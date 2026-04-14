//
// Created by PC on 4/12/2026.
//

#include "Waveform.h"
#include <math.h>
#include <stdio.h>

double calculate_rms(Waveformsample *data_array, int count, char phase_char) {
    if (count <= 0 || data_array == NULL) return 0; //if file is empty exit immediately

    double sum_sq = 0.0; //variable for v^2

    for (int i = 0; i < count; i++) {
        //loops through every row
        double val = 0.0;// Variable to store the specific voltage


        if (phase_char == 'A')  val = data_array[i].phase_A_voltage; //checks phase char and grabs data
        else if (phase_char == 'B')  val = data_array[i].phase_B_voltage;
        else if (phase_char == 'C')  val = data_array[i].phase_C_voltage;

        sum_sq += val * val;

        double rms = sqrt(sum_sq / count);

        return rms;
    }
}
double calculate_peak(Waveformsample *data_array, int count, char phase_char) {
       if (count <= 0 || data_array == NULL) return 0;//Empty file?, immediately exit

        double max_peak = 0.0;

        for (int i = 0; i < count; i++) { //loop through every row
            double current_val = 0.0;
            if (phase_char == 'A')  current_val = data_array[i].phase_A_voltage;
            else if (phase_char == 'B')  current_val = data_array[i].phase_B_voltage;
            else if (phase_char == 'C')  current_val = data_array[i].phase_C_voltage;

            if (fabs(current_val) > max_peak) max_peak = fabs(current_val);//removes negative sign if voltage spikes to -340v
        }
    return max_peak;

}


