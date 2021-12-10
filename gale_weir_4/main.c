/*
    We have: logical address, frame/page size (16 bytes, 2^4 bits), !RAM size (8 frames, or 16*8 = 128 bytes)
    We need to calculate
        1. Offset (logical address mod frame size)
        2. Logical page number (logical address div frame size)
        3. Physical page number (compare with page table Page Number --> Frame Number)
        4. Physical Address (Physical page number * page size + offset)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* address_file = "addresses.txt";
    char* process_file = "PROCESS.txt";

    FILE* address_reader = fopen(address_file, "r");
    if(address_reader == NULL) {
        printf("address file not found");
        exit(0);
    }
    
    FILE* process_reader = fopen(process_file, "r");
    if(process_reader == NULL) {
        printf("PROCESS file not found");
        exit(0);
    }

    //this will be a function and/or a loop, will process one line. will run 300 times
    int i;
    int logical_address;
    
    for(i = 0; i < 300; i++){
        fscanf(address_reader, "%d", &logical_address);
        
        printf("logical address: %d\n", logical_address);
    }
}