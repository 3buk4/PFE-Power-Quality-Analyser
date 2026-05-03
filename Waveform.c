//
// Created by PC on 4/12/2026.
//

#include "Waveform.h"
#include <math.h>
#include <stdio.h>

double calculate_rms(Waveformsample *data_array, int count, char phase_char) {
    if (count <= 0 || data_array == NULL) return 0; //if file is empty exit immediately

    double sum_sq = 0.0; // variable for v^2.

    for (int i = 0; i < count; i++) {
        //loops through every row
        double val = 0.0;// Variable to store the specific voltage


        if (phase_char == 'A')  val = data_array[i].phase_A_voltage; //checks phase char and grabs data
        else if (phase_char == 'B')  val = data_array[i].phase_B_voltage;
        else if (phase_char == 'C')  val = data_array[i].phase_C_voltage;

        sum_sq += val * val;
    }

        return sqrt(sum_sq / count);


}

double calculate_peak(Waveformsample *data_array, int count, char phase_char) {
       if (count <= 0 || data_array == NULL) return 0;//NULL/Empty file?, immediately exit

        double max_val = -1e9;
    double min_val = 1e9;


        for (int i = 0; i < count; i++) { //loop through every row
            double current_val = 0.0;
            if (phase_char == 'A')  current_val = data_array[i].phase_A_voltage;
            else if (phase_char == 'B')  current_val = data_array[i].phase_B_voltage;
            else if (phase_char == 'C')  current_val = data_array[i].phase_C_voltage;

            if (current_val > max_val) max_val = current_val;//Tracks the highest sample
            if (current_val < min_val) min_val = current_val;//Tracks the lowest sample
        }
    return max_val - min_val;
}

double calculate_dc_offset(Waveformsample *data_array, int count, char phase_char) {
    if (count <= 0 || data_array == NULL) return 0;

    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        if (phase_char == 'A')  sum += data_array[i].phase_A_voltage;
        else if (phase_char == 'B')  sum += data_array[i].phase_B_voltage;
        else if (phase_char == 'C')  sum += data_array[i].phase_C_voltage;
    }
    return sum / count;// mean voltage = DC offset
}

int count_clipped(Waveformsample *data_array, int count, char phase_char) {
    if (count <= 0 || data_array == NULL) return 0;

    int clipped = 0;
    for (int i = 0; i < count; i++) {
        double val = 0.0;

        if (phase_char == 'A')  val = data_array[i].phase_A_voltage;
        else if (phase_char == 'B')  val = data_array[i].phase_B_voltage;
        else if (phase_char == 'C')  val = data_array[i].phase_C_voltage;

        if (fabs(val) >= 324.9) clipped++;
    }
    return clipped;
}



int check_Tolerance(double rms) {
    if (rms >= 207.0 && rms <= 253.0) return 1; //Within EN 50160 band
    return 0;
}


