
#include <iostream> // Including the standard input/output stream objects
#include <algorithm> // Including the algorithm library for using std::sort

int main() {
    // Creating a stream object to read input from the console
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    
    // Reading the integer n which determines the size of the array
    int n;
    std::cin >> n;
    
    // Initializing an array of size 3*n to hold the input values
    int array[3 * n];
    
    // Filling the array with user input values
    for (int i = 0; i < 3 * n; i++) {
        std::cin >> array[i];
    }
    
    // Sorting the array in ascending order
    std::sort(array, array + 3 * n);
    
    // Setting the head pointer to the second last element of the sorted array
    int head = 3 * n - 2;
    
    // Initializing a variable to accumulate the result
    long long res = 0;
    
    // Looping n times to sum up the required elements from the sorted array
    for (int i = 0; i < n; i++) {
        res += array[head]; // Adding the current element pointed by head to the result
        head -= 2; // Moving the head pointer two positions to the left for the next iteration
    }
    
    // Printing the final result
    std::cout << res << std::endl;
    
    return 0;
}
