Author: Jonathan Trinh (Johnny)
Date: 2/27/17

Lab 5: Hashing in IO and File Systems
===============================

Purpose of Lab
---------------

The idea of this assignment is to look further into hashing as a means of solving IO/File Systems related
problems specifically writing code for a device that behaves as an append-only (never to be modified)
file. Three programs + a pre-lab are written.

Pre-lab:

We designed a pre-lab to to gain further insight into how a map data structure works and how to take
advantage of it by storing keys and values. This was done with a Pair class that stored a key and value,
and the overarching data structure was an array that stored these "pairs". The input was a series of
strings of standard in (the key), and the output was the string's hash (if it is found in the map
data structure).

Prog1:

The idea of Part 1 was to output a string in a specific order:

  (stringLength)(stringItself)(hash1(stringItself))(hash2(stringItself+previousHash))

The tricky part is to keep track of the previous hash value, but this can be done with memcpy().

Prog2:

Part 2 takes the result of Part1 and performs an analysis on it. For each string, we read character by
character (that way we can handle changes in string length) and grab the string itself, hash it, and compare
to hash1. However, because hash1 is a 128 character hexadecimal, we must first use sprintf to convert
the hash of the string to hex. Then we can continue to read character by character and compare the results.
If they are the same, success. If not, then that string fails. We simply skip hash2 by fseeking 128 characters

Prog3:

The purpose of part 3 is to detect ommissions in the result of part 1, so we will also perform an analysis.
Like in Part 2, we read character by character and grab the string itself and append it to the previous
hash2. We hash this result and continue doing this for as many strings there are. At the end, we compare
this hash to hash2 of the last string. Again, we have to use sprintf to convert the hash of the appended
string to hex before comparing.

Questions:

1. We can take advantage of the map data structure that we created in the pre-lab, and sort everything by
key and hash. That is, we will primarily sort by key/string first. Then within that, we sort by hash.
That way, we only have to look in the adjacent spaces to efficiently find duplicates.

2. Because of the way our key-look up map data structure is "structured", we can take advantage of using
a hashmap. This means that the fact that there are many identical strings leads to many collisions. Since
these strings will map to the same location, and we just have to use linear probing to identify the next
location.
