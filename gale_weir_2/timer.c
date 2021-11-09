/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission: 
    Name of this file: child.c
    Description of the program: Child instances  
*/

void timer_handler(int timer_signal)

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
        
    }



}

