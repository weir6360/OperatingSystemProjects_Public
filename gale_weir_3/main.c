/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: x
    Date of Submission: xx/xx/xx
    Name of this file: ___
    Description of the program: ___________
        ___________________________________
*/

int main()
{
    pthread_t thread_id[9];
    // The following code creates 5 threads.
    for (int i =0; i <9; i++)
    pthread_create(&thread_id [i], NULL, thread_task, (void *) i);
    // The following code makes sure the main program waits until all threads have finished execution
    for (int i =0; i <9; i++)
    pthread_join(thread_id[i], NULL);
}
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