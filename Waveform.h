//
// Created by PC on 4/12/2026.
//

#ifndef PFE_POWER_QUALITY_ANALYSER_WAVEFORM_H
#define PFE_POWER_QUALITY_ANALYSER_WAVEFORM_H

typedef struct {
    double timestamp; //Column 1: Time Stamp
    double phase_a; //Column 2: Voltage Phase A
    double phase_b; //Column 3: Voltage Phase B
    double phase_c; //Column 4: Voltage Phase c
    double current; //Column 5: Line Current
    double frequency; //Column 6: Frequency
    double power_factor; //Column 7: Power Factor
    double thd; //Column 8: thd_Percent (Total Harmonic Distortion)
} Waveformsample;

#endif //PFE_POWER_QUALITY_ANALYSER_WAVEFORM_H
