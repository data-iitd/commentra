#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Initialize the variable 'n' to read the number of elements in the array 'a'
    int n;
    std::cin >> n;

    // Create a vector 'a' to store the input elements
    std::vector<int> a(n);

    // Read 'n' elements from the standard input and store them in vector 'a'
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Initialize an empty vector 'b' to store the unique elements
    std::vector<int> b;

    // Iterate through each element 'v' in vector 'a'
    for (const int& v : a) {
        // Use 'std::lower_bound' to find the index 'x' where 'v' should be inserted in vector 'b'
        auto it = std::lower_bound(b.begin(), b.end(), v);

        // If 'it' is at the end of vector 'b', it means 'v' is not present in the vector, so append it
        if (it == b.end()) {
            b.push_back(v);
        } else {
            // Otherwise, replace the element at index 'x' in vector 'b' with 'v'
            *it = v;
        }
    }

    // Print the length of vector 'b' as the output
    std::cout << b.size() << std::endl;

    // End of the code
    return 0;
}
