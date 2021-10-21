/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission: 10/21/2021
    Name of this file: readme.txt
*/

to compile: 
    gcc 5ps.c c.c s.c t.c v.c -o 5ps

usage: 
    ./5ps [options]

options: 
    -p <pid>    displays requested process id. 
    -c          displays the command line that created the process
    -s          displays the state of the process
    -t          displays the time the proces took to complete
    -v          displays the virutual memory used by the process

notes: 
    
    the -t command has, from testing, often returned only 7 seconds for different pids
    the -t command can occasionally return segmentation faults
