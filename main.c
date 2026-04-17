#include <stdio.h>
#include <stdlib.h>
#include "Waveform.h"
#include "io.h"

int main() {

    const char *filename = "power_quality_log"; //Pointer to the filename
    int num_samples = 2000;

    Waveformsample *data = (Waveformsample *) malloc(sizeof(Waveformsample));
    //Allocating thr memory

    if (data == NULL) {//Null check
        printf("Error: memory allocation failed\n");
        return 1;
    }

    int load = load_csv_data(filename, data, num_samples);//Loading the CSV file
    if (load == 0) {
        printf("Error: could not load\n");
        free(data);
        return 1;
    }
    //phase A
    double rms_a = calculate_rms(data, load, 'A');
    double peak_a = calculate_peak(data, load, 'A');

    //Phase B
    double rms_b = calculate_rms(data, load, 'B');
    double peak_b = calculate_peak(data, load, 'B');

    //phase C
    double rms_c = calculate_rms(data, load, 'C');
    double peak_c = calculate_peak(data, load, 'C');

    printf("");





    return 0;
}


