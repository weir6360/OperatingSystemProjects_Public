/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: 5ps.c
    Description of the program: Handles user input of the requested commands, as well as
        compiling and displaying the proper output
*/

#include "p.h"
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
#include <zconf.h>

/*
Function Name: main
Input to the method: 
    argc: number of commands being passed into program
    argv: list of commands being passed into the program
Output(Return value): 
Brief description of the task:
*/
int main(int argc, char *argv[]) {
    int opt;
    int pid = 1;	
    int s = 0;
    int t = 0;
    int v = 0;
    int c = 0;

    //while getopt is processing commands, loop through inputs to find and flag commands as accepted
    while((opt = getopt(argc, argv, "p:stvc")) != -1) { 
        switch(opt) { 
            case 'p': 
            	printf("\noption: p");      
            	pid = atoi(optarg);         //store provided pid
            	printf("pid: %i", pid);
            	break;
            case 's': 
            	printf("\noption: s");
            	s = 1;
            	break;
            case 't': 
            	printf("\noption: t"); 
            	t = 1;
            	break;
            case 'v': 
            	printf("\noption: v"); 
            	v = 1;
            	break;
            case 'c':
            	printf("\noption: c");
            	c = 1;
            	break;
            case '?': 
                printf("\nunknown option: %c\n", optopt);
                break; 
        } 
    }

//1234: R time=00:03:14 sz=1234567 [myprog -x -y filel myoption]
//5ps -p 1234 -s -t -c -v
    if (pid == 0) {
        printf("Provided PID is invalid, closing program");
        exit(0);
    }
//s.c command passing pid sval = (s_return(pid);?)
//const char* tval;
//tval = t_return(pid);
//cval = c_return(pid);
//vval = v_return(pid);
//printf(pid,": ", sval, " time=", tval, " sz=", vval, " ", cval);
//  printf(pid, tval);
    printf(s_return(pid));

}





