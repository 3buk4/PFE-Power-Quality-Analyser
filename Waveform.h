//
// Created by PC on 4/12/2026.
//

#ifndef PFE_POWER_QUALITY_ANALYSER_WAVEFORM_H
#define PFE_POWER_QUALITY_ANALYSER_WAVEFORM_H


typedef struct {
    double timestamp; //Column 1: Time Stamp
    double phase_A_voltage; //Column 2: Voltage Phase A
    double phase_B_voltage; //Column 3: Voltage Phase B
    double phase_C_voltage; //Column 4: Voltage Phase c
    double line_current; //Column 5: Line Current
    double frequency; //Column 6: Frequency
    double power_factor; //Column 7: Power Factor
    double thd_percent; //Column 8: thd_Percent (Total Harmonic Distortion)
} Waveformsample;

double calculate_rms(Waveformsample *data_array, int count, char phase_char);
double calculate_peak(Waveformsample *data_array, int count, char phase_char);
int check_Tolerance(double rms);
#endif //PFE_POWER_QUALITY_ANALYSER_WAVEFORM_H
