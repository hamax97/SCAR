NOTES ABOUT SECTIONS
====================

* It is not iterable. You have to know beforehand how many sections you will have.
* Each section must be independent of each other.
* Only one thread executes it. This work is not shared between the threads.
* If there are more threads than sections, some threads will wait idle.
* If there are more sections than threads, some threads will execute more than one section.
