#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Initialize input stream for user input
    int N;
    cin >> N;

    // Calculate the size of the array S based on N
    int size = (1 << N);
    // Initialize the array S with user input
    vector<int> S(size);
    // Initialize a boolean array spawned to keep track of which slimes have been spawned
    vector<bool> spawned(size, false);
    // Set the last element of spawned to true, as it represents the position of the last slime
    spawned[size - 1] = true;

    // Read the initial positions of slimes from user input and store them in array S
    for (int i = 0; i < size; i++) {
        cin >> S[i];
    }
    // Sort the array S in ascending order
    sort(S.begin(), S.end());

    // Initialize a vector named active to store the indices of the currently active slimes
    vector<int> active;
    // Set the last element of spawned to true and add its index to the active list
    active.push_back(size - 1);
    spawned[size - 1] = true;

    // Iterate through each generation of slimes
    for (int i = 0; i < N; i++) {
        // Sort the vector active in descending order
        sort(active.rbegin(), active.rend());

        // Initialize a vector named activated to store the indices of the slimes that will be activated in the next generation
        vector<int> activated;
        // Initialize a variable named next to keep track of the index of the current slime in array S
        int next = size - 1;

        // Iterate through each slime in the current generation
        for (int slime : active) {
            // While the current index next is greater than or equal to 0 and the slime size is greater than or equal to the size of the current slime or the current index has already been spawned
            while (next >= 0 && (S[next] >= slime || spawned[next])) {
                next--;
            }
            // If the current index next is less than 0, it means that there is no empty space for the new slime to spawn, so print "No" and exit the program
            if (next < 0) {
                cout << "No" << endl;
                return 0;
            }
            // Set the current index as spawned and add its index to the activated vector
            spawned[next] = true;
            activated.push_back(S[next]);
        }
        // Add all the indices of the activated slimes to the active vector
        active.insert(active.end(), activated.begin(), activated.end());
    }

    // Print "Yes" to indicate that the program has successfully determined the positions of all N slimes
    cout << "Yes" << endl;

    return 0;
}

// <END-OF-CODE>
