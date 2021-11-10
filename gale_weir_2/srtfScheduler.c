/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 2
    Date of Submission: 
    Name of this file: srtfScheduler.c
    Description of the program: 
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "child.h"
#include "srtfScheduler.h"
#include "timer.h"


int count_lines(char* filename) {
int **processes;
int lines;
int time;
int running_process;


/*
Function Name: 
Input to the method: 
Output(Return value):
Brief description of the task: s
*/
int count_lines(char* filename) {
    FILE *file_reader = fopen(filename, "r");
    if(file_reader == NULL) {
        printf("File not found");
        exit(0);
    }
    char header_str[100];
    fgets(header_str, 100, file_reader);
    int count = 0;
    while(fgets(header_str, 100, file_reader)!=NULL) {
        count++;
    }
    return count;
}

int **proc_list(char* filename) {
    lines = count_lines(filename);
    
    FILE *file_reader = fopen(filename, "r");
    if(file_reader == NULL) {
        printf("File not found");
        exit(0);
    }

    char currstring[60];
    fgets(currstring, 60, file_reader); //get first header line
    //printf("%s", currstring); //don't need for program was for debugging
    
    int **first_process;
    first_process = malloc(sizeof(int*) * lines);
    int j;
    for(j=0; j<lines; j++) {
        first_process[j] = malloc(sizeof(int*) * 3);
        fscanf(file_reader, "%d", &first_process[j][0]);
        fscanf(file_reader, "%d", &first_process[j][1]);
        fscanf(file_reader, "%d", &first_process[j][2]);
    }
    
    fclose(file_reader);
    return first_process;
}

void on_clock_tick() {
    //count up time, and check how many of the processes have arrived
    time++;
    if(running_process != -1) {
        processes[running_process][2] = processes[running_process][2] -1;
        printf("current process time: %d\n", processes[running_process][2]);
    }
    //NEED TO ADD CHECK TO MAKE SURE CURRENT PROCESS ISN'T DONE AND ADD TERMINATION(remove from list)
    printf("identified_processes\n");
    int identified_processes = 0;
    int i;
    for(i=0; i<lines; i++) {
        if(processes[i][1]<=time) {
            identified_processes++;
        }
    }
    //find the process with the SRT, counting backwards through AT so that ties are broken by AT
    printf("SRT of %d processes\n", identified_processes);
    int j;
    int min = -1;
    int minproc = -1;
    for(j = identified_processes-1; j >= 0; j--) {
        int current_process = processes[j][2];
        if(j == identified_processes-1) {
            min = current_process;
            minproc = j;
        }
        else if(current_process < min) {
            min = current_process;
            minproc = j;
        }
    }
    //if no process is running, do the SRTF
    if(running_process == -1) {
        //createChild(minproc)
        //startRunning(minproc)
        running_process = minproc;
        printf("Make new process %d\n", running_process);
    }
    else if(minproc == running_process) {
        //do nothing I think
        printf("Let current process run %d\n", running_process);
    }
    else{
        running_process = minproc;
        //pause previous process
        //check if 'new' process already exists
        //createChild(minproc)
        printf("Pause current process and start new one %d\n", running_process);
    }

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    processes = proc_list(filename);
    running_process = -1;
    int i;
    for(i = 0; i<lines; i++) {
        printf("%d, %d, %d\n", processes[i][0],processes[i][1],processes[i][2]);

    }
    time = 0;
    //startClock();
    on_clock_tick();
    on_clock_tick();
    on_clock_tick();
    on_clock_tick();
    
    return 0;
}

