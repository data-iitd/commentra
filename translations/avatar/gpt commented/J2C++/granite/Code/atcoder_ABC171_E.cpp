
#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <numeric> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <string> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 

using namespace std; 

int main() { 
    // Create a Scanner object to read input from the user
    // Scanner sc(cin); 
    // Read the number of elements in the array
    int n; 
    cin >> n; 
    // Initialize an array to hold the input integers
    vector<int> a(n); 
    // Variable to hold the cumulative XOR of all elements
    int r = 0; 
    // Read each integer from input and compute the cumulative XOR
    for (int i = 0; i < n; i++) { 
        cin >> a[i]; 
        r ^= a[i]; // Update the cumulative XOR with the current element
    } 
    // For each element in the array, print the result of XORing the cumulative XOR with the element
    for (int i = 0; i < n; i++) { 
        if (i!= 0) 
            cout << " "; // Print a space before the next number if it's not the first element
        cout << (r ^ a[i]); // Print the result of XORing the cumulative XOR with the current element
    } 
    // End of code
    return 0; 
}
