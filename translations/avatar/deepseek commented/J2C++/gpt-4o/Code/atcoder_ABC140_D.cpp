#include <iostream> // For input and output
#include <string>   // For string manipulation
#include <algorithm> // For std::max
using namespace std;

int main() {
    int N, K; // Declare variables for N and K
    cin >> N >> K; // Read the integers N and K
    string S; // Declare a string S
    cin >> S; // Read the string S

    string c1 = S; // Copy S to c1
    string c3 = S; // Copy S to c3

    bool flag = false; // A flag to indicate whether we are flipping
    int count = 0; // A counter for the number of flips

    // Process c1 (Left to Right)
    for (int i = 0; i < N; i++) {
        if (flag && c1[i] == 'R') { // If we are flipping and encounter 'R'
            flag = false; // Reset the flag
            count++; // Increment the flip count
        }
        if (count == K) { // If we have made K flips, break out of the loop
            break;
        }
        if (c1[i] == 'L') { // If we encounter 'L'
            flag = true; // Set the flag to true
            c1[i] = 'R'; // Flip it to 'R'
        }
    }

    flag = false; // Reset the flag
    count = 0; // Reset the flip count

    // Process c3 (Right to Left)
    for (int i = 0; i < N; i++) {
        if (flag && c3[i] == 'L') { // If we are flipping and encounter 'L'
            flag = false; // Reset the flag
            count++; // Increment the flip count
        }
        if (count == K) { // If we have made K flips, break out of the loop
            break;
        }
        if (c3[i] == 'R') { // If we encounter 'R'
            flag = true; // Set the flag to true
            c3[i] = 'L'; // Flip it to 'L'
        }
    }

    int sum1 = 0; // Initialize sum for c1
    count = 1; // Initialize count for consecutive characters
    char bef = c1[0]; // Initialize the previous character

    // Count consecutive characters in c1
    for (int i = 1; i < N; i++) {
        if (c1[i] == bef) { // If the current character is the same as the previous
            count++; // Increment the count
            if (i == N - 1) { // If it's the last character in the string
                sum1 += count - 1; // Add the count minus one to the sum
            }
        } else { // If the current character is different
            bef = c1[i]; // Update the previous character
            sum1 += count - 1; // Add the count minus one to the sum
            count = 1; // Reset the count
        }
    }

    int sum3 = 0; // Initialize sum for c3
    count = 1; // Reset count for consecutive characters
    bef = c3[0]; // Initialize the previous character

    // Count consecutive characters in c3
    for (int i = 1; i < N; i++) {
        if (c3[i] == bef) { // If the current character is the same as the previous
            count++; // Increment the count
            if (i == N - 1) { // If it's the last character in the string
                sum3 += count - 1; // Add the count minus one to the sum
            }
        } else { // If the current character is different
            bef = c3[i]; // Update the previous character
            sum3 += count - 1; // Add the count minus one to the sum
            count = 1; // Reset the count
        }
    }

    // Print the maximum of the two sums
    cout << max(sum1, sum3) << endl;

    return 0; // End of the program
}

// <END-OF-CODE>
