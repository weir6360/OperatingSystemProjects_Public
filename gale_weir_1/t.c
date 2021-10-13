/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: c.c
    Description of the program: Handles the -t command for the 5ps
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

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
Function Name:
Input to the method: < This should be in
English and not list of variables from the
function header>
Output(Return value): < This should be in
English and not the return type from the
function header>
Brief description of the task:
 */

const char* format_timestr(clock_ticks){ 
    
}


