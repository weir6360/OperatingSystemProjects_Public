/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission: 
    Name of this file: srtfScheduler.c
    Description of the program: 
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int **processes;
int lines;
int time;
int currentProcess;

int countlines(char* filename){
    FILE *fileReader = fopen(filename, "r");
    if(fileReader == NULL){
        printf("File not found");
        exit(0);
    }
    char bunkStr[100];
    fgets(bunkStr, 100, fileReader);
    int count = 0;
    while(fgets(bunkStr, 100, fileReader)!=NULL){
        count++;
    }
    return count;
}

int **procList(char* filename) {
    lines = countlines(filename);
    
    FILE *fileRead = fopen(filename, "r");
    if(fileRead == NULL){
        printf("File not found");
        exit(0);
    }

    char currstring[60];
    fgets(currstring, 60, fileRead); //get first bunk line
    //printf("%s", currstring); //don't need for program was for debugging
    
    int **firstProc;
    firstProc = malloc(sizeof(int*) * lines);
    int j;
    for(j=0; j<lines; j++){
        firstProc[j] = malloc(sizeof(int*) * 3);
        fscanf(fileRead, "%d", &firstProc[j][0]);
        fscanf(fileRead, "%d", &firstProc[j][1]);
        fscanf(fileRead, "%d", &firstProc[j][2]);
    }
    
    fclose(fileRead);
    return firstProc;
}

void onClockTick(){
    //count up time, and check how many of the processes have arrived
    time++;
    if(currentProcess != -1){
        processes[currentProcess][2] = processes[currentProcess][2] -1;
        printf("current process time: %d\n", processes[currentProcess][2]);
    }
    //NEED TO ADD CHECK TO MAKE SURE CURRENT PROCESS ISN'T DONE AND ADD TERMINATION(remove from list)
    printf("currprocs\n");
    int currProcs = 0;
    int i;
    for(i=0; i<lines; i++){
        if(processes[i][1]<=time){
            currProcs++;
        }
    }
    //find the process with the SRT, counting backwards through AT so that ties are broken by AT
    printf("SRT of %d processes\n", currProcs);
    int j;
    int min = -1;
    int minproc = -1;
    for(j = currProcs-1; j >= 0; j--){
        int toCheck = processes[j][2];
        if(j == currProcs-1){
            min = toCheck;
            minproc = j;
        }
        else if(toCheck < min){
            min = toCheck;
            minproc = j;
        }
    }
    //if no process is running, do the SRTF
    if(currentProcess == -1){
        //createChild(minproc)
        //startRunning(minproc)
        currentProcess = minproc;
        printf("Make new process %d\n", currentProcess);
    }
    else if(minproc == currentProcess){
        //do nothing I think
        printf("Let current process run %d\n", currentProcess);
    }
    else{
        currentProcess = minproc;
        //pause previous process
        //check if 'new' process already exists
        //createChild(minproc)
        printf("Pause current process and start new one %d\n", currentProcess);
    }

}

//Main function, starts the whole deal
int main(int argc, char *argv[]){
    char *filename = argv[1];
    processes = procList(filename);
    currentProcess = -1;
    int i;
    for(i = 0; i<lines; i++){
        printf("%d, %d, %d\n", processes[i][0],processes[i][1],processes[i][2]);

    }
    time = 0;
    //startClock();
    onClockTick();
    onClockTick();
    onClockTick();
    onClockTick();
    
    return 0;
}

