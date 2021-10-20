/*
    Author: Gabe Weir
    Assignment Number: 1
    Date of Submission:
    Name of this file: c.c
    Description of the program: Handles the -v command for the 5ps, reading the statm file
        in order to display the amount of virtual memory being used. 
*/

#include "v.h"
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

const char* v_return() { 
     
}