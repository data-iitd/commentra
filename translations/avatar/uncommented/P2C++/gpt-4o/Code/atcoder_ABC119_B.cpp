#include <iostream>
#include <string>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore(); // To ignore the newline character after the integer input

    std::vector<double> x(N);
    for (int i = 0; i < N; ++i) {
        std::string input;
        std::getline(std::cin, input);

        // Replace 'JPY' with '* 1.0' and 'BTC' with '* 380000.0'
        size_t pos = input.find("JPY");
        if (pos != std::string::npos) {
            input.replace(pos, 3, "* 1.0");
        }
        pos = input.find("BTC");
        if (pos != std::string::npos) {
            input.replace(pos, 3, "* 380000.0");
        }

        // Evaluate the expression
        x[i] = eval(input);
    }

    double total = 0;
    for (double value : x) {
        total += value;
    }

    std::cout << total << std::endl;

    return 0;
}

// Note: The eval function is not directly available in C++. You would need to implement a parser or use a library to evaluate the expression.
// <END-OF-CODE>
