/*
    Author: Gabe Weir
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
#include <zconf.h>

/*
Function Name: s_return
Input to the method: pid: the process id for the current process
Output(Return value): the virtual memory used by the process with id pid
Brief description of the task: v_return parses the statm file for its contents
*/

const char* v_return(int pid) { 
    char[256] virtual_memory;
    
    //copies the contents at the file path /proc/<pid_path>/stat
    char *statm_file_path;
    strcpy(statm_file_path, ("/proc/%d/statm", pid)); 
    FILE *statm_file_pointer = fopen(statm_file_path, "r");
    
    //Return a failed state if file pointer is invalid or the file cannot be read
    if (statm_file_pointer == NULL or fscanf(statm_file_pointer, "%*d %*s %c", virtual_memory) < 1) {
        //failed state
        return 1;
    }

    fclose(statm_file_pointer);
    return virtual_memory;
}