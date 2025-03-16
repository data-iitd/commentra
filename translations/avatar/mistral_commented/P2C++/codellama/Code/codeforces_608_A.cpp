#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Declaring and initializing the variables n, s, f, t, x, and c
    int n, s, f, t, x, c = 0;
    
    // Reading the first line of input and storing the number of test cases and the target sum in variables n and s
    cin >> n >> s;
    
    // Iterating through the test cases using a for loop
    for (int i = 0; i < n; i++) {
        // Reading the start and end time of each activity from the input
        cin >> f >> t;
        
        // Calculating the difference between the end time and the difference between the target sum and start time
        x = t - (s - f);
        
        // Updating the variable c with the maximum value of x calculated in the current iteration
        if (x > c) {
            c = x;
        }
    }
    
    // Printing the final answer which is the sum of the target sum and the maximum overlap calculated
    cout << s + c << endl;
    
    // Ending the code with a comment "