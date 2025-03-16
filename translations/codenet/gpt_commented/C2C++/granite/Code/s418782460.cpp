
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string sInput; // Buffer for the first line of input
    string sLine; // Buffer for the second line of input
    vector<int> anComingSec; // Vector to store the coming seconds of humans

    int nHumanNumber=0; // Number of humans
    int nWaterLength=0; // Length of water coverage
    int nWaterLife=0; // Total water life duration
    int nStart=0; // Start time for water coverage
    int nStop=0; // Stop time for water coverage

    // Read the first line of input containing number of humans and water length
    getline(cin, sInput);
    stringstream ss(sInput);
    ss >> nHumanNumber >> nWaterLength;

    // Read the second line of input containing the coming seconds of humans
    getline(cin, sLine);
    stringstream ss2(sLine);
    int nTemp=0;
    while (ss2 >> nTemp) {
        anComingSec.push_back(nTemp);
    }

    // Initialize the start time for water coverage
    nStart = anComingSec[0];

    // Main loop to calculate the total water life duration
    for (int i = 0; i < nHumanNumber; i++) {
        if (i == nHumanNumber) {
            break; // Exit if all humans have been processed
        } else {
            nStop = nStart + nWaterLength; // Calculate stop time based on water length
            if (anComingSec[i] < nStop) {
                // Process humans that arrive before the current stop time
                int j = i;
                while (j < nHumanNumber && anComingSec[j] < nStop) {
                    if (nStop <= anComingSec[j] + nWaterLength) {
                        nStop = anComingSec[j] + nWaterLength; // Extend stop time if necessary
                        j++; // Move to the next human
                    }
                }
                if (j == nHumanNumber) {
                    nWaterLife = nWaterLife + (nStop - nStart); // Add to water life if all humans are processed
                    break;
                }
            }
            nWaterLife = nWaterLife + (nStop - nStart); // Add the duration of water coverage
            nStart = nStop; // Update start time for the next iteration
            if (nStart < anComingSec[i]) {
                nStart = anComingSec[i]; // Adjust start time if necessary
            }
        }
    }

    // Output the total water life duration
    cout << nWaterLife << endl;

    return 0; // End of the program
}

