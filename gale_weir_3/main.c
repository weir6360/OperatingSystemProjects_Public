/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: x
    Date of Submission: xx/xx/xx
    Name of this file: ___
    Description of the program: ___________
        ___________________________________
*/

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t front_line;
sem_t dice;


//Front desk knows how many dice are left and loans them out itself


//Player group 
/*
sem_wait(front_line);
int j;
for(j = 0; j < needed_dice; j++)
{
    sem_wait(dice);
}
sem_post(front_line);
sleep(random 0-10 seconds);
for(j = 0; j < needed_dice; j++)
{
    sem_post(dice);
}

*/

void thread_task(int i) {
    //Code for the thread task goes here
    if(i == 0) {
        //run front desk
        printf("I am the front desk\n");
    }
    else {
        //run player group(i)
        printf("I am a player group, number %d\n", i);
    }

    pthread_exit(0); // this code returns to the corresponding pthread_join issued in main()
} 

int main()
{
    unsigned int dice_num = 8;
    unsigned int line_front = 1;
    int sem_init(dice, TRUE, dice_num);
    int sem_init(dice, TRUE, line_front);
    
    pthread_t thread_id[9];
    // The following code creates 5 threads.
    for (int i =0; i <9; i++)
    pthread_create(&thread_id [i], NULL, thread_task, (void *) i);
    // The following code makes sure the main program waits until all threads have finished execution
    for (int i =0; i <9; i++)
    pthread_join(thread_id[i], NULL);
}
