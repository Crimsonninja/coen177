Author: Jonathan Trinh (Johnny)
Date: 2/27/17

Lab 4: Page Replacement
===============================

Purpose of Lab
---------------

The idea of this assignment is to look further into different page replacement algorithms, and how
each has its benefits and disadvantages when grabbing a specific page from virtual memory and
loading it into physical memory.

Implementation of FIFO, LRU, LFU, and Random
--------------------------------------------

1. FIFO was a straightforward algorithm to implement. I kept track of a pointer variable that
increments every time a page replacement happens. Whatever the pointer variable points to is the
page that will be replaced the next time a page fault occurs.

2. LRU required two helper functions: one that searches through the array for a specific value and
returns its index and another function that searches for the minimum given an array and lo and hi
indices and returns its index. The basic idea is to search for the page number coming in. If the
given page number is not found, either: the array is not yet filled in which cased we simply add
the page number OR the array is completely populated and we have to perform a page replacement. This
is where minSearch comes. Since we keep track of a globalCounter in a second array (which is
incremented everytime), we just have to search for the minimum index in the globalCounter array
and update the value at that index in BOTH the first and second array.

3. LFU has the same implementation as LRU but instead, we keep track of frequency in the second
array rather than the globalCounter. We search for the minimum frequency and update the values
in the buffer and frequency array at that location. If there are multiple values that have the same
minimum frequency, the algorithm will replace the first one.

4. Random only requires the first of the two helper functions described in LRU. If we have found
the given page number, then either: the array is not yet populated in which case we add to the end
of the array OR we need to perform the page replacement and select an index at random to do the
replacement


Sample Hit Rates Analysis
-----------------

When observing Pure Scan, all the algorithms had a 100% page fault rate (500/500). This is due to
the way Pure Scan generates its numbers. Since all the buffers read in numbers 1-500 in sequential
order, all the elements that it reads in is something it hasn't seen before. In other words, all the
numbers are unique.

When observing Repeated Scan, FIFO and LRU all have a 100% page fault rate. This is to be expected.
Because the buffer size never exceeds 100, FIFO and LRU will see pages that are unique (each
element read in has not been seen before). If the buffer size exceeds 500, then there is a possibility
that there may be less than 5000 page faults for these two algorithms. Because the way Random is
implemented (randomly picks a page to be removed), it's possible for it to pick the same number as
the one that is coming in. Thus, this does not result in a page fault. LFU is a different algorithm.
As, the buffer size goes up, the page fault rate decreases. LFU keeps track of a frequency

Random Scan behaves as expected for all algorithms. Because Random Scan is so sporadic, values
are all over the place, but generally, it can be agreed that as the buffer size goes up, the number
of page faults goes down.

Improvements on the Algorithms
------------------------------

Given a certain buffer size, one could tailor certain algorithm to a certain buffer size. For small sizes,
FIFO would work. It's not an expensive algorithm because we won't have to access the data structure
everytime a page request happens. For larger data sets, it may be preferable to use LFU since its
page fault size decreases in a majority of scenarios as the buffer size goes up. (as demonstrated
in Random Scan and Repeated Scan cases)
