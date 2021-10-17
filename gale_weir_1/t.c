/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: t.c
    Description of the program: Handles the -t command for the 5ps
*/

/*
This information is found in the stat file in process's directory, looking at the "utime" field.
Add to this to the system time, “stime” field . This is the total time consumed by the
process. This time is represented in clock ticks. You must divide my number of clock
ticks per second (system constant) to obtain the number of seconds. It should then be
displayed in hours:min:seconds format. If this option is not present, do not display this
information.
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

const char* t_return(/*PID?*/) { 
//call read_ctps
//call format_timestr
//return formatted timestring
ctps = read_ctps();
timeString = format_timestr(ctps);
return timeString;

}

/*
Function Name: read_utime
Input to the method: n/a
Output(Return value): an integer representing the number of click ticks needed to run this program
Brief description of the task: the function makes a system call to the stat file, reading and returning
    the value of the utime field. 
*/

int read_utime() { 
//open stat file
//read utime field
//return utime field


//statFileu = fopen("/proc/<pid>/stat", "r")
//14 utime
//return utime
}

/*
Function Name: read_stime
Input to the method: n/a
Output(Return value): an integer representing the number of click ticks in the system time
Brief description of the task: the function makes a system call to the stat file, reading and returning
    the value of the stime field. 
*/

int read_stime() { 
//open stat file
//read utime field
//return utime field


//statFiles = fopen("/proc/<pid>/stat", "r")
//15 stime
//return stime

}


/*
Function Name: read_ctps
Input to the method: n/a
Output(Return value): an integer representing the system-constant number of clock ticks per second 
Brief description of the task: the function makes a system call for the number of clock ticks per second
*/

int read_ctps() { 
//find and return clock ticks value for system, figure out what file/call for this

//it's just 1 million? 
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
//clock ticks as input
//call read_stime
//call read_utime (not necessarially in that order)
//add them together accordingly
//format into nice looking string


}


