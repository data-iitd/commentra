#include <iostream> 
#include <cmath> 

using namespace std; 

int main() { 
    // Read a long integer N from user input
    long N; 
    cin >> N; 
    
    // Initialize a variable to hold the minimum value
    long min = 0; 
    
    // Loop to read five long integers and find the minimum
    for (int i = 0; i < 5; i++) {
        // For the first iteration, directly assign the value to min
        if (i == 0) {
            cin >> min; 
        } else {
            // For subsequent iterations, update min if a smaller value is found
            long temp; 
            cin >> temp; 
            min = min < temp ? min : temp; 
        }
    }
    
    // Calculate the result by dividing N by min, rounding up, and adding 4
    cout << (long) ceil((double) N / min) + 4 << endl; 
    
    return 0; 
}

