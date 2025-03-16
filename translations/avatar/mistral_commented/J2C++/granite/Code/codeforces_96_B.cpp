

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Initialize variables for answer and current value
    long long ans = -1, value = 0;

    // Initialize mask variable for binary number manipulation
    int mask = 2;

    // Main loop to find the answer
    while (value < number) {
        // Convert mask to binary string and remove leading '1'
        string s = bitset<64>(mask++).to_string().substr(1);

        // Count the number of zeros in the binary string
        int zeros = 0;
        for (char c : s)
            if (c == '0') zeros++;

        // If the number of zeros is not equal to the length of the binary string minus the number of zeros, continue to the next iteration
        if (zeros!= s.length() - zeros) continue;

        // Replace all zeros with '4' and all ones with '7' in the binary string
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '0') s[i] = '4';
            else s[i] = '7';

        // Convert the modified binary string back to a long number and update the value variable
        value = stoll(s);
    }

    // Print the answer
    cout << value << endl;

    return 0;
}

This code should be self-explanatory. Let me know if you need any further clarification or modification.