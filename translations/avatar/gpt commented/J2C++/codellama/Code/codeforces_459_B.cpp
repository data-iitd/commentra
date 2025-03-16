#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

int main() { 
    // Read the number of elements from input
    int N; 
    cin >> N; 
    
    // Initialize an array to hold the input integers
    vector<int> A(N); 
    
    // Read N integers from input and store them in the array A
    for (int n = 0; n < N; n++) { 
        cin >> A[n]; 
    } 
    
    // Sort the array A to easily find the minimum and maximum values
    sort(A.begin(), A.end()); 
    
    // Identify the minimum and maximum values in the sorted array
    int min = A[0]; 
    int max = A[N - 1]; 
    
    // Initialize counters for occurrences of min and max values
    long mins = 0; 
    long maxs = 0; 
    
    // Count how many times the minimum and maximum values occur in the array
    for (int value : A) { 
        if (value == min) mins++; 
        if (value == max) maxs++; 
    } 
    
    // If all elements are the same (min equals max)
    if (min == max) { 
        // Calculate the difference (which is 0) and the number of ways to choose 2 from mins
        cout << (max - min) << " " << mins * (mins - 1) / 2 << endl; 
    } else { 
        // Calculate the difference and the product of occurrences of min and max
        cout << (max - min) << " " << mins * maxs << endl; 
    } 
    
    return 0; 
} 

// Debugging method to print objects in a readable format
void debug(const vector<int>& obj) { 
    cerr << obj << endl; 
} 

