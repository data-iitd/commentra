#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int n;
    std::cin >> n;
    int c = 0;

    for (int i = 0; i < n; ++i) {
        std::vector<int> l1;
        int num;
        while (std::cin.peek() != '\n' && std::cin >> num) {
            l1.push_back(num);
        }
        std::cin.ignore(); // Ignore the newline character after the input

        if (std::accumulate(l1.begin(), l1.end(), 0) > 1) {
            c++;
        }
    }

    std::cout << c << std::endl;
    return 0;
}

// <END-OF-CODE>
