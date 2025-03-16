

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	string sInput; // Initialize a string to store a single input line
	vector<int> anComingSec; // Initialize a vector to store the arrival time of humans

	int nHumanNumber = 0; // Initialize a counter for the number of humans
	int nWaterLength = 0; // Initialize the length of the water wave
	int nWaterLife = 0; // Initialize the life of the water wave
	int nStart = 0; // Initialize the start time of the water wave
	int nStop = 0; // Initialize the stop time of the water wave

	// Read the first line of input
	cin >> nHumanNumber >> nWaterLength; // Read the number of humans and the length of the water wave from the standard input stream

	// Read the second line of input and store the arrival times of the humans in the anComingSec vector
	for (int i = 0; i < nHumanNumber; i++) {
		cin >> nStart; // Read the arrival time of a human from the standard input stream
		anComingSec.push_back(nStart); // Store the arrival time in the anComingSec vector
	}

	// Sort the arrival times of the humans in ascending order
	sort(anComingSec.begin(), anComingSec.end());

	// Calculate the life of the water wave by iterating through the humans and finding the overlapping periods
	for (int i = 0; i < nHumanNumber; i++) {
		nStop = anComingSec[i] + nWaterLength; // Calculate the stop time of the water wave based on the start time and the length of the water wave
		if (i < nHumanNumber - 1) {
			if (anComingSec[i + 1] < nStop) {
				nStop = anComingSec[i + 1] + nWaterLength; // Update the stop time to include the next human
			}
		}
		nWaterLife += (nStop - nStart); // Calculate the life of the water wave based on the start and stop times
		nStart = nStop; // Update the start time to the stop time of the current period
	}

	// Print the life of the water wave to the standard output stream
	cout << nWaterLife << endl; // Print the life of the water wave to the standard output stream

	return 0;
}

