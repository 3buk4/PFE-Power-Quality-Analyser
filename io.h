//
// Created by PC on 4/12/2026.
//

#ifndef PFE_POWER_QUALITY_ANALYSER_IO_H
#define PFE_POWER_QUALITY_ANALYSER_IO_H

#include "Waveform.h"
int load_csv_data(const char *filename, Waveformsample *data_array, int max_rows);
int write_results(const char *filename, Waveformsample *data_array, int count);

#endif //PFE_POWER_QUALITY_ANALYSER_IO_H
