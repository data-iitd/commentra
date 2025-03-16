#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

#pragma warning(disable:4996)

// Define constants for maximum sizes
const int MAX_STRING = 30;
const int MAX_LINE = 2000000;
const int MAX_HUMAN = 200000;

// Declare global variables
std::string sLongInputLine;
std::vector<int> anComingSec;

int main() {
    // Declare variables for input and processing
    std::string sInput;
    int nHumanNumber = 0;
    int nNextHumanIndex = 0;
    int nWaterLength = 0;
    int nWaterLife = 0;
    int nStart = 0;
    int nStop = 0;

    // Read the first line of input which contains the number of humans and the water length
    std::getline(std::cin, sInput);
    std::istringstream iss(sInput);
    iss >> nHumanNumber >> nWaterLength;

    // Read the second line of input which contains the seconds when each human arrives
    std::getline(std::cin, sLongInputLine);
    std::istringstream issLong(sLongInputLine);
    anComingSec.resize(nHumanNumber);
    for (int i = 0; i < nHumanNumber; i++) {
        issLong >> anComingSec[i];
    }

    // Initialize the start time to the first human's arrival time
    nStart = anComingSec[0];

    // Process the data to calculate the water life
    while (nNextHumanIndex < nHumanNumber) {
        if (nNextHumanIndex == nHumanNumber) {
            break;
        } else {
            nStop = nStart + nWaterLength;
            if (anComingSec[nNextHumanIndex] < nStop) {
                while (nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop) {
                    if (nStop <= anComingSec[nNextHumanIndex] + nWaterLength) {
                        nStop = anComingSec[nNextHumanIndex] + nWaterLength;
                        nNextHumanIndex++;
                    }
                }
                if (nNextHumanIndex == nHumanNumber) {
                    nWaterLife += (nStop - nStart);
                    break;
                }
            }
            nWaterLife += (nStop - nStart);
            nStart = nStop;
            if (nStart < anComingSec[nNextHumanIndex]) {
                nStart = anComingSec[nNextHumanIndex];
            }
        }
    }

    // Output the result which is the total water life
    std::cout << nWaterLife << std::endl;

    return 0;
}

// <END-OF-CODE>
