#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the integer N (length of the string) and K (number of changes allowed)
    int N, K;
    cin >> N >> K;
    
    // Read the string S
    string S;
    cin >> S;
    
    // Initialize a flag to track changes and a count for 'R' occurrences
    bool flag = false;
    int count = 0;
    
    // First pass: Change 'L' to 'R' up to K times
    for (int i = 0; i < N; i++) {
        // If the flag is set and the current character is 'R', increment count and reset flag
        if (flag && S[i] == 'R') {
            flag = false;
            count++;
        }
        // Break the loop if K changes have been made
        if (count == K) {
            break;
        }
        // If the current character is 'L', set the flag and change 'L' to 'R'
        if (S[i] == 'L') {
            flag = true;
            S[i] = 'R';
        }
    }
    
    // Reset flag and count for the second pass
    flag = false;
    count = 0;
    
    // Second pass: Change 'R' to 'L' up to K times
    for (int i = 0; i < N; i++) {
        // If the flag is set and the current character is 'L', increment count and reset flag
        if (flag && S[i] == 'L') {
            flag = false;
            count++;
        }
        // Break the loop if K changes have been made
        if (count == K) {
            break;
        }
        // If the current character is 'R', set the flag and change 'R' to 'L'
        if (S[i] == 'R') {
            flag = true;
            S[i] = 'L';
        }
    }
    
    // Initialize variables to count consecutive characters in S1
    int sum1 = 0;
    char bef = S[0];
    int count = 1;
    
    // Count the number of consecutive characters in S1
    for (int i = 1; i < N; i++) {
        if (S[i] == bef) {
            count++;
            // If it's the last character, add the count to sum1
            if (i == N - 1) {
                sum1 += count - 1;
            }
        } else {
            bef = S[i];
            sum1 += count - 1;
            count = 1;
        }
    }
    
    // Initialize variables to count consecutive characters in S3
    int sum3 = 0;
    bef = S[0];
    count = 1;
    
    // Count the number of consecutive characters in S3
    for (int i = 1; i < N; i++) {
        if (S[i] == bef) {
            count++;
            // If it's the last character, add the count to sum3
            if (i == N - 1) {
                sum3 += count - 1;
            }
        } else {
            bef = S[i];
            sum3 += count - 1;
            count = 1;
        }
    }
    
    // Output the maximum of the two sums calculated from S1 and S3
    cout << max(sum1, sum3) << endl;
}

