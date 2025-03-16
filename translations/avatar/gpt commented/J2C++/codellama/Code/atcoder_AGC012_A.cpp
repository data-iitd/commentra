
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    // Creating a Scanner object to read input from the console
    int n;
    cin >> n;
    
    // Initializing an array of size 3*n to hold the input values
    int array[3 * n];
    
    // Filling the array with user input values
    for (int i = 0; i < 3 * n; i++) {
        cin >> array[i];
    }
    
    // Sorting the array in ascending order
    sort(array, array + 3 * n);
    
    // Setting the head pointer to the second last element of the sorted array
    int head = 3 * n - 2;
    
    // Initializing a variable to accumulate the result
    long res = 0;
    
    // Looping n times to sum up the required elements from the sorted array
    for (int i = 0; i < n; i++) {
        res += array[head]; // Adding the current element pointed by head to the result
        head -= 2; // Moving the head pointer two positions to the left for the next iteration
    }
    
    // Printing the final result
    cout << res << endl;
    
    return 0;
}

