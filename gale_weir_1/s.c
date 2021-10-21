/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: c.c
    Description of the program: Handles the -s command for the 5ps, returning the single
        character state information about the process. 
*/

#include "s.h"
#include "statmParser.h"

#include <ctype.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <zconf.h>

/*
Function Name: s_return
Input to the method: pid: the process id for the current process
Output(Return value): 
Brief description of the task: 
*/

const char* s_return(int pid) {
    char[256] program_state;
    
    //copies the contents at the file path /proc/<pid_path>/stat
    char *stat_file_path;
    strcpy(stat_file_path, ("/proc/%d/stat", pid)); 
    FILE *stat_file_pointer = fopen(stat_file_path, "r");
    
    //Return a failed state if file pointer is invalid
    if (stat_file_pointer == NULL) {
        //failed state
        return 1;
    }

    //Return a failed state if the file cannot be scanned
    if (fscanf(state_file_pointer, "%*d %*s %c", program_state) < 1) {
        return 1;
    }

    fclose(stat_file_pointer);
    return program_state;
}
