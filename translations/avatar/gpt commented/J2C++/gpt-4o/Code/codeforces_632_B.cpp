#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Create a variable to read input
    int n;
    
    // Read the number of elements in the array
    cin >> n;
    
    // Initialize a vector to hold the integer values
    vector<int> a(n);
    
    // Populate the vector with input values
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
        char ch = s[i];
        if (ch == 'B') 
            sum += a[i]; // Add the value to sum if the character is 'B'
    }
    
    // Store the initial sum as the maximum answer found so far
    long long ans = sum;
    long long sum1 = sum;
    
    // Iterate through the string to calculate the maximum possible sum
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') 
            sum1 += a[i]; // Increase sum1 if the character is 'A'
        else 
            sum1 -= a[i]; // Decrease sum1 if the character is not 'A'
        
        // Update the maximum answer if the current sum1 is greater
        ans = max(ans, sum1);
    }
    
    // Reset sum1 to the initial sum for the next calculation
    sum1 = sum;
    
    // Iterate through the string in reverse to calculate the maximum possible sum
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == 'A') 
            sum1 += a[i]; // Increase sum1 if the character is 'A'
        else 
            sum1 -= a[i]; // Decrease sum1 if the character is not 'A'
        
        // Update the maximum answer if the current sum1 is greater
        ans = max(ans, sum1);
    }
    
    // Output the maximum sum found
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
