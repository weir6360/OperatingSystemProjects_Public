/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: c.c
    Description of the program: Handles the -t command for the 5ps, returning the formatted
        time consumed by the process
*/

#include "t.h"
#include "statmParser.h"

#include <ctype.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <zconf.h>

/*
Function Name: t_return
Input to the method: n/a
Output(Return value): a formatted time string (hours::mins::sec)
Brief description of the task: calls read_stime() and read_utime() to get the time passed, 
    and calls format_timestr(clock_ticks) to produce the desired formatted time string
*/

const char* t_return() { 

}

/*
Function Name: read_utime
Input to the method: n/a
Output(Return value): an integer representing the number of click ticks needed to run this program
Brief description of the task: the function makes a system call to the stat file, reading and returning
    the value of the utime field. 
*/

int read_utime() { 

}

/*
Function Name: read_stime
Input to the method: n/a
Output(Return value): an integer representing the number of click ticks in the system time
Brief description of the task: the function makes a system call to the stat file, reading and returning
    the value of the stime field. 
*/

int read_stime() { 

}


/*
Function Name: read_ctps
Input to the method: n/a
Output(Return value): an integer representing the system-constant number of clock ticks per second 
Brief description of the task: the function makes a system call for the number of clock ticks per second
*/

int read_ctps() { 

}

/*
Function Name: format_timestr
Input to the method: the final number of active clock ticks
Output(Return value): a formatted timestring
Brief description of the task: format_timestr takes clock_ticks, and uses it to calculate
    the number of hours, then minutes, then seconds the program took. Once complete, format_timestr
    then arranges them in a string, and returns that value. 
*/

const char* format_timestr(clock_ticks){ 
    
}


