#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

class Scanner {
public:
    Scanner() {
        std::cin.tie(nullptr);
        std::ios::sync_with_stdio(false);
    }

    int NextInt() {
        int v;
        std::cin >> v;
        return v;
    }
};

int main() {
    Scanner sc; // Initialize a new Scanner instance

    int n = sc.NextInt(); // Read an integer n from the standard input
    double ans = 0.0; // Initialize a variable ans to 0.0
    for (int i = 0; i < n; i++) { // Enter a loop that runs n times
        int tmpInt = sc.NextInt(); // Read an integer
        double tmp = 1.0 / static_cast<double>(tmpInt); // Divide 1 by this value
        ans += tmp; // Add this result to ans
    }
    std::cout << std::fixed << std::setprecision(10) << 1.0 / ans << std::endl; // Calculate the reciprocal of ans and print it

    return 0;
}

// <END-OF-CODE>
