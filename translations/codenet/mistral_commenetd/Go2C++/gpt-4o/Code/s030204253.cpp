// Include necessary headers
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Initialize an integer variable 'n' and read its value from the standard input
    int n;
    std::cin >> n;

    // Create a vector 'a' of 'n' float elements
    std::vector<double> a(n);

    // Read 'n' float values from the standard input and assign them to the vector 'a'
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Sort the vector 'a'
    std::sort(a.begin(), a.end());

    // Initialize an empty vector 'na' of double
    std::vector<double> na;

    // Iterate through the vector 'a' starting from index 2 and append its elements to the vector 'na'
    for (size_t j = 2; j < a.size(); j++) {
        na.push_back(a[j]);
    }

    // Append the average of the first two elements of the original vector 'a' to 'na'
    na.push_back((a[0] + a[1]) / 2);

    // Reassign the value of the vector 'a' with the vector 'na'
    a = na;

    // Print the first element of the sorted vector 'a' to the standard output
    std::cout << a[0] << std::endl;

    return 0;
}

// <END-OF-CODE>
