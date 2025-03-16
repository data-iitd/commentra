#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    // Read the first line of input and split it into an array
    string input;
    getline(cin, input);
    vector<string> input_array;
    input_array = split(input, " ");

    // Parse the number of movements (m), start position (s), and final position (f)
    int m = stoi(input_array[1]);
    int s = stoi(input_array[2]);
    int f = stoi(input_array[3]);

    // Initialize maxT to keep track of the maximum time step
    int maxT = -1;

    // Create a HashMap to store the movements at each time step
    map<int, vector<int>> map;

    // Read the movements for each time step
    while (m > 0) {
        // Read the movement data for the current time step
        string mth;
        getline(cin, mth);
        vector<string> mth_array;
        mth_array = split(mth, " ");

        // Initialize the list for the current time step and add the movement range
        map[stoi(mth_array[0])] = vector<int>();
        map[stoi(mth_array[0])].push_back(stoi(mth_array[1]));
        map[stoi(mth_array[0])].push_back(stoi(mth_array[2]));

        // Update maxT to the highest time step encountered
        maxT = max(maxT, stoi(mth_array[0]));
        m--;
    }

    // Prepare a StringBuilder to store the actions taken
    string actions;

    // Determine the direction of movement based on start and final positions
    char M = (s < f)? 'R' : 'L';
    int d = (s < f)? +1 : -1;

    // Initialize current position to start position
    int cur = s;
    int a = -1;
    int b = -1;

    // Iterate through each time step from 1 to maxT
    for (int t = 1; t <= maxT; t++) {
        // Check if there are movements defined for the current time step
        if (map.find(t)!= map.end()) {
            a = map[t][0]; // Get the start of the movement range
            b = map[t][1]; // Get the end of the movement range
        }

        // Check if the current position or the next position is within the movement range
        if (map.find(t)!= map.end() && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) {
            actions += 'X'; // Append 'X' if within the range
        } else {
            actions += M; // Append the movement direction
            cur += d; // Update the current position
        }

        // Break the loop if the current position reaches the final position
        if (cur == f) break;
    }

    // Continue moving until the current position reaches the final position
    while (cur!= f) {
        actions += M; // Append the movement direction
        cur += d; // Update the current position
    }

    // Output the sequence of actions taken
    cout << actions << endl;

    return 0;
}

