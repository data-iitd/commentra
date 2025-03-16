
#include <iostream> // Include the necessary libraries for input and output
#include <vector> // Include the vector library for arrays

using namespace std; // Use the standard namespace

int main() {
    int N, M; // Declare variables to store the number of elements N and the number of comparisons M
    cin >> N >> M; // Read the number of elements N and the number of comparisons M from the input
    
    vector<long long> H(N); // Initialize a vector to store the heights of N elements
    vector<bool> ans(N, true); // Initialize a vector to store the result for each element
    
    // Read the heights of the elements into the vector H
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    
    // Read the pairs of indices (temp1 and temp2) and compare the heights at these indices
    for (int i = 0; i < M; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        
        if (H[temp1 - 1] < H[temp2 - 1]) {
            ans[temp1 - 1] = false; // Update the vector ans based on the comparison results
        } else if (H[temp1 - 1] > H[temp2 - 1]) {
            ans[temp2 - 1] = false; // Update the vector ans based on the comparison results
        } else {
            ans[temp1 - 1] = false; // Update the vector ans based on the comparison results
            ans[temp2 - 1] = false; // Update the vector ans based on the comparison results
        }
    }
    
    int ans2 = 0; // Initialize a counter to count the number of elements in the vector ans that are still true
    // Count the number of elements in the vector ans that are still true
    for (int i = 0; i < N; i++) {
        if (ans[i]) {
            ans2++; // Increment the counter if the element is still true
        }
    }
    
    cout << ans2 << endl; // Print the count
    
    return 0; // Return 0 to indicate successful execution
}

