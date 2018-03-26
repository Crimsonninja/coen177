Author/Modifier: Jonathan Trinh (Johnny)
Date: 2/6/17


Lab 2: Rewriting the Scheduling Algorithm of Minix
====================================================

Purpose of this lab
--------------------

This lab is designed to further familiarize ourselves with different shell commands as well as learn
how the minix 3 operating system works. The idea was to change the current Minix scheduling
algorithm and add the slight possibility of it choosing a different process in the pqueue and as a
result, make the operating system slower.

Part 1: Find the Copyright message and modify it
------------------------------------------------

We used a system call called grep which looks for the specific instance of whatever is passed into
it. It typically starts at the root directly (but you can also change the path that it starts at)
and looks through all the folders underneath it for that specific instance.


Part 2: Modify the Minix Scheduling Algorithm
---------------------------------------------

1. The original scheduling algorithm used in Minix is a multi-priority round robin. It always picks
the process at the head of the highest priority queue. The code specifies that it will go through
all the queues and perform rand_proc() to pick a job in that priority queue.

2. I modified the scheduler my simply influencing how it chose the queues. Queues 0 through 6 are
system queues so we will not touch that lest we destroy the minix image. Thus, I check if the queue
number is greater than or equal to seven. If so, then I implement some "randomness" within those
queues. This is done by making q = rand()%(NR_SCHED_QUEUES-7)+7. Essentially, we want a random
number between 7 and 15 inclusive. The rand() function generates a random number between 0 and
32767. Then we mod that result with NR_SCHED_QUEUES-7 to ensure that the max number is limited to 9
(we have 9 queues to play with between 7 and 15 inclusive). Then finally we add 7 so that our range
goes from 7 to 15 rather than 0 to 8.

3. I tested this new scheduler by compiling and rebooting the minix image. It took about a minute
for the system to reboot which is much slower because it is using a less efficient algorithm.
Instead of going through each queue and doing rand_proc on each, it now chooses a queue at random (
in the 7 through 15 range).
