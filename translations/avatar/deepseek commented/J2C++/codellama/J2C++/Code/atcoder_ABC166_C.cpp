#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int N; // Declare the number of elements N
    long M; // Declare the number of comparisons M
    
    cin >> N >> M; // Read the number of elements N and the number of comparisons M
    
    long H[N]; // Declare an array to store the heights of N elements
    bool ans[N]; // Declare a boolean array to store the result for each element
    
    // Read the heights of the elements into the array H
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        ans[i] = true; // Initialize all elements in the boolean array ans to true
    }
    
    // Read the pairs of indices (temp1 and temp2) and compare the heights at these indices
    for (int i = 0; i < M; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        
        if (H[temp1 - 1] < H[temp2 - 1]) {
            ans[temp1 - 1] = false; // Update the boolean array ans based on the comparison results
        } else if (H[temp1 - 1] > H[temp2 - 1]) {
            ans[temp2 - 1] = false; // Update the boolean array ans based on the comparison results
        } else {
            ans[temp1 - 1] = false; // Update the boolean array ans based on the comparison results
            ans[temp2 - 1] = false; // Update the boolean array ans based on the comparison results
        }
    }
    
    int ans2 = 0; // Declare a counter to count the number of elements in the boolean array ans that are still true
    // Count the number of elements in the boolean array ans that are still true
    for (int i = 0; i < N; i++) {
        if (ans[i]) {
            ans2++; // Increment the counter if the element is still true
        }
    }
    
    cout << ans2 << endl; // Print the count
    
    return 0;
}

