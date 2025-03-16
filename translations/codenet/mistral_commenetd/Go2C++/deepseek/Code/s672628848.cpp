#include <iostream>
#include <vector>

int main() {
    // Declare variables a, b, c, d, and e of type int
    int a, b, c, d, e;

    // Read input values for variables a, b, c, d, and e from the standard input
    std::cin >> a >> b >> c >> d >> e;

    // Create a vector named al with the values of variables a, b, c, d, and e
    std::vector<int> al = {a, b, c, d, e};

    // Iterate through each element i in the vector al starting from the index 0
    for (int n = 0; n < al.size(); ++n) {
        // Check if the current element i is equal to 0
        if (al[n] == 0) {
            // Print the index number n+1 as output
            std::cout << n + 1 << std::endl;
            // Break the loop as soon as the first zero element is found
            break;
        }
    }

    return 0;
}
