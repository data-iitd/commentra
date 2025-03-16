#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

// Global variables
string sLongInputLine; // Buffer for long input line
vector<int> anComingSec; // Array to store the coming seconds of humans

int main() {
    // Local variables
    string sInput; // Buffer for the first line of input
    string sWord; // Buffer for tokenizing words
    string sInput; // Buffer for tokenizing input

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
    getline(cin, sInput);
    sInput.erase(sInput.find_last_not_of(" ") + 1); // Remove trailing spaces
    sInput.erase(0, sInput.find_first_not_of(" ")); // Remove leading spaces
    istringstream iss(sInput);
    iss >> nHumanNumber >> nWaterLength;

    // Read the second line of input containing the coming seconds of humans
    getline(cin, sLongInputLine);
    sLongInputLine.erase(sLongInputLine.find_last_not_of(" ") + 1); // Remove trailing spaces
    sLongInputLine.erase(0, sLongInputLine.find_first_not_of(" ")); // Remove leading spaces
    istringstream iss(sLongInputLine);
    while (iss >> sWord) {
        anComingSec.push_back(atoi(sWord.c_str())); // Store each coming second in the array
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
    cout << nWaterLife << endl;

    return 0; // End of the program
}

