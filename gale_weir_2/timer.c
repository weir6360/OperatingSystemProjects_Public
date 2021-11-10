/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 2
    Date of Submission: 
    Name of this file: timer.c
    Description of the program: handles the ticking iteration of the timer for 
        use by srtfScheduler.c    
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include "child.h"
#include "srtfScheduler.h"
#include "timer.h"

/*
Function Name: 
Input to the method:
Output(Return value): 
Brief description of the task: 
*/
void timer_handler(int timer_signal) { 
    latest_time++;

    //placeholder: execute actual scheduler
    srtf_scheduler(latest_time);
}

/*
Function Name:
Input to the method: pid: the process id for the current process
Output(Return value): the program associated with the pid's state, either 
Brief description of the task: s_return parses the stat file for the program's pid state, passes it to 
    program_state, checks to make sure specified file exists, and if so returns the program_state
*/
void start_timer() { 
    struct sigaction sa; 
    memset (&sa, 0, sizeof(sa)); 
    sa.sa_handler = &timer_handler; 
    sigaction(SIGALRM, &sa, NULL);    

    struct itimerval timer; 
    timer.it_value.tv_sec = 1; 
    timer.it_vaule.tv_usec = 0; 
    timer.it_interval.tv_sec = 1; 
    timer.it_interval.tv_usec = 0; 
    
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        printf("%s: error caused by setitimer.\n", prog_name);
        exit(EXIT_FAILURE)
    }

    while (1) {
        //while-loop
    }



}

