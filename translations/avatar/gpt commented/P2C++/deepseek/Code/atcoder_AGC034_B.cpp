#include <iostream>
#include <string>

// Function to compute the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    // Ensure a is the larger and b is the smaller number
    if (a < b) {
        std::swap(a, b);
    }
    // Use the Euclidean algorithm to find GCD
    while (a % b != 0) {
        a = a % b;
        std::swap(a, b);
    }
    return b;
}

// Main function to solve the problem
void solve() {
    // Read input string
    std::string s;
    std::cin >> s;
    std::string t = "";  // Initialize an empty string to build the result
    int i = 0;   // Initialize index for traversing the input string

    // Process the input string character by character
    while (i < s.length()) {
        if (s[i] == 'A') {
            // If the character is 'A', add it to the result
            t += "A";
            i++;  // Move to the next character
        } else if (s[i] == 'B') {
            // If the character is 'B', check the next character
            if (i < s.length() - 1) {
                if (s[i + 1] == 'C') {
                    // If the next character is 'C', add 'D' to the result
                    t += "D";
                    i += 2;  // Skip the next character as well
                } else {
                    // If the next character is not 'C', add 'X' to the result
                    t += "X";
                    i++;  // Move to the next character
                }
            } else {
                // If 'B' is the last character, add 'X' to the result
                t += "X";
                i++;
            }
        } else {
            // For any other character, add 'X' to the result
            t += "X";
            i++;
        }
    }

    int total = 0;  // Initialize total count
    int numA = 0;   // Initialize count of 'A's encountered

    // Calculate the total based on the processed string
    for (int i = 0; i < t.length(); i++) {
        if (t[i] == 'X') {
            // Reset count of 'A's when 'X' is encountered
            numA = 0;
        } else {
            if (t[i] == 'A') {
                // Increment count of 'A's
                numA++;
            } else {
                // If the character is not 'A', add the count of 'A's to total
                total += numA;
            }
        }
    }

    // Print the final total
    std::cout << total << std::endl;
}

// Entry point of the program
int main() {
    solve();
    return 0;
}
