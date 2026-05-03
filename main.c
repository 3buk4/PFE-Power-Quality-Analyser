#include <stdio.h>
#include <stdlib.h>
#include "Waveform.h"
#include "io.h"

int main(int argc, char *argv[]) {

if (argc < 2) {
    printf("Usage: %s <power_quality_log.csv>\n", argv[0]);
    return 1;
}
    const char *filename = argv[1]; //inputs csv path from command line
    const char *output_file = "results.txt"; //output report to be written here

    int num_samples = 2000; // Buffer size(larger than data set to avoid overflow)

    Waveformsample *data = (Waveformsample *) malloc(num_samples * sizeof(Waveformsample));
    //Allocating thr memory

    if (data == NULL) {//Null check for memory allocation
        printf("Error: memory allocation failed\n");
        return 1;
    }

    int load = load_csv_data(filename, data, num_samples);//Loading the CSV file(I/O)
    if (load <= 0) {
        printf("Error: could not load\n");
        free(data);
        return 1;
    }
    //phase A
    double rms_a = calculate_rms(data, load, 'A');//calls up function in waveform.c
    double peak_a = calculate_peak(data, load, 'A');

    //Phase B
    double rms_b = calculate_rms(data, load, 'B');
    double peak_b = calculate_peak(data, load, 'B');

    //phase C
    double rms_c = calculate_rms(data, load, 'C');
    double peak_c = calculate_peak(data, load, 'C');

    printf("POWER QUALITY ANALYSIS REPORT   \n");
    printf("Phase   | RMS Voltage   |   Peak Voltage       \n");
    printf("  A     | %8.2f Volts   |    %8.2f Volts       \n", rms_a, peak_a);
    printf("  B     | %8.2f Volts   |    %8.2f Volts       \n", rms_b, peak_b);
    printf("  C     | %8.2f Volts   |    %8.2f Volts       \n", rms_c, peak_c);


    printf("Total Samples Processed: %d\n", load);



write_results(output_file, data, load);//writes full report to the file results.txt

   free(data);
    return 0;
}


