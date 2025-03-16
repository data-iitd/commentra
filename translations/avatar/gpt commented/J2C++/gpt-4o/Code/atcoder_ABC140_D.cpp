#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Read the integer N (length of the string) and K (number of changes allowed)
    int N, K;
    cin >> N >> K;

    // Read the string S
    string S;
    cin >> S;

    // Create two copies of the string for manipulation
    string c1 = S;
    string c3 = S;

    // Initialize a flag to track changes and a count for 'R' occurrences
    bool flag = false;
    int count = 0;

    // First pass: Change 'L' to 'R' up to K times
    for (int i = 0; i < N; i++) {
        // If the flag is set and the current character is 'R', increment count and reset flag
        if (flag && c1[i] == 'R') {
            flag = false;
            count++;
        }
        // Break the loop if K changes have been made
        if (count == K) {
            break;
        }
        // If the current character is 'L', set the flag and change 'L' to 'R'
        if (c1[i] == 'L') {
            flag = true;
            c1[i] = 'R';
        }
    }

    // Reset flag and count for the second pass
    flag = false;
    count = 0;

    // Second pass: Change 'R' to 'L' up to K times
    for (int i = 0; i < N; i++) {
        // If the flag is set and the current character is 'L', increment count and reset flag
        if (flag && c3[i] == 'L') {
            flag = false;
            count++;
        }
        // Break the loop if K changes have been made
        if (count == K) {
            break;
        }
        // If the current character is 'R', set the flag and change 'R' to 'L'
        if (c3[i] == 'R') {
            flag = true;
            c3[i] = 'L';
        }
    }

    // Initialize variables to count consecutive characters in c1
    count = 1;
    int sum1 = 0;
    char bef = c1[0];

    // Count the number of consecutive characters in c1
    for (int i = 1; i < N; i++) {
        if (c1[i] == bef) {
            count++;
            // If it's the last character, add the count to sum1
            if (i == N - 1) {
                sum1 += count - 1;
            }
        } else {
            bef = c1[i];
            sum1 += count - 1;
            count = 1;
        }
    }

    // Reset count and initialize variables to count consecutive characters in c3
    count = 1;
    int sum3 = 0;
    bef = c3[0];

    // Count the number of consecutive characters in c3
    for (int i = 1; i < N; i++) {
        if (c3[i] == bef) {
            count++;
            // If it's the last character, add the count to sum3
            if (i == N - 1) {
                sum3 += count - 1;
            }
        } else {
            bef = c3[i];
            sum3 += count - 1;
            count = 1;
        }
    }

    // Output the maximum of the two sums calculated from c1 and c3
    cout << max(sum1, sum3) << endl;

    return 0;
}

// <END-OF-CODE>
