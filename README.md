A command-line C program that reads a 3-phase power quality log file, computes key waveform metrics, and writes a structured compliance report.

Built for Programming for Engineers project main coursework

 **What the Program Does**

- Reads a CSV file containing 3-phase voltage measurements (Phase A, B, C)
- Computes RMS voltage, peak-to-peak voltage, DC offset, and clipping detection per phase
- Checks EN 50160 tolerance compliance (207 V – 253 V)
- Writes a plain-text report to `results.txt`

**Project Structure**

PFE_Power_Quality_Analyser/
main.c          # Entry point — argument handling and orchestration
Waveform.c      # Analysis functions (RMS, peak, DC offset, clipping)
Waveform.h      # Struct definition and function declarations
io.c            # File I/O — CSV loading and results writing
io.h            # I/O function declarations
CMakeLists.txt  # CMake build configuration
README.md       # This file



**Requirements**

C compiler supporting C99 (GCC or Clang)
CMake 3.10 or higher
Math library: linked automatically via CMakeLists.txt

**How to Build and Run**

CLion
1. Open CLion and select File and Open, then choose the project folder
2. CLion will automatically detect "CMakeLists.txt" and configure the project
3. Click the Build button (hammer icon) or press "Ctrl+F9"
4. Once built, open the Run/Debug Configurations dropdown
5. Add the CSV filename as a program argument: power_quality_log.csv
6. Click RUN (green arrow) or press Shift+F10


**HOW TO USE**
./PFE_Power_Quality_Analyser power_quality_log.csv   <path_to_csv>

The program will print a summary table to the terminal and write a full report to `results.txt` in the current directory.


## Expected Output

**Terminal:**
POWER QUALITY ANALYSIS REPORT
Phase   | RMS Voltage   |   Peak Voltage
  A     |   229.72 Volts   |    650.01 Volts
  B     |   229.72 Volts   |    650.01 Volts
  C     |   229.72 Volts   |    650.01 Volts
Total Samples Processed: 1000
Results Written to results.txt

**results.txt** will contain RMS compliance status, peak-to-peak voltages, DC offsets, and clipping detection per phase.


**ERROR HANDLING**

| Scenario | Behaviour |
| No filename argument provided | Prints usage instructions and exits |
| CSV file not found | Prints error message and exits cleanly |
| Memory allocation failure | Prints error message, frees memory, and exits |


**DATASET**

The input file `power_quality_log.csv` contains 1,000 rows of 3-phase power measurements sampled at 5,000 samples/second over 200 ms (10 full cycles at 50 Hz).

| Column    | Unit    | Description |
| timestamp | seconds | Sample time, 0.0002 s steps |
| phase_A_voltage | Volts | Instantaneous Phase A voltage |
| phase_B_voltage | Volts | Instantaneous Phase B voltage |
| phase_C_voltage | Volts | Instantaneous Phase C voltage |
| line_current    | Amperes | Line current magnitude |
| frequency       | Hz | Instantaneous frequency estimate |
| power_factor    |  | Ratio of real to apparent power |
| thd_percent     | % | Total Harmonic Distortion |



**AUTHOR: UWANDU-JUDE VICTORY**
STUDENT NUMBER: 25058595
GitHub Repository Link: 3buk4/PFE-Power-Quality-Analyser
