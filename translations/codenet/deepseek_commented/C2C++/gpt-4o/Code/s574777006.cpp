#include <iostream>  // Include the iostream header for input-output
#include <vector>    // Include the vector header for using vectors

int main() {
    int n, q, sum = 0;  // Declare variables
    std::cin >> n;  // Read the number of elements

    std::vector<int> x(n);  // Create a vector x of size n
    for(int i = 0; i < n; i++) {
        std::cin >> x[i];  // Read the elements of vector x
    }

    std::cin >> q;  // Read the number of queries
    std::vector<int> y(q);  // Create a vector y of size q
    for(int i = 0; i < q; i++) {
        std::cin >> y[i];  // Read the elements of vector y
    }

    for(int i = 0; i < q; i++) {  // For each query
        for(int j = 0; j < n; j++) {  // Check each element in vector x
            if(y[i] == x[j]) {  // If the query matches an element in x
                sum++;  // Increment the sum
                break;  // Break out of the inner loop
            }
        }
    }

    std::cout << sum << std::endl;  // Print the sum of matches

    return 0;  // Return 0 to indicate successful execution
}  // <END-OF-CODE>
