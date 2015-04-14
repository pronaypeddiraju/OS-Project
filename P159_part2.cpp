/*Write a multithreaded sorting program that works as follows: A list of integers
is divided into two smaller lists of equal size. Two separate threads (which we
will term sorting threads) sort each sublist using a sorting algorithm of your
choice. The two sublists are then merged by a third thread—a merging thread
—which merges the two sublists into a single sorted list.
Because global data are shared cross all threads, perhaps the easiest way
to set up the data is to create a global array. Each sorting thread will work on
one half of this array. A second global array of the same size as the unsorted
integer array will also be established. The merging thread will then merge
the two sublists into this second array. Graphically, this program is structured
according to Figure 4.20.
This programming project will require passing parameters to each of the
sorting threads. In particular, it will be necessary to identify the starting index
from which each thread is to begin sorting. Refer to the instructions in Project
1 for details on passing parameters to a thread.
The parent thread will output the sorted array once all sorting threads have
exited.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using namespace std;

#define N 2                                                     //storing number of threads in N

int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

typedef struct Arr
{
    int low;
    int high;
} Array;

void merge(int low, int high)                               //sorting algorithm and merging function
{
        int mid = (low+high)/2;
        int left = low;
        int right = mid+1;

        int b[high-low+1];
        int i, temp = 0;

        while(left <= mid && right <= high)
        {
                if (a[left] > a[right])
                        b[temp++] = a[right++];
                else
                        b[temp++] = a[right++];
        }

        while(left <= mid)
        b[temp++] = a[left++];

        while(right <= high)
        b[temp++] = a[left++];

        for (i = 0; i < (high-low+1) ; i++)
        a[low+i] = b[i];
}

void * mergesort(void *a)                                   //function that creates threads and calls the merge function which sorts and merges the sub sets
{
        Array *pa = (Array *)a;
        int mid = (pa->low + pa->high)/2;

        Array aIndex[N];
        pthread_t thread[N];

        aIndex[0].low = pa->low;
        aIndex[0].high = mid;

        aIndex[1].low = mid+1;
        aIndex[1].high = pa->high;

        if (pa->low >= pa->high) return 0;

        int i;

        for(i = 0; i < N; i++)
        pthread_create(&thread[i], NULL, mergesort, &aIndex[i]);    //creating a new thread with routine mergesort and only parameter as aIndex[i]

        for(i = 0; i < N; i++)
        pthread_join(thread[i], NULL);                              //ending the thread thread[i] with return status set to NULL

        merge(pa->low, pa->high);
        return 0;
}

int main()
{
        Array ai;                                                   //creating element ai of struct arr type
        ai.low = 0;
        ai.high = sizeof(a)/sizeof(a[0])-1;                         //assigning last location of the array to ai.high
        pthread_t thread;                                           //making new thread with thread label

        pthread_create(&thread, NULL, mergesort, &ai);              //creating thread with routine mergesort and only parameter ai
        pthread_join(thread, NULL);                                 //ending the thread 'thread' and returni

        int i;
        for (i = 0; i < 10; i++)
        cout << "\t" << a[i];
        cout << endl;

        return 0;
}
