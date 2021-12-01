/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: x
    Date of Submission: xx/xx/xx
    Name of this file: ___
    Description of the program: ___________
        ___________________________________
*/

#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

extern int number_of_dice; 
sem_t dice_pool[8]; 
semt_t players_waiting_mutex; 
int players_waiting; 

void give_dice(); 
void return_dice(); 