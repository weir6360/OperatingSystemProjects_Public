/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: 5ps.c
    Description of the program: Handles user input of the requested commands, as well as the output
*/

#include <ctype.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <zconf.h>

#include "c.h"
#include "p.h"
#include "s.h"
#include "t.h"
#include "v.h"

char send_commands(char *process_id, char *current_command)


/*
Function Name: main
Input to the method: argc and **argv, user input of the function
Output(Return value): A formatted string outputing the desired options
Brief description of the task: Uses getopt to process and flag accepted tac commands, then
    calls send_commands() for each flagged command to get the formatted, desired output
*/
int main(int argc, char **argv) {
    char[256] c_return;
    int cflag = 0;
    char[256] p_return;
    int pflag = 0; 
    int *process_id = 1;
    char[256] s_return; 
    int sflag = 0; 
    char[256] t_return;
    int tflag = 0; 
    char[256] v_return;
    int vflag = 0; 
    int current_index;
    int command; 


    opterr = 0; 

    while ((command = getopt (argc, argv, "5ps")) != -1)
    {
        switch (command)
        {
            case 'c':
                cflag = 1;
                break;
            case 'p':
                pflag = 1; 
                /* AUTHOR"S NOTE: Need to include handling of -p's numeric index included.  */ 
                break; 
            case 's':
                sflag = 1; 
            case 't':
                tflag = 1; 
                break;
            case 'v':
                vflag = 1; 
                break;
        }
    }

    if (cflag == 0 and pflag == 0 and sflag == 0 and ) 
    { 

    }

    /*Ordered sequence of checking flagged conditions in order to produce an output
    that doesn't crash, such as trying to do -t first causing crashing.*/
    if cflag == 1 
    {

    }



}

char send_commands(char *process_id, char *current_command)
{ 
    switch (current_command)
    { 
        case 'c': 
        case 'p': 
        case 's': 
        case 't': 
        case 'v': 
    }
}