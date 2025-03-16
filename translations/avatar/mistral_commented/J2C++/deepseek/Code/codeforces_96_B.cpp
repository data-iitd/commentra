#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    // Initialize variables for input and output
    long long number;
    long long ans = -1, value = 0;
    int mask = 2;

    // Read a long number as input
    cin >> number;

    // Main loop to find the answer
    while (value < number) {
        // Convert mask to binary string and remove leading '1'
        string s = bitset<32>(mask++).to_string().substr(1);

        // Count the number of zeros in the binary string
        int zeros = 0;
        for (char c : s)
            if (c == '0') zeros++;

        // If the number of zeros is not equal to the length of the binary string minus the number of zeros, continue to the next iteration
        if (zeros != s.length() - zeros) continue;

        // Replace all zeros with '4' and all ones with '7' in the binary string
        for (char &c : s)
            c = (c == '0') ? '4' : '7';

        // Convert the modified binary string back to a long number and update the value variable
        value = stoll(s);
    }

    // Print the answer
    cout << value << endl;

    return 0;
}

