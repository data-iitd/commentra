#include <iostream>
#include <vector>
#include <algorithm>

void resolve() {
    // Read the number of pairs
    int n;
    std::cin >> n;

    // Initialize vectors to store the lower and higher values of each pair
    std::vector<int> low;
    std::vector<int> high;

    // Loop to read each pair and append values to the vectors
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        low.push_back(a);
        high.push_back(b);
    }

    // Sort the vectors
    std::sort(low.begin(), low.end());
    std::sort(high.begin(), high.end());

    // Check if the number of pairs is odd or even
    if (n % 2) {
        // If odd, calculate the range between the middle elements
        std::cout << high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1 << std::endl;
    } else {
        // If even, calculate the average of the middle elements and print the range
        double hh = (high[n / 2 - 1] + high[n / 2]) / 2.0;
        double ll = (low[n / 2 - 1] + low[n / 2]) / 2.0;
        std::cout << static_cast<int>((hh - ll) * 2) + 1 << std::endl;
    }
}

// Call the resolve function when the script is executed
int main() {
    resolve();
    return 0;
}

// <END-OF-CODE>
