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
#include <string.h>

/*
Function Name: t_return
Input to the method: n/a
Output(Return value): a formatted time string (hours::mins::sec)
Brief description of the task: calls read_stime() and read_utime() to get the time passed, 
    and calls format_timestr(clock_ticks) to produce the desired formatted time string
*/

const char* t_return(char* pid) { 
//call format_timestr
//return formatted timestring
char* stime = read_stime(pid);
char* utime = read_utime(pid);
char* ctime = strcat(stime, utime); // might need to do some funky stuff with string parsing
//do funky math to get nice formatting
char* ftime = ctime;
return ftime;

}

/*
Function Name: read_utime
Input to the method: n/a
Output(Return value): an integer representing the number of click ticks needed to run this program
Brief description of the task: the function makes a system call to the stat file, reading and returning
    the value of the utime field. 
*/

int read_utime(char* pid) { 
//open stat file
//read utime field
//return utime field

char* filestring1 = strcat("/proc/", pid);
char* filestring2 = strcat(filestring1, "/stat");
FILE* statFileu = fopen(filestring2, "r");
//navigate file to value 14
char* utime = "1000";//value 14
return utime;
}

/*
Function Name: read_stime
Input to the method: n/a
Output(Return value): an integer representing the number of click ticks in the system time
Brief description of the task: the function makes a system call to the stat file, reading and returning
    the value of the stime field. 
*/

int read_stime(char* pid) { 
//open stat file
//read utime field
//return utime field

char* filestrings1 = strcat("/proc/", pid);
char* filestrings2 = strcat(filestrings1, "/stat");
FILE* statFiles = fopen(filestrings2, "r");
char* stime = "2000";//value 15
return stime;

}


