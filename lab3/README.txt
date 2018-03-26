Author: Jonathan Trinh (Johnny)
Date: 2/13/17

Lab 3: File System Performance
===============================

Purpose of Lab
---------------

The idea of of this assignment is to investigate how a computer's file system works including
observe how input and output affects speed. To do this, we create 3 files: 1 GB, 5GB, and 10 GB
using /dev/random with the following command:

head -c nG</dev/urandom> /local/weka/filename.bat     //"n" being replaced by 1, 5, or 10

We then create two programs: one that will read the files in sequentially and another one that reads
them at random (as a result, we'd need to fread same as before but use a random offset). By doing
this, we can answer the question: "What is the impact of user workload on file system performance?"


Results
------------

When testing SEQUENTIAL:

1GB:
  real    0m0.636s
  user    0m0.133s
  sys     0m0.439s

5GB:
  real    0m2.880s
  user    0m0.815s
  sys     0m2.065s

10GB:
  real    0m5.544s
  user    0m1.567s
  sys     0m3.977s

When testing RANDOM:

1GB:
  real    0m3.992s
  user    0m1.012s
  sys     0m2.910s

5GB:
  real    0m18.913s
  user    0m4.951s
  sys     0m13.961s

10GB:
  real    0m37.766s
  user    0m9.945s
  sys     0m27.818s

Observations
------------

In general, sequential performs faster than random (as expected). This is because instead of reading
the file in order in 1MB increments, random must calculate a new offset each time and jumps around
the file reading 1 MB at the spot that it lands at. To put this into perspective, we must consider
the hardware. Sequential simply moves the pointer by however much it is incremented by. Thus, the
needle moves while it is reading. But since random generates a random offset, the needle not only
must move to the beginning of the file, but also must move to a new position everytime, and it is
this moving that causes a hiccup in performance.

We can also note that when performing the reading, the system spends less time in user than it does
in system. This is due to the fact that in the C code, we simply make a system call (i.e. fread),
and this is essentially a request for the OS to read the contents of that file. The reading of
contents actually happens in supervisor mode rather than user mode, and we can see this from the
results above.


Answering the question: "What is the impact of user workload on file system performance?"
-----------------------------------------------------------------------------------------

The file system is stored on the disk. Our lab required that we do a lot of "disk access" (the files
were stored in /local/weka). Because we had to make many system calls to access the files and read
them in, the disk was rotating and the needle was moving a lot. In general, IO is slow. Especially
in the 10GB case, our physical memory/RAM space is only so much. Thus, there was a lot of swapping
that happened between the virtual and disk space. Since the reading (in my case) only happened
1 MB at a time, it is possible for an absurdly large amount of swaps to happen which makes it slow.
To summarize, greater user workload decreases file system performance.

