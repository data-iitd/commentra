#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

#define MAX_STRING 30
#define MAX_HUMAN 200000

string sLongInputLine(MAX_LINE + 1, '\0'); // Initialize a string to store a long input line
vector<int> anComingSec(MAX_HUMAN); // Initialize a vector to store the arrival time of humans

int main() {
    string sInput; // Initialize a string to store a single input line
    string token; // Store a token from the input line
    int nHumanNumber = 0; // Initialize a counter for the number of humans
    int nWaterLength = 0; // Initialize the length of the water wave
    int nWaterLife = 0; // Initialize the life of the water wave
    int nStart = 0; // Initialize the start time of the water wave
    int nStop = 0; // Initialize the stop time of the water wave
    int nNextHumanIndex = 0; // Initialize a counter for the index of the next human

    // Read the first line of input
    getline(cin, sInput); // Read a line from the standard input stream into the sInput string
    stringstream ss(sInput); // Use a stringstream to tokenize the input string
    ss >> nHumanNumber >> nWaterLength; // Extract the number of humans and the length of the water wave from the input string

    // Read the second line of input
    getline(cin, sLongInputLine); // Read a line from the standard input stream into the sLongInputLine string
    stringstream ss2(sLongInputLine); // Use a stringstream to tokenize the input string
    int i = 0; // Initialize a counter for iterating through the humans

    // Parse the second line of input and store the arrival times of the humans in the anComingSec vector
    while (ss2 >> token) {
        anComingSec[i++] = stoi(token); // Convert the token to an integer and store it in the anComingSec vector
    }

    // Initialize the start time of the water wave to the arrival time of the first human
    nStart = anComingSec[0];

    // Calculate the life of the water wave by iterating through the humans and finding the overlapping periods
    while (nNextHumanIndex < nHumanNumber) {
        if (nNextHumanIndex == nHumanNumber) {
            break; // If we have reached the last human, we are done
        } else {
            // Calculate the stop time of the water wave based on the start time and the length of the water wave
            nStop = nStart + nWaterLength;

            // Check if the next human arrives before the stop time of the water wave
            if (anComingSec[nNextHumanIndex] < nStop) {
                // If the next human arrives before the stop time, we need to find the maximum stop time that includes both the current and next human
                while (nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop) {
                    if (nStop <= anComingSec[nNextHumanIndex] + nWaterLength) {
                        nStop = anComingSec[nNextHumanIndex] + nWaterLength; // Update the stop time to include the next human
                        nNextHumanIndex++; // Move to the next human
                    }
                }

                // If we have reached the end of the array, we have found the maximum stop time that includes all the humans
                if (nNextHumanIndex == nHumanNumber) {
                    nWaterLife += (nStop - nStart); // Calculate the life of the water wave based on the start and stop times
                    break; // Exit the loop
                }
            }

            // If the next human arrives after the stop time of the water wave, we can update the start time to the arrival time of the next human and continue the loop
            nStart = nStop;
            if (nStart < anComingSec[nNextHumanIndex]) {
                nStart = anComingSec[nNextHumanIndex]; // Update the start time to the arrival time of the next human
            }
        }
    }

    // Print the life of the water wave to the standard output stream
    cout << nWaterLife << endl;

    return 0;
}
