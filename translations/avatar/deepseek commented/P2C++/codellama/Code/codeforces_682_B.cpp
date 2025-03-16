
#include <iostream>  // Importing necessary libraries
#include <array>  // Importing array module
#include <math.h>  // Importing math module

using namespace std;  // Using standard namespace

// Define input functions
int* I() {  // Read a list of integers
    int n;
    cin >> n;
    int* l = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    return l;
}

string IS() {  // Read a single string
    string s;
    cin >> s;
    return s;
}

int IN() {  // Read an integer
    int n;
    cin >> n;
    return n;
}

float IF() {  // Read a float
    float n;
    cin >> n;
    return n;
}

// Main function
int main() {
    // Read the number of elements
    int n = IN();

    // Read the list of elements
    int* l = I();

    // Initialize variables
    int f = 1;  // Flag variable
    sort(l, l + n);  // Sort the list
    int c = 0;  // Counter variable

    // Iterate through the list to find the maximum number of unique elements
    for (int i = 0; i < n; i++) {
        if (l[i] > c) {
            c += 1;  // Increment the counter if the current element is greater than the counter
        }
    }

    // Print the result
    cout << c + 1 << endl;  // Print the maximum number of unique elements

    return 0;
}

