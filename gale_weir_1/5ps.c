/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: 5ps.c
    Description of the program: Handles user input of the requested commands, as well as the output
*/
#include "p.h"
#include "s.h"
#include "t.h"
#include "v.h"
#include "c.h"
#include <getopt.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include <ctype.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <zconf.h>
int main(int argc, char *argv[]){

int opt;
int pid = 1;	
int s = 0;
int t = 0;
int v = 0;
int c = 0;
while((opt = getopt(argc, argv, "p:stvc")) != -1) 
    { 
        switch(opt) 
        { 
            case 'p': 
            	printf("\noption: p");
            	pid = atoi(optarg);
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
if(pid == 0){
    printf("INVALID PID");
    exit(0);
}
//s.c command passing pid sval = (s_return(pid);?)
//const char* tval = t_return(pid);
//cval = c_return(pid);
//vval = v_return(pid);
//printf(pid,": ", sval, " time=", tval, " sz=", vval, " ", cval);
//  printf(pid, tval);
}






/*
void send_commands

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
}*/
