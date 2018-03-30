# OS-Project
OS project on pthreads

This project was part of my Operating Systems course work assignment. 
It was required to design a PID manager that allocated a unique process identifier to each process. 
By writing a program that created a number of threads that requested and released process identifiers, I was to ensure that the data structure used to represent the availability of process identifiers is safe from race conditions. 
I have implemented the use of Pthreads mutex locks

The second part of the project was as follows:

Write a multithreaded sorting program that works as follows: 
A list of integers is divided into two smaller lists of equal size. 
Two separate threads (which we will term sorting threads) sort each sublist using a sorting algorithm of your choice. 
The two sublists are then merged by a third thread—a merging thread —which merges the two sublists into a single sorted list. 
Because global data are shared cross all threads, perhaps the easiest way to set up the data is to create a global array. 
Each sorting thread will work on one half of this array. 
A second global array of the same size as the unsorted integer array will also be established. 
The merging thread will then merge the two sublists into this second array. 

This programming project will require passing parameters to each of the sorting threads. 
In particular, it will be necessary to identify the starting index from which each thread is to begin sorting. 
The parent thread will output the sorted array once all sorting threads have exited.

This software is licensed under the DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE http://www.wtfpl.net/

        DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                Version 2, December 2004

Copyright (C) 2004 Sam Hocevar sam@hocevar.net

Everyone is permitted to copy and distribute verbatim or modified copies of this license document, and changing it is allowed as long as the name is changed.

        DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE

TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

    You just DO WHAT THE FUCK YOU WANT TO.
