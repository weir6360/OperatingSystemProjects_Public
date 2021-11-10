/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission: 
    Name of this file: child.c
    Description of the program: Child instances grab their pid from args, randomly 
        generate a 10-digit number upon creation via fork(), and start checking for
        the highest prime number. 
*/

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "child.h"
#include "srtfScheduler.h"
#include "timer.h"

int child_pid = -1;
int child_process_num = -1;

unsigned long long int child_prime = 1000000000; 
unsigned long long int highest_prime = 1000000000; 

unsigned long long int generate_random_number() { 
    unsigned long long int lower_bound = 1000000000;
    unsigned long long int upper_bound = 9999999999;
    
    // generate the random number
    do { 
        child_prime *= RAND_MAX;
        child_prime += rand(); 
    } while (child_prime < upper_bound && child_prime > 0);
    
    // if the number overexceeds, it remains positive. 
    if (child_prime < 0) { 
        child_prime *= -1; 
    }
    // printf("%llu", child_prime);
    return child_prime % 9999999999;

}

int check_prime_num (unsigned long long int current_prime) { 
    unsigned long long int range = sqrt(current_prime); 
    unsigned long long int iterator = 3; 
    int is_prime = 1; 
    while (is_prime == 1 && iterator <= range) {
        if ((current_prime % iterator) == 0) {
            is_prime = 0; 
        }
        iterator++; 
    }
    return is_prime; 
}

void check_child_args(int argc, char *argv[]) { 
    int c; 
    while ((c = getopt(argc, argv, "p:")) != -1) {
        if (c == "p") {
            child_process_num = atoi(optarg);
        }

    }
}

void check_child_signal(int signal) {
    switch (signal) { 
        case SIGCONT: 
            printf("Process %d: my PID is %d: I just got resumed. Highest prime" 
            "number I found is %llu.\n", 
            child_process_num, child_pid, highest_prime); 
            break; 
        case SIGTERM: 
            printf("Process %d: my PID is %d: I completed. "
            " my task and will exit. Highest prime numbe I found is %llu.\n", 
            child_process_num, child_pid, highest_prime); 
            exit(EXIT_SUCCESS);
            break; 
        case SIGTSTP: 
            printf("Process %d: my PID is %d: I am about to be suspended." 
            "Highest prime number I found is %llu.\n", 
            child_process_num, child_pid, highest_prime); 
            pause(); 
            break;
        default: 
            break;
    } 
}

int main (int argc, char **argv) {
    time_t seed_time;
    srand((unsigned) time(&seed_time));
    unsigned long long int holder = generate_random_number();
    child_pid = getpid(); 
    child_prime = holder;
    printf("Process %d: my PID is %d: I just got started. \nI am starting with the number"
    "%llu to find the next prime number.\n",
    child_process_num, child_pid, child_prime);
}