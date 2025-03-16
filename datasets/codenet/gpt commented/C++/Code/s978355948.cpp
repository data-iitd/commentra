#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Declare variables for the number of elements (N) and the threshold value (X)
    int N, X;
    
    // Read the values of N and X from standard input
    cin >> N >> X;
    
    // Initialize a vector L of size N to store the elements
    vector<int> L(N);
    
    // Read N elements into the vector L
    for(int i = 0; i < N; i++)
        cin >> L[i];
    
    // Initialize index variable and a variable to accumulate the sum
    int i;
    int d = 0;
    
    // Iterate through the elements of the vector L
    for(i = 0; i < N; i++) {
        // Accumulate the sum of elements
        d = d + L[i];
        
        // Check if the accumulated sum exceeds the threshold X
        if(d > X)
            break; // Exit the loop if the sum exceeds X
    }

    // Output the number of elements processed before exceeding X
    cout << i + 1 << endl; // i + 1 because we want to count the number of elements
}
