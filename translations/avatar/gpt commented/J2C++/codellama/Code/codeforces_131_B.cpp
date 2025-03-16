#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    int n; // Declare variable to store the number of integers to process
    long cnt[21]; // Declare an array to count occurrences of integers in the range [-10, 10]
    long res; // Declare variable to store the final result
    
    // Read the number of integers to process
    cin >> n;
    
    // Initialize the array to count occurrences of integers in the range [-10, 10]
    for (int i = 0; i < 21; i++) {
        cnt[i] = 0;
    }
    
    // Loop to read n integers and count their occurrences
    for (int i = 0; i < n; i++) {
        // Increment the count for the input integer adjusted by +10 to handle negative values
        cnt[cin.nextInt() + 10]++;
    }
    
    // Calculate the number of pairs (i, 20 - i) where i ranges from 0 to 9
    for (int i = 0; i < 10; i++) {
        // Multiply the counts of i and (20 - i) and add to the result
        res += cnt[i] * cnt[20 - i];
    }
    
    // Add the number of pairs of the integer 10 (i.e., combinations of 10 taken 2 at a time)
    res += (cnt[10] * (cnt[10] - 1)) / 2;
    
    // Output the final result
    cout << res << endl;
    
    return 0;
}

