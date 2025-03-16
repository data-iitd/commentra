#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the number of elements in the array
    int n;
    cin >> n;
    
    // Initialize an array to hold the integer values
    int a[n];
    
    // Populate the array with input values
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Read the string input which consists of characters 'A' and 'B'
    string s;
    cin >> s;
    
    // Initialize a variable to hold the sum of values corresponding to 'B'
    long long sum = 0;
    
    // Calculate the initial sum based on the positions of 'B' in the string
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'B') {
            sum += a[i];
        }
    }
    
    // Store the initial sum as the maximum answer found so far
    long long ans = sum;
    long long sum1 = sum;
    
    // Iterate through the string to calculate the maximum possible sum
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') {
            sum1 += a[i];
        } else {
            sum1 -= a[i];
        }
        
        // Update the maximum answer if the current sum1 is greater
        ans = max(ans, sum1);
    }
    
    // Reset sum1 to the initial sum for the next calculation
    sum1 = sum;
    
    // Iterate through the string in reverse to calculate the maximum possible sum
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == 'A') {
            sum1 += a[i];
        } else {
            sum1 -= a[i];
        }
        
        // Update the maximum answer if the current sum1 is greater
        ans = max(ans, sum1);
    }
    
    // Output the maximum sum found
    cout << ans << endl;
}

