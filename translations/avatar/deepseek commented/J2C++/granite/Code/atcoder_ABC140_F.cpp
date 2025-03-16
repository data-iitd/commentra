
#include <iostream> // Include necessary libraries
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N; // Declare and initialize the integer N
    cin >> N;
    int size = (1 << N); // Calculate the size of the array S, which is 2^N
    vector<int> S(size); // Initialize a vector S to store integers
    vector<bool> spawned(size, false); // Initialize a boolean vector to track spawned elements
    spawned[size - 1] = true; // Set the last element of spawned to true, indicating it's initially active

    // Read integers into the vector S
    for (int i = 0; i < size; i++) {
        cin >> S[i];
    }

    sort(S.begin(), S.end()); // Sort the vector S
    vector<int> active; // Initialize a vector to keep track of active elements
    active.push_back(S[size - 1]); // Add the largest element from S to the active list and mark it as spawned
    spawned[size - 1] = true;

    // Iterate N times
    for (int i = 0; i < N; i++) {
        sort(active.begin(), active.end(), greater<int>()); // Sort the active list in reverse order
        vector<int> activated; // Initialize a vector to find new activated elements
        int next = size - 1; // Initialize next to find new activated elements

        // Find new activated elements
        for (int slime : active) {
            while (next >= 0 && (S[next] >= slime || spawned[next])) {
                next--;
            }
            if (next < 0) {
                cout << "No" << endl; // If no new activated elements are found, print "No"
                return 0;
            }
            spawned[next] = true; // Mark the found element as spawned
            activated.push_back(S[next]); // Add the found element to the activated list
        }
        active.insert(active.end(), activated.begin(), activated.end()); // Add the activated elements to the active list
    }
    cout << "Yes" << endl; // If N iterations are successful, print "Yes"

    return 0;
}
