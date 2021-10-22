/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: 5ps.c
    Description of the program: Handles user input of the requested commands, as well as
        compiling and displaying the proper output
*/

#include "s.h"
#include "t.h"
#include "v.h"
#include "c.h"

#include <ctype.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/*
Function Name: main
Input to the method: 
    argc: number of commands being passed into program
    argv: list of commands being passed into the program
Output(Return value): returns a 1 if it runs into a fail state, otherwise exits upon completion
Brief description of the task: uses getopt to mark flags if a given command was used, then runs through flagged commands sequentially 
*/
int main(int argc, char *argv[]) {
    int opt;
    int pid = 1;	
    int s = 0;
    int t = 0;
    int v = 0;
    int c = 0;

    char s_output;
    const char* t_output;
    int v_output;
    char* c_output;
    char final_output[1000];


    //while getopt is processing commands, loop through inputs to find and flag commands as accepted
    while((opt = getopt(argc, argv, "p:stvc")) != -1) { 
        switch(opt) { 
            case 'p': 
//            	printf("\noption: p");      
            	pid = atoi(optarg);         //store provided pid
//            	printf("pid: %i", pid);
            	break;
            case 's': 
//            	printf("\noption: s");
            	s = 1;
            	break;
            case 't': 
//            	printf("\noption: t"); 
            	t = 1;
            	break;
            case 'v': 
//            	printf("\noption: v"); 
            	v = 1;
            	break;
            case 'c':
//            	printf("\noption: c");
            	c = 1;
            	break;
            case '?': 
//                printf("\nunknown option: %c\n", optopt);
                break; 
        } 
    }

    if (pid == 0) {
        printf("Provided PID is invalid, closing program");
        exit(0);
    }

    //check flag on s
    if (s == 1) { 
        s_output = s_return(pid);    
    }
    else if (s != 1) { 
        s_output = 0;
    }

    //check flag on c
    if (c == 1) {
        c_output = c_return(pid);
    }
    else if (c != 1) {
        c_output = "";
    }
    
    //check flag on v
    if (v == 1) {
        v_output = v_return(pid);
    }
    else if (v != 1) {
        v_output = -1;
    }

    //check flag on t
    if (t == 1) {
        t_output = t_return(pid);
    }
    else if (t != 1)
    { 
        t_output = "";
    }

    if (v_output == -1) {
        sprintf(final_output, "\n%d: %c %s %s", pid, s_output, t_output, c_output);
    }
    else { 
        sprintf(final_output, "\n%d: %c time=%s sz=%d [%s]\n", pid, s_output, t_output, v_output, c_output);
    }

    printf("%s", final_output);

    return 0;
}





