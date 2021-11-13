/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 2
    Date of Submission: 11/12/2021
    Name of this file: srtfScheduler.c
    Description of the program: Handles file parsing and scheduler algorithm
        Creates child forks when needed, and sends signals to children. 
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

int **processes;
int lines;
int current_time;
int running_process = -1;
int ended_processes;
int *children;

/*
Function Name: count_lines
Input to the method: file_name, the name of the current file
Output(Return value): count, the number of lines in the read file
Brief description of the task: uses a while-loop to count the number
    of lines in the provided input file. 
*/
int count_lines(char* file_name) {
    //file pointer and error check if no file is provided
    FILE *file_reader = fopen(file_name, "r");
    if(file_reader == NULL) {
        printf("File not found");
        exit(0);
    }
    
    // check for the header
    char header_str[100];
    fgets(header_str, 100, file_reader);
    int count = 0;
    while(fgets(header_str, 100, file_reader)!=NULL) {
        count++;
    }
    return count;
}

/*
    Function Name: process_list
    Input to the method: file_name, the name of the current file
    Output(Return value): first_process, the first process identified on the list. 
    Brief description of the task: uses the line count to read through each line
        and store its contents (process id, arrival current_time and burst) in the 2d array
        processes
*/
int **process_list(char* file_name) {
    lines = count_lines(file_name);
    
    //filling of array child_num with initialized 0s
    int *child_num;
    child_num = malloc(sizeof(int*) * 10);
    int i;
    for(i = 0; i < 10; i++) {
        child_num[i] = 0;
    }
    children = child_num;
    
    
    //open given file to read
    FILE *file_reader = fopen(file_name, "r");
    if(file_reader == NULL) {
        printf("File not found");
        exit(0);
    }

    // get first header line
    char currstring[60];
    fgets(currstring, 60, file_reader); 
    int **first_process;
    first_process = malloc(sizeof(int*) * lines);
    int j;

    //for-loop, assigning elements to [j][x] for process num, AT and Burst
    for(j=0; j<lines; j++) {
        first_process[j] = malloc(sizeof(int*) * 3);
        fscanf(file_reader, "%d", &first_process[j][0]);
        fscanf(file_reader, "%d", &first_process[j][1]);
        fscanf(file_reader, "%d", &first_process[j][2]);
    }
    
    fclose(file_reader);
    return first_process;
}

/*
    Function Name: remove_one_row
    Input to the method: input, the index to remove from the array
    Output(Return value): first_process, the next process with shortest
        burst to start running once terminated
    Brief description of the task: remove the element of the children array
        at the provided index by moving other elements to a new array to give to processes,
        and returning the index of the new process to start. 
*/
int **remove_one_row(int **input) {
    //terminate the running process that has its time at 0
    terminate_child(running_process);
    //make a new array one line shorter
    int **first_process;
    first_process = malloc(sizeof(int*) * (lines - ended_processes));
    int j;
    int offset = 0; //offset value for resizing array
    for(j = 0; j < (lines - ended_processes + 1); j++) {
        int k = (j - offset);
        //if this is the process we want to remove, add the offset instead. 
        if (j == running_process) { 
            offset++;
        }
        //else, copy the contents of the array element into the new array. 
        else {
            first_process[k] = malloc(sizeof(int*) * 3);
            first_process[k] = input[j];
        }//effectively, j is read head and k is write head
        
    }
    
    return first_process;
}

/*
    Function Name: continue_child
    Input to the method: child, the pid of the child object
    Output(Return value): n/a
    Brief description of the task: sends the SIGCONT command to the child, 
        causing it to continue execution. 
*/
void continue_child(int child) { 
    kill(children[processes[child][0]],SIGCONT);
    running_process = child; 
}

/*
    Function Name: create_child
    Input to the method: new_process_num, the process number to be passed to the child
    Output(Return value): n/a
    Brief description of the task: creates a child object to be forked outwards. 
*/
void create_child (int new_process_num) { 
    //if there is a running process, stop it.
    if (running_process != -1) {
        stop_child(running_process);
    }
    running_process = new_process_num;
    //if there is not a process for this process number yet, make one
    if (children[processes[new_process_num][0]] == 0) { 
        int child_pid; 
        child_pid = fork(); 
        //child runs if
        if (child_pid == 0) {
            char sending[10];
            sprintf(sending, "-p %d", processes[new_process_num][0]);
            execlp("./child", "./child", sending, (char *)NULL);
        }//parent runs else
        else {
            children[processes[new_process_num][0]] = child_pid; 
            running_process = new_process_num;
        }
    }//otherwise continue the exsisting process
    else {
        continue_child(new_process_num);
    }
}

/*
    Function Name: stop_child
    Input to the method: child, the pid of the child object
    Output(Return value): n/a
    Brief description of the task: sends the SIGTSTP command to the child, 
        causing it to continue execution. 
*/
void stop_child(int child) {
    kill(children[processes[child][0]],SIGTSTP); //pause current process
}

/*
    Function Name: terminate_child
    Input to the method: child, the pid of the child object
    Output(Return value): n/a
    Brief description of the task: sends the SIGTERM command to the child, 
        causing it to terminate. 
*/
void terminate_child(int child) { 
    kill(children[processes[child][0]],SIGTERM);
}


/*
    Function Name: manage_children
    Input to the method: minproc, the process with the minimum burst current_time
    Output(Return value): n/a
    Brief description of the task: uses minproc to fork a child process if none exist,
        otherwise sends kill commands to manage children
*/
void manage_children(int minproc) {
    
    //if there is no running process
    if(running_process == -1) {
        create_child(minproc);
        printf("Scheduling process %d (PID %d) whose remaining time is %d seconds\n", processes[minproc][0], children[processes[minproc][0]], processes[minproc][2]);
    }

    // else if the minimum burst process is currently running
    else if(minproc == running_process) {
        //do nothing, current process keeps running
        printf("Continuing to run process %d (PID %d) whose remaining time is %d seconds\n", processes[minproc][0], children[processes[minproc][0]], processes[minproc][2]);
    }

    // else, pause the current process, and fork to the one with the lowest burst
    else {
        create_child(minproc);
        printf("Pausing process and starting process %d (PID %d) whose remaining time is %d seconds\n", processes[minproc][0], children[processes[minproc][0]], processes[minproc][2]);
        running_process = minproc;
    }
}

/*
    Function Name: on_clock_tick
    Input to the method: n/a
    Output(Return value): n/a
    Brief description of the task: on a clock tick, increase the timer, 
        check the running processes, remove terminated processes
*/
void on_clock_tick() {
    //count up current_time, and check how many of the processes have arrived
    current_time++;
    printf("\nCurrent time: %d\n", current_time);
    //if there is a running process, decrement its remaining time, and check if it's at 0
    if(running_process != -1) {
        processes[running_process][2] = (processes[running_process][2] -1);
        if(processes[running_process][2] <= 0) {
            //if at 0, terminate process
            ended_processes++;
            int** new_proc = remove_one_row(processes);
            processes = new_proc;
            running_process = -1;
            //if all the processes are done
            if(lines == ended_processes) {
                printf("Complete!");
                exit(0);
            }
        }
    }
    //check how many processes have arrived at the current time
    int identified_processes = 0;
    int i;
    for(i=0; i < (lines - (ended_processes)); i++) {
        if(processes[i][1] <= current_time) {
            identified_processes++;
        }
    }
    //find the process with the SRT, counting backwards through AT so that ties are broken by AT
    int j;
    int min = -1;
    int minproc = -1;
    for(j = (identified_processes-1); j >= 0; j--) {
        int current_process = processes[j][2];
        if(j == (identified_processes-1)) {
            min = current_process;
            minproc = j;
        }
        else if(current_process <= min) {
            min = current_process;
            minproc = j;
        }
    }
    manage_children(minproc);
}

/*
    Function Name: main
    Input to the method: argc and argv, input arguments
    Output(Return value): return 0, used to denote completion of program
    Brief description of the task: controls the process list and starts the timer
        sets the process list for use by the program
*/
int main(int argc, char *argv[]) {
    char *file_name = argv[1];
    processes = process_list(file_name);
    running_process = -1;
    ended_processes = 0;
    int i;
    
    //for-loop to print the processes
    for(i = 0; i < lines; i++) {
        printf("%d, %d, %d\n", processes[i][0],processes[i][1],processes[i][2]);

    }
    current_time = 0;
    start_timer();
    
    return 0;
}

