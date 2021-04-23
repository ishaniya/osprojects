# Some basic OS codes written in C++...


Questions

1. Write a program to sync 5 readers and 3 
writers such that multiple readers should 
be allowed to read at same time but reader 
and writer cannot simultaneously enter 
into the critical section. Program should 
be implemented with the help of thread 
and use semaphore for synchronization.

2. Write a program to create two threads and 
both the threads are sharing a common 
variable whose value is initialized by 2. 
First thread should increment the shared 
value by 1 and the other thread should 
decrement by 1. In order to avoid context 
switching and to attain consistency use 
Mutex Lock. Create a scenario such that 
after every execution, the value of the 
shared variable should be consistent. 

3.Write a program to create three threads and 
three binary semaphore S1, S2 and S3 that are 
initialized with value 1. Threads should 
acquire semaphore in such a manner that 
deadlock is achieved. 

4.Write a program to implement producer 
consumer problem such that Maximum 
number of items produced by a producer are 
five. Producer should not produce any item if 
the buffer is full and should say “ BUFFER IS 
ALREADY FULL” and the consumer should 
not consume if the buffer is empty. Problem 
should be implemented with the help of 
thread, semaphore and mutex lock.
