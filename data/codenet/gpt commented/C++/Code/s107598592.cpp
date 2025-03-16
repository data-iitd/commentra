#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() { 
    // Read the number of elements
    int N; 
    cin >> N;

    // Initialize two vectors to store the input values
    vector<int> X(N); 
    vector<int> Y(N);
    
    // Read input values into vector X and copy them to vector Y
    for(int i = 0; i < N; i++) { 
        cin >> X[i]; 
        Y[i] = X[i]; 
    }
  
    // Sort vector Y to find the median
    sort(Y.begin(), Y.end());
  
    // Find the median value (middle element for odd N, or lower middle for even N)
    int y = Y[N/2];
    
    // Output the appropriate median value for each element in X
    for(int i = 0; i < N; i++) {
        // If the current element in X is less than the median
        if (X[i] < Y[N/2]) {
            cout << Y[N/2]; // Output the upper median
        } else {
            cout << Y[N/2 - 1]; // Output the lower median
        }
        cout << endl; // Print a newline after each output
    }
    
    return 0; // End of the program
}
