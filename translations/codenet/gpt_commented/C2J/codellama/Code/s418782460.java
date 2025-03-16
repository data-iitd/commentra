#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STRING 30
#define MAX_LINE 2000000
#define MAX_HUMAN 200000

// Global variables
char sLongInputLine[MAX_LINE+1]=""; // Buffer for long input line
int  anComingSec[MAX_HUMAN]; // Array to store the coming seconds of humans

int main() {
    // Local variables
    char sInput[MAX_STRING+1]=""; // Buffer for the first line of input
    char* psWord=NULL; // Pointer for tokenizing words
    char* psInput=NULL; // Pointer for tokenizing input

    int nHumanNumber=0; // Number of humans
    int nNextHumanIndex=0; // Index for the next human
    int nWaterLength=0; // Length of water coverage
    int nWaterLife=0; // Total water life duration
    int nStart=0; // Start time for water coverage
    int nStop=0; // Stop time for water coverage

    int nIndex=0; // General index variable
    int i=0; // Loop counter
    int j=0; // Loop counter

    // Read the first line of input containing number of humans and water length
    fgets(sInput, MAX_STRING, stdin);
    if (strchr(sInput, '\n') != NULL) {
        sInput[strlen(sInput) - 1] = '\0'; // Remove newline character
    }
    psInput = strtok(sInput, " "); // Tokenize the input
    nHumanNumber = atoi(psInput); // Convert first token to number of humans
    psInput = strtok(NULL, " "); // Get the next token
    nWaterLength = atoi(psInput); // Convert to water length

    // Read the second line of input containing the coming seconds of humans
    fgets(sLongInputLine, MAX_LINE, stdin);
    if (strchr(sLongInputLine, '\n') != NULL) {
        sLongInputLine[strlen(sLongInputLine) - 1] = '\0'; // Remove newline character
    }
    psInput = strtok(sLongInputLine, " "); // Tokenize the input
    for (i = 0; i < nHumanNumber; i++) {
        anComingSec[i] = atoi(psInput); // Store each coming second in the array
        psInput = strtok(NULL, " "); // Get the next token
    }

    // Initialize the start time for water coverage
    nStart = anComingSec[0];

    // Main loop to calculate the total water life duration
    while (nNextHumanIndex < nHumanNumber) {
        if (nNextHumanIndex == nHumanNumber) {
            break; // Exit if all humans have been processed
        } else {
            nStop = nStart + nWaterLength; // Calculate stop time based on water length
            if (anComingSec[nNextHumanIndex] < nStop) {
                // Process humans that arrive before the current stop time
                while (nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop) {
                    if (nStop <= anComingSec[nNextHumanIndex] + nWaterLength) {
                        nStop = anComingSec[nNextHumanIndex] + nWaterLength; // Extend stop time if necessary
                        nNextHumanIndex++; // Move to the next human
                    }
                }
                if (nNextHumanIndex == nHumanNumber) {
                    nWaterLife = nWaterLife + (nStop - nStart); // Add to water life if all humans are processed
                    break;
                }
            }
            nWaterLife = nWaterLife + (nStop - nStart); // Add the duration of water coverage
            nStart = nStop; // Update start time for the next iteration
            if (nStart < anComingSec[nNextHumanIndex]) {
                nStart = anComingSec[nNextHumanIndex]; // Adjust start time if necessary
            }
        }
    }

    // Output the total water life duration
    System.out.println(nWaterLife);

    return 0; // End of the program
}

