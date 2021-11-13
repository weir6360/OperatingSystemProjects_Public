/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 2
    Date of Submission: 11/11/2021
    Name of this file: child.c
    Description of the program: Child instances grab their pid from args, randomly 
        generate a 10-digit number upon creation via fork(), and start checking for
        the highest prime number. 
*/

#include <inttypes.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include "child.h"
#include "srtfScheduler.h"
#include "timer.h"

const unsigned long long int PRIME_LOWER_BOUND = 1000000000;
const unsigned long long int PRIME_UPPER_BOUND = 9999999999; 

int child_pid = -1;
int child_process_num = -1;

unsigned long long int child_prime = 1000000000; // original random starting number 
unsigned long long int highest_prime = 1;       // new highest prime number

/*
    Function Name: generate_random_number()
    Input to the method: n/a
    Output(Return value): child_prime: the child's randomly-generated prime number. 
    Brief description of the task: Generates a random number, then multiplies it by -1 if it 
        somehow became negative. Returns the prime after generation. 
*/
unsigned long long int generate_random_number() {     
    //create seed for random generation. 
    time_t seed_time;
    srand((unsigned) time(&seed_time));

    // generate the random number
    do { 
        child_prime *= RAND_MAX;
        child_prime += rand(); 
    } while (child_prime < PRIME_UPPER_BOUND && child_prime > 0);
    
    // if the number overexceeds, it remains positive. 
    if (child_prime < 0) { 
        child_prime *= -1; 
    }
    return child_prime % PRIME_UPPER_BOUND;

}

/*
    Function Name: check_prime_num
    Input to the method: n/a
    Output(Return value): is_prime, a variable used to determine if a given number is prime or not. 
    Brief description of the task: Uses a while-loop to determine if the current highest
        number being tested is a prime number
*/
int check_prime_num (long long unsigned int current_prime) { 

    //initialize highest_prime as starting number + 1

    //while the current prime number is in range of the iteration, continue increasing the iterator
    //checks up to the square-root of the current prime
    int is_prime = 1;
    
    unsigned long long int iterator = 2; 

    while (is_prime == 1 && iterator < (current_prime/2)) {
        
        if ((current_prime % iterator) == 0) {
            is_prime = 0; 
        }
        iterator++; 
    }
    return is_prime; 
}

/*
    Function Name: check_child_args
    Input to the method: argc and argv, passed from the main 
    Output(Return value): n/a
    Brief description of the task: sets the child's process id by reading
        given args.
*/
void check_child_args(int argc, char *argv[]) { 
    char c; 
    //while-loop to parse args
    while ((c = getopt(argc, argv, "p:")) != -1) {
        if (c == 'p') {
            child_process_num = atoi(optarg);
        }

    }
}

/*
    Function Name: check_child_signal
    Input to the method: numeric signal, passed as an int
    Output(Return value): n/a
    Brief description of the task: signal handler, 
        sends different instructions to the child based on which
        signal it heard.  
*/
void check_child_signal(int signal) {
    switch (signal) { 
        case SIGTSTP: 
            printf("Process %d: my PID is %d: I am about to be suspended." 
            "Highest prime number I found is %llu.\n", 
            child_process_num, child_pid, highest_prime); 
            pause(); 
            break;
        case SIGCONT: 
            printf("Process %d: my PID is %d: I just got resumed. Highest prime" 
            "number I found is %llu.\n", 
            child_process_num, child_pid, highest_prime); 
            break; 
        case SIGTERM: 
            printf("Process %d: my PID is %d: I completed."
            " my task and will exit. Highest prime number I found is %llu.\n", 
            child_process_num, child_pid, highest_prime); 
            exit(EXIT_SUCCESS);
            break; 

        default: 
            break;
    } 
}

/*
    Function Name: main
    Input to the method: argc and argv, passed from the parent process
    Output(Return value): n/a
    Brief description of the task: handles initialization of child variables
        and begins the process of setting up the child's timer and signal handling, 
        ending with a while loop to check the current prime number on clock tics. 
*/
int main (int argc, char **argv) {
    //grab the needed elements from the arguments
    check_child_args(argc, argv);
    child_pid = getpid(); 
    child_prime = generate_random_number();
    printf("Process %d: my PID is %d: I just got started. \nI am starting with the number "
    "%llu to find the next prime number.\n",
    child_process_num, child_pid, child_prime);

    //set and create sigaction object to interact with srtfScheduler.c
    struct sigaction sa; 
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = check_child_signal;
    sigaction (SIGCONT, &sa, NULL);
    sigaction (SIGTERM, &sa, NULL); 
    sigaction (SIGTSTP, &sa, NULL); 

    highest_prime = child_prime; 
    long long unsigned int current_prime = child_prime + 1; 
    while (1) {
        if (check_prime_num(current_prime) == 1) {
            highest_prime = current_prime; 
        }
        current_prime++;   
    }
 
}