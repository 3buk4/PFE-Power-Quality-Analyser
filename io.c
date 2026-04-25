#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_csv_data(const char *filename, Waveformsample *data_array, int max_rows) {
    FILE *file;  // file pointer
    file = fopen(filename, "r"); //Attempting to open the csv in read mode

    if (file == NULL) {  //NULL CHECK
        printf("Error: could not open CSV file\n "); //Message if file was not found
        return 1;  //Returns 1 if unsuccessful.
    }

    char line[512];
    int count = 0; //Track of how many rows successfully stored

    fgets(line, sizeof(line), file);// Skips Header

    while (fgets(line, sizeof(line), file) != NULL) { //Runs loop untill the end of the file

        char *token;
        token = strtok(line, ",");
        if (token != NULL)
            data_array[count].timestamp = atof(token); //Reads the first number

        token = strtok(NULL, ",");
        if (token != NULL)
            data_array[count].phase_A_voltage = atof(token); //Reads the second number

        token = strtok(NULL, ",");
        if (token != NULL)
            data_array[count].phase_B_voltage = atof(token); //Reads the third number

        token = strtok(NULL, ",");
        if (token != NULL)
            data_array[count].phase_C_voltage = atof(token); //Reads the forth number

        token = strtok(NULL, ",");
        if (token != NULL)
            data_array[count].line_current = atof(token); //Reads the fifth number

        token = strtok(NULL, ",");
        if (token != NULL)
            data_array[count].frequency = atof(token); //Reads the sixth number

        token = strtok(NULL, ",");
        if (token != NULL)
            data_array[count].power_factor = atof(token); //Reads the seventh number

        token = strtok(NULL, ",");
        if (token != NULL)
            data_array[count].thd_percent = atof(token); //Reads the eight number

        count++;//After filling one struct with 8 columns, move to the nxt index in our array

    }

    fclose(file);//close file
    return 0;
}