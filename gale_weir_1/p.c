/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: p.c
    Description of the program: Handles the -p command for the 5ps, returning the process information
        for the process number associated with pid. 
*/

#include "p.h"
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

const char* p_return() { 
     
}