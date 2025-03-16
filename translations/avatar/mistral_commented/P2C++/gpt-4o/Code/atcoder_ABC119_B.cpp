#include <iostream>
#include <vector>
#include <string>

int main() {
    // Ask the user for the number of inputs
    int N;
    std::cin >> N;
    std::cin.ignore(); // To ignore the newline character after the integer input

    // Create a vector 'x' to store the values
    std::vector<double> x;

    // Read inputs and convert them
    for (int i = 0; i < N; ++i) {
        std::string input;
        std::getline(std::cin, input);

        // Replace 'JPY' with '* 1.0' and 'BTC' with '* 380000.0'
        double value = 0.0;
        if (input.find("JPY") != std::string::npos) {
            value = std::stod(input.replace(input.find("JPY"), 3, "")) * 1.0;
        } else if (input.find("BTC") != std::string::npos) {
            value = std::stod(input.replace(input.find("BTC"), 3, "")) * 380000.0;
        }

        x.push_back(value);
    }

    // Print the sum of all the elements in the vector 'x'
    double sum = 0.0;
    for (double num : x) {
        sum += num;
    }
    std::cout << sum << std::endl;

    return 0;
}

// <END-OF-CODE>
