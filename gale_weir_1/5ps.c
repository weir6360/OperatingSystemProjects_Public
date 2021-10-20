/*
    Author: Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: c.c
    Description of the program: Handles the -c command for the 5ps
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

int main() { 
    char input [255] = "\0";
    char *splitInput; 
    char *array [255]; 
    int numSpaces = 0; 
    int numBytes = 0; 
    int numLines = 0; 

    fgets(input, sizeof(input), stdin); 

    splitInput = strtok(input, "\n\t"); 
    
    while (splitInput != NULL)
    { 
        array[numSpaces++] = splitInput;
        splitInput = strtok (NULL, "\n\t");
    }

    for (int i = 1; i <= numSpaces; i = i + 1)
    { 
        if (i > (numSpaces - 1))
        {
            break;
        }
    }
}*/
