#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define a pair type to hold an integer and a string
typedef pair<int,string> P;

// Array to hold pairs of scores and names
P v[22];

// Vector to hold lists of indices for each number
vector<int> d[33];

int main(void) {
    int n; // Variable to hold the number of participants

    // Read the number of participants until a zero is encountered
    while(cin >> n && n) {
        int m; // Variable to hold the number of scores for each participant

        // Clear the previous data in the vector of lists
        for(int i = 0; i < 33; i++) d[i].clear();

        // Loop through each participant
        for(int i = 0; i < n; i++) {
            v[i].first = 0; // Initialize the score of the participant to zero

            // Read the participant's name and the number of scores
            cin >> v[i].second >> m;

            // Loop through each score for the current participant
            for(int j = 0; j < m; j++) {
                int a; // Variable to hold the score value
                cin >> a; // Read the score

                // Update the score of the current participant
                v[i].first += n - (int)d[a].size();

                // Decrease the score of participants who have already received this score
                for(int k = 0; k < (int)d[a].size(); k++) {
                    v[d[a][k]].first--;
                }

                // Add the current participant's index to the list for this score
                d[a].push_back(i);
            }
        }

        // Sort the participants based on their scores
        sort(v, v+n);

        // Output the participant with the highest score
        cout << v[0].first << " " << v[0].second << endl;
    }
}
