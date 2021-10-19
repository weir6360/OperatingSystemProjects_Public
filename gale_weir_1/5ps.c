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

int main(int argc, char *argv[]){

int opt;	
while((opt = getopt(argc, argv, “:if:lrx”)) != -1) 
    { 
        switch(opt) 
        { 
            case ‘p’: 
            	printf("option: p");
            case ‘s’: 
            	printf("option: s");
            case ‘t’: 
            	printf("option: t"); 
            case ‘v’: 
            	printf("option: v"); 
            case ‘c’:
            	printf("option: c");
            case ‘:’: 
                printf(“option needs a value\n”); 
                break; 
            case ‘?’: 
                printf(“unknown option: %c\n”, optopt);
                break; 
        } 
    }
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
