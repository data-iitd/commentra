#include <iostream>  // Include input/output stream
#include <string>    // Include string class
#include <vector>    // Include vector for dynamic array

int main() {
    int n, taro = 0, hanako = 0;  // Declare number of rounds, scores
    std::cin >> n;  // Read the number of rounds

    std::vector<std::string> t(n);  // Create a vector for Tarō's strings
    std::vector<std::string> h(n);  // Create a vector for Hanako's strings

    // Loop through each round
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];  // Read Tarō's string
        std::cin >> h[i];  // Read Hanako's string
        if (t[i] < h[i]) hanako += 3;  // Compare and update Hanako's score
        if (t[i] > h[i]) taro += 3;    // Compare and update Tarō's score
        if (t[i] == h[i]) {  // If strings are equal
            taro += 1;  // Increment Tarō's score by 1
            hanako += 1;  // Increment Hanako's score by 1
        }
    }

    std::cout << taro << " " << hanako << std::endl;  // Print the final scores
    return 0;  // Return 0 to indicate successful execution
}  // <END-OF-CODE>
