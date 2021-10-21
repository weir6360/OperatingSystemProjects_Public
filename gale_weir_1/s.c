/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: c.c
    Description of the program: Handles the -s command for the 5ps, returning the single
        character state information about the process. 
*/

#include "s.h"

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
Output(Return value): the program associated with the pid's state, either 
Brief description of the task: s_return parses the stat file for the program's pid state, passes it to 
    program_state, checks to make sure specified file exists, and if so returns the program_state
*/

const char* s_return(int pid) {
    char[256] program_state;
    
    //copies the contents at the file path /proc/<pid_path>/stat
    char *stat_file_path;
    strcpy(stat_file_path, ("/proc/%d/stat", pid)); 
    FILE *stat_file_pointer = fopen(stat_file_path, "r");
    
    //Return a failed state if file pointer is invalid or the file cannot be read
    if (stat_file_pointer == NULL or fscanf(stat_file_pointer, "%s", program_state) < 1) {
        //failed state
        return "failed to retrieve state";
    }

    fclose(stat_file_pointer);
    return program_state;
}
