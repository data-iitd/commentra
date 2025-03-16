#include <iostream>
#include <vector>

int main() {
    // Declare variables to hold the number of elements, the target sum, and the list of integers
    int n, x;
    std::vector<int> l;

    // Read the number of elements and the target sum from the standard input
    std::cin >> n >> x;

    // Read n integers from the standard input and append them to the list l
    for (int i = 0; i < n; i++) {
        int tmpL;
        std::cin >> tmpL;
        l.push_back(tmpL);
    }

    // Initialize variables to keep track of the sum and the result
    int tmpSum = 0;
    int rs = 0;

    // Iterate over the list l, updating the sum and checking the condition
    for (int i = 0; i < l.size(); i++) {
        tmpSum += l[i];
        // If the sum is less than or equal to x, update the result
        if (tmpSum <= x) {
            rs = i + 1; // i + 1 because we want the count of elements
        } else {
            break;
        }
    }

    // Print the result
    std::cout << rs << std::endl;

    return 0;
}

// <END-OF-CODE>
