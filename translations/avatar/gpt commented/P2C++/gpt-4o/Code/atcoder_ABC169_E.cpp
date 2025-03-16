#include <iostream>
#include <vector>
#include <algorithm>

void resolve() {
    // Read the number of intervals
    int n;
    std::cin >> n;

    // Initialize vectors to store the lower and upper bounds of the intervals
    std::vector<int> low;
    std::vector<int> high;

    // Read each interval and store the lower and upper bounds
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        low.push_back(a);  // Append the lower bound to the low vector
        high.push_back(b); // Append the upper bound to the high vector
    }

    // Sort the lower and upper bounds
    std::sort(low.begin(), low.end());
    std::sort(high.begin(), high.end());

    // Check if the number of intervals is odd
    if (n % 2) {
        // For odd number of intervals, calculate the range of the median interval
        std::cout << high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1 << std::endl;
    } else {
        // For even number of intervals, calculate the average of the two middle values
        double hh = (high[n / 2 - 1] + high[n / 2]) / 2.0; // Average of the two middle high values
        double ll = (low[n / 2 - 1] + low[n / 2]) / 2.0;   // Average of the two middle low values
        // Calculate the range and print the result
        std::cout << static_cast<int>((hh - ll) * 2) + 1 << std::endl;
    }
}

// Entry point of the program
int main() {
    resolve();
    return 0;
}

// <END-OF-CODE>
