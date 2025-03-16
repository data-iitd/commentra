
#include <iostream>                                                                                                                               
#include <map>                                                                                                                                    
using namespace std;                                                                                                                              

// Main function starts here
int main() {
    string str; // Declare a string variable named 'str' to store the input string

    // Read the input string from the standard input
    cin >> str;

    int max = 0, cnt = 0; // Initialize two integer variables 'max' and 'cnt' with zero values

    // Iterate through each character in the input string using a range-based for loop
    for (auto sc : str) {
        // Check if the current character is a valid nucleotide (A, C, G or T)
        if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') {
            cnt++; // Increment the count if the character is a valid nucleotide
        } else { // Otherwise, reset the count to zero
            cnt = 0;
        }

        // Update the maximum count if the current count is greater than the previous maximum
        max = max < cnt ? cnt : max;
    }

    // Print the maximum count of valid nucleotides found in the input string
    cout << max << endl;
}