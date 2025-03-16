#include <iostream> // For input and output
#include <vector>   // For using vectors
#include <algorithm> // For sorting

int main() {
    // Creating a variable to read the number of elements in the array
    int n;
    std::cin >> n;

    // Initializing a vector of size n
    std::vector<int> a(n);

    // Loop to read n integers from the user and store them in the vector
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Sorting the vector in ascending order
    std::sort(a.begin(), a.end());

    // Loop to check the condition for adjacent elements in the sorted vector
    for (int i = 0; i < a.size() - 1; i++) {
        // Checking if the next element is less than double the current element
        // and ensuring they are not equal
        if (a[i + 1] < a[i] * 2 && a[i] != a[i + 1]) {
            // If the condition is met, print "YES" and exit the program
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    // If no such pair is found, print "NO"
    std::cout << "NO" << std::endl;

    return 0;
}

// <END-OF-CODE>
