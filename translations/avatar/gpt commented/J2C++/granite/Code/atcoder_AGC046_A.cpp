
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <cmath> 
#include <cstdio> 
#include <queue> 
#include <stack> 
#include <set> 
#include <map> 
#include <bitset> 
#include <cstdlib> 
#include <utility> 
#include <functional> 
#include <cctype> 
#include <cassert> 

using namespace std; 

int main() { 
    // Create a FastReader object to read input efficiently
    FastReader sc; 
    // Create a PrintWriter object to output results
    PrintWriter pw; 
    // Read an integer input from the user
    int x = sc.nextInt(); 
    // Initialize a counter to keep track of the number of rotations
    int count = 0; 
    // Store the original value of x for later use
    int tmp = x; 
    // Reset x to 0 for the rotation calculation
    x = 0; 
    // Loop until x completes a full rotation (360 degrees)
    while (x!= 360) { 
        // Increment x by the original input value
        x = x + tmp; 
        // If x exceeds 360, wrap it around by subtracting 360
        if (x > 360) { 
            x = x - 360; 
        } 
        // Increment the count of rotations
        count++; 
    } 
    // Output the total number of rotations needed to reach 360 degrees
    cout << count << endl; 
    return 0; 
} 

// FastReader class for efficient input reading
class FastReader { 
public: 
    FastReader() { 
        // Initialize the input stream
        cin.tie(0)->sync_with_stdio(0); 
    } 
    // Method to read the next token as a String
    string next() { 
        // Continue reading until there are more tokens available
        string str; 
        cin >> str; 
        return str; 
    } 
    // Method to read the next token as an integer
    int nextInt() { 
        // Continue reading until there are more tokens available
        int num; 
        cin >> num; 
        return num; 
    } 
    // Method to read the next token as a long
    long nextLong() { 
        // Continue reading until there are more tokens available
        long num; 
        cin >> num; 
        return num; 
    } 
    // Method to read the next token as a double
    double nextDouble() { 
        // Continue reading until there are more tokens available
        double num; 
        cin >> num; 
        return num; 
    } 
    // Method to read the next line as a String
    string nextLine() { 
        // Continue reading until there are more tokens available
        string str; 
        getline(cin, str); 
        return str; 
    } 
};

The above C++ code is translated from the given Java code. The FastReader class is also included for efficient input reading. The code reads an integer input from the user, calculates the total number of rotations needed to reach 360 degrees, and outputs the result.