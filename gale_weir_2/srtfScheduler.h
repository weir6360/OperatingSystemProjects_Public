/*
    Author: Alex Gale, Gabe Weir
    Assignment Number: 2
    Date of Submission: 11/11/2021
    Name of this file: srtfScheduler.h
    Description of the program: header file for srtfScheduler.c
        
*/

int count_lines(char* filename); 

int **process_list(char* filename); 

int **remove_one_row(int **input);

void continue_child(int child);

void create_child(int new_process_num);

void stop_child(int child);

void terminate_child(int child);

void manage_children(int minproc); 

void on_clock_tick(); 

int main(int argc, char *argv[]);