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
#include "srtfScheduler.c"
#include "timer.h"

/*
Function Name: s_return
Input to the method: pid: the process id for the current process
Output(Return value): the program associated with the pid's state, either 
Brief description of the task: s_return parses the stat file for the program's pid state, passes it to 
    program_state, checks to make sure specified file exists, and if so returns the program_state
*/
int count_lines(char* filename) {
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
    int lines = countlines(filename);
    
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


int main(int argc, char *argv[]){
    char *filename = argv[1];
    int **processes;
    processes = procList(filename);
    for process in processes
    printf("%d, %d, %d\n", processes[0][0],processes[0][1],processes[0][2]);
    printf("%d, %d, %d\n", processes[1][0],processes[1][1],processes[1][2]);
    return 0;
}

