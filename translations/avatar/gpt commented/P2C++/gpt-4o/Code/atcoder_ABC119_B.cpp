#include <iostream>
#include <string>
#include <vector>

int main() {
    // Read the number of currency inputs from the user
    int N;
    std::cin >> N;
    std::cin.ignore(); // To ignore the newline character after the integer input

    // Create a vector of converted currency values
    std::vector<double> x;

    for (int i = 0; i < N; ++i) {
        std::string input;
        std::getline(std::cin, input);

        // Replace 'JPY' with its equivalent in float and 'BTC' with its equivalent in float
        double value = 0.0;
        if (input.find("JPY") != std::string::npos) {
            value = std::stod(input) * 1.0; // Convert JPY
        } else if (input.find("BTC") != std::string::npos) {
            value = std::stod(input) * 380000.0; // Convert BTC
        }
        
        x.push_back(value);
    }

    // Calculate and print the total sum of the converted currency values
    double total = 0.0;
    for (double amount : x) {
        total += amount;
    }
    
    std::cout << total << std::endl;

    return 0;
}

// <END-OF-CODE>
