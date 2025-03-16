#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

int main() {
    // Your C++ code here
    std::string input;
    std::getline(std::cin, input);
    std::vector<char> arr(input.begin(), input.end());
    int N = arr.size();

    std::unordered_set<std::string> set;

    int K;
    std::cin >> K;
    std::cin.ignore(); // To ignore the newline character after reading K

    int res = 0;

    for (int k = 0; k < K; ++k) {
        std::string input;
        std::getline(std::cin, input);

        int a = 0, b = 0;

        for (int i = 0; i < N; ++i) {
            if (arr[i] == input[0])
                ++a;
            else if (arr[i] == input[1])
                ++b;
            else {
                res += std::min(a, b);
                a = b = 0;
            }
        }

        res += std::min(a, b);
    }

    std::cout << res << std::endl;

    return 0;
}
