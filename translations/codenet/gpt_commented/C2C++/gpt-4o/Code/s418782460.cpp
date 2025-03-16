#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#define MAX_STRING 30
#define MAX_LINE 2000000
#define MAX_HUMAN 200000

// Global variables
char sLongInputLine[MAX_LINE + 1] = ""; // Buffer for long input line
int anComingSec[MAX_HUMAN]; // Array to store the coming seconds of humans

int main() {
    // Local variables
    std::string sInput; // Buffer for the first line of input
    std::istringstream iss; // Stream for tokenizing words

    int nHumanNumber = 0; // Number of humans
    int nNextHumanIndex = 0; // Index for the next human
    int nWaterLength = 0; // Length of water coverage
    int nWaterLife = 0; // Total water life duration
    int nStart = 0; // Start time for water coverage
    int nStop = 0; // Stop time for water coverage

    // Read the first line of input containing number of humans and water length
    std::getline(std::cin, sInput);
    iss.clear();
    iss.str(sInput);
    iss >> nHumanNumber >> nWaterLength;

    // Read the second line of input containing the coming seconds of humans
    std::getline(std::cin, sLongInputLine);
    iss.clear();
    iss.str(sLongInputLine);
    for (int i = 0; i < nHumanNumber; i++) {
        iss >> anComingSec[i]; // Store each coming second in the array
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
                    nWaterLife += (nStop - nStart); // Add to water life if all humans are processed
                    break;
                }
            }
            nWaterLife += (nStop - nStart); // Add the duration of water coverage
            nStart = nStop; // Update start time for the next iteration
            if (nStart < anComingSec[nNextHumanIndex]) {
                nStart = anComingSec[nNextHumanIndex]; // Adjust start time if necessary
            }
        }
    }

    // Output the total water life duration
    std::cout << nWaterLife << std::endl;

    return 0; // End of the program
} // <END-OF-CODE>
