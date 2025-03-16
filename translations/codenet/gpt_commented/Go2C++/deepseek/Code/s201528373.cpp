#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::vector<int> l;

    // Read the number of elements (n) from standard input
    std::cin >> n;
    // Read the threshold value (x) from standard input
    std::cin >> x;

    // Loop to read n integers from standard input and append them to the vector l
    for (int i = 0; i < n; i++) {
        int tmpL;
        // Read each integer and store it in tmpL
        std::cin >> tmpL;
        // Append the read integer to the vector l
        l.push_back(tmpL);
    }

    // Initialize variables to keep track of the cumulative sum (tmpSum) and the result (rs)
    int tmpSum = 0;
    int rs = 0;

    // Loop through the vector l to calculate the cumulative sum and determine the result
    for (int i = 0; i < n; i++) {
        // Add the current value to the cumulative sum
        tmpSum += l[i];

        // If the cumulative sum is less than or equal to x, update the result
        if (tmpSum <= x) {
            rs = i + 2; // Update result to the current index + 2
        } else {
            break; // Exit the loop if the cumulative sum exceeds x
        }
    }

    // Print the final result
    std::cout << rs << std::endl;

    return 0;
}

