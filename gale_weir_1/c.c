/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: c.c
    Description of the program: Handles the -c command for the 5ps, reading the statm file
        in order to display the original command line 
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
#include <zconf.h>

/*
Function Name: c_return
Input to the method: pid: the process id for the current process
Output(Return value): the original command statement of the program associated with the pid
Brief description of the task: s_return parses the stat file for the program's pid state, passes it to 
    program_state, checks to make sure specified file exists, and if so returns the program_state
*/

const char* c_return(int pid) { 
    char[256] command_statement;
    
    //copies the contents at the file path /proc/<pid_path>/stat
    char *cmdline_file_path;
    strcpy(cmdline_file_path, ("/proc/%d/cmdline", pid)); 
    FILE *cmdline_file_pointer = fopen(cmdline_file_path, "r");
    
    if cmdline_file_pointer == NULL) { 
        return "failed to find cmdline file"
    }

    //Return a failed state if file pointer is invalid or the file cannot be scanned
    if (cmdline_file_pointer == NULL || fscanf(cmdline_file_pointer, "%*s\t%s", command_statement) < 1) {
        //failed state
         return "failed to retrieve state";
    }

    fclose(cmdline_file_pointer);
    return command_statement;
}