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
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

sem_t one_die;
sem_t two_dice;
sem_t four_dice;
sem_t five_dice;
sem_t one_less;

unsigned int line_front = 0;
unsigned int one_less_queue = 1;


int groups_running = 8;
int queue[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int return_queue[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

const char games[9][100] = {"I should be front desk", "Backgammon", "Backgammon", "Risk", "Risk", "Monopoly", "Monopoly", "Pictionary", "Pictionary"};
const int die_amount[9] = {0, 4, 4, 5, 5, 2, 2, 1, 1};

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
        int dice = 8;
        printf("I am the front desk, starting with 8 dice.\n");
        while(groups_running != 0){
            int j;
            for(j = 0; j < 9; j++){
                if(return_queue[j] != 0){
                    dice = dice + return_queue[j];
                    return_queue[j] = 0;
                }
            }
            if(dice > 0){
                int k;
                for(k = 0; k < 9; k++){
                    if(queue[k] != 0){
                        if(queue[k] <= dice){
                            printf("Front Desk: Before loans, I have %d dice\n", dice);
                            printf("Front Desk: Loaning out %d dice.\n", queue[k]);
                            switch(queue[k]){
                                case 1:
                                    sem_post(&one_die);
                                    dice = dice - 1;
                                    break;
                                case 2:
                                    sem_post(&two_dice);
                                    dice = dice - 2;
                                    break;
                                case 4:
                                    sem_post(&four_dice);
                                    dice = dice - 4;
                                    break;
                                case 5:
                                    sem_post(&five_dice);
                                    dice = dice - 5;
                                    break;
                            }
                            queue[k] = 0;
                        }
                    }
                }
            }
        }
    }
    else {
        //run player group(i)
        int dice_num = die_amount[i];
        char *current_game = games[i];
        int c;
        time_t seed_time;
        srand((unsigned) time(&seed_time) + i);
        for(c = 0; c < 5; c++){
            int random = (rand() % 5);
            sleep(random);

            printf("Group %d: I want to play %s, and I need %d dice for that. This is game %d\n", i, current_game, dice_num, c+1);
            switch(dice_num){
                case 1 :
                    queue[i] = 1;
                    sem_wait(&one_die);
                    printf("Group %d: Starting my game of %s\n", i, current_game);
                    sleep(random + 5);
                    printf("Group %d: We have finished our game of %s and are returning %d dice\n", i, current_game, dice_num);
                    return_queue[i] = 1;
                    break;
                case 2 :
                    queue[i] = 2;
                    sem_wait(&two_dice);
                    printf("Group %d: Starting my game of %s\n", i, current_game);
                    sleep(random + 5);
                    printf("Group %d: We have finished our game of %s and are returning %d dice\n", i, current_game, dice_num);
                    return_queue[i] = 2;
                    break;
                case 4 :
                    queue[i] = 4;
                    sem_wait(&four_dice);
                    printf("Group %d: Starting my game of %s\n", i, current_game);
                    sleep(random + 5);
                    printf("Group %d: We have finished our game of %s and are returning %d dice\n", i, current_game, dice_num);
                    return_queue[i] = 4;
                    break;
                case 5 :
                    queue[i] = 5;
                    sem_wait(&five_dice);
                    printf("Group %d: Starting my game of %s\n", i, current_game);
                    sleep(random + 5);
                    printf("Group %d: We have finished our game of %s and are returning %d dice\n", i, current_game, dice_num);
                    return_queue[i] = 5;
            }

        }
        sem_wait(&one_less);
        groups_running--;
        printf("Group %d: We are done playing and are leaving the parlor.\n\n", i);
        sem_post(&one_less);
    }

    pthread_exit(0); // this code returns to the corresponding pthread_join issued in main()
} 

int main()
{
    
    sem_init(&one_die, 1, line_front);
    sem_init(&two_dice, 1, line_front);
    sem_init(&four_dice, 1, line_front);
    sem_init(&five_dice, 1, line_front);
    sem_init(&one_less, 1, one_less_queue);

    pthread_t thread_id[9];
    // The following code creates 5 threads.
    for (int i =0; i <9; i++)
    pthread_create(&thread_id [i], NULL, thread_task, (void *) i);
    // The following code makes sure the main program waits until all threads have finished execution
    for (int i =0; i <9; i++)
    pthread_join(thread_id[i], NULL);
}
