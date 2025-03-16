#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the integer N which determines the size of the input array
    int N;
    cin >> N;
    
    // Calculate the size of the array as 2^N
    int size = (1 << N);
    
    // Initialize an array S to hold the input values
    vector<int> S(size);
    
    // Initialize a boolean array to track which elements have been spawned
    vector<bool> spawned(size);
    
    // Mark the last element as spawned (the largest element)
    spawned[size - 1] = true;
    
    // Read N elements into the array S
    for (int i = 0; i < size; i++) {
        cin >> S[i];
    }
    
    // Sort the array S in ascending order
    sort(S.begin(), S.end());
    
    // Create a list to keep track of active slimes
    vector<int> active;
    
    // Add the largest element to the active list
    active.push_back(S[size - 1]);
    
    // Mark the largest element as spawned
    spawned[size - 1] = true;
    
    // Iterate N times to activate new slimes
    for (int i = 0; i < N; i++) {
        // Sort the active list in descending order
        sort(active.begin(), active.end(), greater<int>());
        
        // Create a list to keep track of newly activated slimes
        vector<int> activated;
        
        // Initialize the next index to the last element of S
        int next = size - 1;
        
        // Iterate through each slime in the active list
        for (int slime : active) {
            // Find the next unspawned element that is less than the current slime
            while (next >= 0 && (S[next] >= slime || spawned[next])) {
                next--;
            }
            
            // If no valid unspawned element is found, print "No" and exit
            if (next < 0) {
                cout << "No" << endl;
                return 0;
            }
            
            // Mark the found element as spawned
            spawned[next] = true;
            
            // Add the newly activated slime to the activated list
            activated.push_back(S[next]);
        }
        
        // Add all newly activated slimes to the active list
        active.insert(active.end(), activated.begin(), activated.end());
    }
    
    // If all iterations complete successfully, print "Yes"
    cout << "Yes" << endl;
    
    return 0;
}

