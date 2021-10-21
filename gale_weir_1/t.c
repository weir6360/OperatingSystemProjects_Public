/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: t.c
    Description of the program: Handles the -t command for the 5ps, returning the formatted
        time consumed by the process
*/

#include "t.h"

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
Input to the method: pid: the provided pid
Output(Return value): a formatted time string (hours::mins::sec)
Brief description of the task: calls read_stime() and read_utime() to get the time passed, 
    and calls format_timestr(clock_ticks) to produce the desired formatted time string
*/

const char* t_return(int pid) { 
    


    int stime;
    stime = read_stime(pid);
    int utime;
    utime = read_utime(pid);
    float ctime;
    printf("\n%d \n%d\n", stime, utime);
    ctime = (float) ((utime + stime) / sysconf(_SC_CLK_TCK));
    
    char ftime[100];
    sprintf(ftime, "%f", ctime);
    char *ftimeptr = ftime;
    return ftimeptr;
}

/*
Function Name: read_utime
Input to the method: pid: 
Output(Return value): an integer representing the number of click ticks needed to run this program
Brief description of the task: the function makes a system call to the stat file, reading and returning
    the value of the utime field. 
*/

int read_utime(int pid) { 
    char pidstr[100];
    sprintf(pidstr, "%d", pid);
    char filestring1[100] = "/proc/"; 
    strcat(filestring1, pidstr);
    char filestring2[100] = "/stat";
    strcat(filestring1, filestring2);
    FILE* statFileu = fopen(filestring1, "r");
    if(statFileu != NULL){
        //for loop 13 times, to get to value 14
        int i;
        for(i = 0; i<=13; i++){
            fscanf(statFileu, "%*s");
        }
        int utime;
        fscanf(statFileu, "%d", &utime);
        fclose(statFileu);
        return utime;

    }
    fclose(statFileu);
    return 0;
    
}

/*
Function Name: read_stime
Input to the method: n/a
Output(Return value): an integer representing the number of click ticks in the system time
Brief description of the task: the function makes a system call to the stat file, reading and returning
    the value of the stime field. 
*/

int read_stime(int pid) { 
    char pidstr[100];
    sprintf(pidstr, "%d", pid);
    char filestring1[100] = "/proc/"; 
    strcat(filestring1, pidstr);
    char filestring2[100] = "/stat";
    strcat(filestring1, filestring2);
    FILE* statFiles = fopen(filestring1, "r");
    if(statFiles != NULL){
        //for loop 14 times, to get to value 15
        int i;
        for(i = 0; i<=14; i++){
            fscanf(statFiles, "%*s");
        }
        int stime;
        fscanf(statFiles, "%d", &stime);
        fclose(statFiles);
        return stime;

    }

    fclose(statFiles);
    return 0;
    

}