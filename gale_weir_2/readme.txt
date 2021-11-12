/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 2
    Date of Submission: 11/11/2021
    Name of this file: readme.txt
*/

to compile: 
    gcc 5ps.c c.c s.c t.c v.c -o 5ps

usage: 
    ./a.out [options]

options: 
    -p <pid>    displays requested process id. 
    -c          displays the command line that created the process
    -s          displays the state of the process
    -t          displays the time the proces took to complete
    -v          displays the virutual memory used by the process

notes: 
    
    This program was tested in a version of ubuntu that included a modern gui. We noticed in testing our getopt wasn't able to consistently get the p id when
        used with this version of ubuntu, but does work with the version of ubuntu we developed within, 20.04.3
    5ps often hits segmentation faults, depending on the PID entered. we suspect this is due to entering the PID of an important process, where the values are protected and inaccessable.
    The time return is very often 00:00:00, though this is likely because the process took less than a second to complete, because computers are fast
    the command-line command that started the process doesn't seem to work most of the time, we do not know how the cmdline file is formatted, and cannot make a parser as such. in testing it did work on the test machine, on PID 1.
