/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: v.c
    Description of the program: Handles the -v command for the 5ps, reading the statm file
        in order to display the amount of virtual memory being used. 
*/

#include "v.h"

#include <ctype.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/*
Function Name: s_return
Input to the method: pid: the process id for the current process
Output(Return value): the virtual memory used by the process with id pid
Brief description of the task: s_return parses the stat file for the program's pid state, passes it to 
    program_state, checks to make sure specified file exists, and if so returns the program_state*/

int v_return(int pid) { 
    int virtual_memory;
    
    //copies the contents at the file path /proc/<pid_path>/stat
    char pidstr[100];
    sprintf(pidstr, "%d", pid);
    char filestring1[100] = "/proc/"; 
    strcat(filestring1, pidstr);
    char filestring2[100] = "/stat";
    strcat(filestring1, filestring2);
    FILE* statm_file_pointer = fopen(filestring1, "r");
    
    //Return a failed state if file pointer is invalid or the file cannot be read
    if(statm_file_pointer != NULL){
        //for loop 22 times, to get to value 23
        int i;
        for(i = 0; i<=22; i++){
            fscanf(statm_file_pointer, "%*s");
        }
        fscanf(statm_file_pointer, "%d", &virtual_memory);
        fclose(statm_file_pointer);
        return virtual_memory;

    }

    fclose(statm_file_pointer);
    return 0;
}