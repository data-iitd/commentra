#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

int main() {
    // Declare and initialize a constant integer
    const int num = 998244353;

    // Read the number of elements 'n' from the input
    int n;
    std::cin >> n;

    // Create two std::vector objects to store the pairs of integers
    std::vector<int> ai;
    std::vector<int> bi;

    // Read the pairs of integers from the input and store them in the std::vector objects
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        ai.push_back(a);
        bi.push_back(b);
    }

    // Sort both the std::vector objects
    std::sort(ai.begin(), ai.end());
    std::sort(bi.begin(), bi.end());

    // Check if 'n' is odd or even
    if (n % 2 == 1) {
        // If 'n' is odd, calculate the range by subtracting the middle element of 'bi' from the middle element of 'ai' and add 1
        std::cout << bi[bi.size() / 2] - ai[ai.size() / 2] + 1 << std::endl;
    } else {
        // If 'n' is even, calculate the range by averaging the middle elements of 'ai' and 'bi' and multiply by 2, then add 1
        double b = (ai[ai.size() / 2] + ai[ai.size() / 2 - 1]) / 2.0;
        double c = (bi[bi.size() / 2] + bi[bi.size() / 2 - 1]) / 2.0;
        std::cout << std::fixed << std::setprecision(0) << 2 * (c - b) + 1 << std::endl;
    }

    return 0;
}
