#include "io.h"
#include "Waveform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_csv_data(const char *filename, Waveformsample *data_array, int max_rows) {
    FILE *file;  // file pointer
    file = fopen(filename, "r"); //Attempting to open the csv in read mode

    if (file == NULL) {  //NULL CHECK
        printf("Error: could not open CSV file\n "); //Message if file was not found
        return -1;  //error prints if unsuccessful.
    }

    char line[1024];//buffer to hold one line at a time
    int count = 0; //Track of how many rows successfully stored

    fgets(line,sizeof(line), file);// Skips Header row

    while (fgets(line,sizeof(line), file) != NULL) { //Read one line at a time until the end of the file

        char *token;
        token = strtok(line, ",");
        if (token != NULL)
            data_array[count].timestamp = atof(token); //Reads the first number and converts string to double

        token = strtok(NULL, ",");
        if (token != NULL)
            data_array[count].phase_A_voltage = atof(token); //Reads the second number '' ''

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
            data_array[count].thd_percent = atof(token); //Reads the eight number.

        count++;//After filling one struct with 8 columns, move to the nxt index in our array

    }

    fclose(file);//close file
    return count;//returns number of rows read
}


int write_results(const char *filename, Waveformsample *data_array, int count) {

    FILE *file;
    file = fopen(filename, "w");

    if (file == NULL) {// null check
        printf("Error: could not write results in file\n ");
        return 1;
    }
    // Calculate the metrics
    double rms_a = calculate_rms(data_array, count, 'A');
    double rms_b = calculate_rms(data_array, count, 'B');
    double rms_c = calculate_rms(data_array, count, 'C');

    double peak_a = calculate_peak(data_array, count, 'A');
    double peak_b = calculate_peak(data_array, count, 'B');
    double peak_c = calculate_peak(data_array, count, 'C');

    //DC offset per phrase
    double dc_a = calculate_dc_offset(data_array, count, 'A');
    double dc_b = calculate_dc_offset(data_array, count, 'B');
    double dc_c = calculate_dc_offset(data_array, count, 'C');

// clipped sample count per phase
    int clip_a = count_clipped(data_array, count, 'A');
    int clip_b = count_clipped(data_array, count, 'B');
    int clip_c = count_clipped(data_array, count, 'C');



    //write the report
    //RMS VOLTAGE
    fprintf(file, "POWER QUALITY REPORT\n" );

    fprintf(file, "Total Samples Processed: %d\n\n", count);
    // RMS VOLTAGE
    fprintf(file,"RMS VOLTAGE\n");
    fprintf(file, "phase A: %.2f V    %s\n", rms_a, check_Tolerance(rms_a) ? "COMPLIANT" : "NON COMPLIANT");
    fprintf(file, "phase B: %.2f V    %s\n", rms_b, check_Tolerance(rms_b) ? "COMPLIANT" : "NON COMPLIANT");
    fprintf(file, "phase C: %.2f V    %s\n", rms_c, check_Tolerance(rms_c) ? "COMPLIANT" : "NON COMPLIANT");
    fprintf(file, "(EN 50160 tolerance band: 207v - 253v)\n\n");

    //PEAK TO PEAK VOLTAGE
    fprintf(file, "PEAK TO PEAK VOLTAGE\n");
    fprintf(file, "phase A: %.2f V\n", peak_a);
    fprintf(file, "phase B: %.2f V\n", peak_b);
    fprintf(file, "phase C: %.2f V\n\n", peak_c);

    //DC OFFSET
    fprintf(file, "DC OFFSET\n");
    fprintf(file, "phase A: %.6f V\n" , dc_a);
    fprintf(file, "phase B: %.6f V\n" , dc_b);
    fprintf(file, "phase C: %.6f V\n\n" , dc_c);

    //CLIPPING DETECTION
    fprintf(file, "CLIPPING DETECTION (V >= 324.9V)\n");
    fprintf(file, "phase A: %d clipped samples\n", clip_a);
    fprintf(file, "phase B: %d clipped samples\n", clip_b);
    fprintf(file, "phase C: %d clipped samples\n", clip_c);
    fprintf(file, "Total: %d clipped samples\n\n", clip_a + clip_b + clip_c);

    fclose(file);
    printf("Results Written to %s\n", filename);
    return 0;


}
