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

int latest_time;

/*
Function Name: timer_handler
Input to the method: timer_signal: numeric value of the received signal
Output(Return value): n/a
Brief description of the task: Increment the time, and call on_clock_tick
*/
void timer_handler(int timer_signal) { 
    latest_time++;

    //placeholder: execute actual scheduler
    on_clock_tick();
}

/*
Function Name: start_timer
Input to the method: n/a
Output(Return value): n/a
Brief description of the task: sets up the sigaction struct, establishes 
    timer intervals and values, and starts the timer and while-loop for ticking
*/
void start_timer() { 
    //creation of the sigaction structure
    struct sigaction sa; 
    memset (&sa, 0, sizeof(sa)); 
    sa.sa_handler = &timer_handler; 
    sigaction(SIGALRM, &sa, NULL);    

    //set the timer's initial value and interval value in secs and milisecs. 
    struct itimerval timer; 
    timer.it_value.tv_sec = 1; 
    timer.it_value.tv_usec = 0; 
    timer.it_interval.tv_sec = 1; 
    timer.it_interval.tv_usec = 0; 
    
    //set the timer, check for errors and terminate if errored out. 
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        printf("error caused by setitimer.\n");
        exit(EXIT_FAILURE);
    }

    //
    while (1) {
        //while-loop
    }



}

