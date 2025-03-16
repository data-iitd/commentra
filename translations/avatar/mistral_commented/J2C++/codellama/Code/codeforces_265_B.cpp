// Include the necessary header files for file I/O and collections
#include <iostream>
#include <vector>

// Define the main function, which is the entry point of the program
int main() {

    // Create a Scanner object to read input from the standard input
    std::cin >> n;

    // Create an integer array arr of size n
    std::vector<int> arr(n);

    // Use a for loop to read n integers from the standard input and store them in the array arr
    for (int i = 0; i < arr.size(); i++) {
        std::cin >> arr[i]; // Read the next integer and store it in the current index of the array
    }

    // Initialize a variable ans with the first element of the array and add 1 to it
    int ans = arr[0] + 1;

    // Use another for loop to iterate through the remaining elements of the array arr
    for (int i = 1; i < arr.size(); i++) {
        // Calculate the absolute difference between the current and previous elements and add it to the variable ans along with 2
        ans += abs(arr[i] - arr[i - 1]) + 2;
    }

    // Finally, print the value of ans to the standard output
    std::cout << ans << std::endl;

    return 0;
}

