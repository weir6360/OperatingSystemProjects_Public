/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 2
    Date of Submission: 11/11/2021
    Name of this file: readme.txt
*/

to compile: 
    gcc child.c -o child
    gcc srtfScheduler.c timer.c

usage: 
    ./a.out input.txt

notes: 
    This program was tested in a version of ubuntu that included a modern gui.
    Random number generation works properly, but as of writing was running into overflow issues with testing the prime number
    We've run into inconsistencies with children being made in our create_child; sometimes most if not all children are made, other times none of them are. 
    We haven't seen a SIGCONT command go through properly, but SIGTSTP and SIGTERM were validated. 