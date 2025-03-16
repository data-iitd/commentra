#include <iostream>
#include <string>
#include <vector>

int main() {
    // Define a constant for infinity
    const long long INF = 1e15;
    
    // Create a string to read input
    std::string number;
    
    // Read the input number as a string
    std::cin >> number;
    
    // Create a vector to store the digits of the number
    std::vector<int> digits(number.length() + 1);
    
    // Convert the number into a vector of digits
    for (size_t i = 0; i < number.length(); i++) {
        digits[i] = number[number.length() - 1 - i] - '0';
    }
    
    // Initialize the total bill to 0
    int bills = 0;
    
    // Loop through each digit to calculate the total bill
    for (size_t i = 0; i <= number.length(); i++) {
        // Handle the case where the digit is 10
        if (digits[i] == 10) {
            digits[i + 1]++;
            digits[i] = 0;
        }
        
        // Add the digit to the bill if it is less than 5
        if (digits[i] < 5) {
            bills += digits[i];
        }
        // Handle the case where the digit is 5
        else if (digits[i] == 5) {
            if (digits[i + 1] >= 5) {
                digits[i + 1]++;
            }
            bills += 5;
        }
        // Handle the case where the digit is greater than 5
        else {
            digits[i + 1]++;
            bills += 10 - digits[i];
        }
    }
    
    // Print the total bill
    std::cout << bills << std::endl;
    
