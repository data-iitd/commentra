
#include <iostream>
#include <string>

int main() {
    int n;  // Step 1: Take an integer input `n`
    std::string number;  // Step 1: Take a string `number`
    std::cin >> n >> number;

    int h1 = 0;  // Step 2: Initialize `h1` to store the sum of the first half of the digits
    int h2 = 0;  // Step 2: Initialize `h2` to store the sum of the second half of the digits
    int x = 0;  // Step 3: Initialize `x` to check for invalid digits

    // Step 4: Enter a for loop to iterate over each digit in the number
    for (int i = 0; i < n; i++) {
        if (number[i]!= '4' && number[i]!= '7') {  // Step 5: Check if the current digit is invalid
            std::cout << "NO" << std::endl;  // Step 5: Print "NO" and break the loop if an invalid digit is found
            x = 1;  // Step 5: Set `x` to 1
            break;  // Step 5: Break out of the loop
        }
        if (i < n / 2) {  // Step 6: Add the digit to `h1` if it's in the first half
            h1 += number[i] - '0';
        } else {  // Step 6: Add the digit to `h2` if it's in the second half
            h2 += number[i] - '0';
        }
    }

    // Step 7: After the loop, check if `x` is still 0 and compare the sums of the first and second halves
    if (!x) {  // Step 7: Check if no invalid digit was found
        if (h1 == h2) {  // Step 7: Check if the sums are equal
            std::cout << "YES" << std::endl;  // Step 7: Print "YES" if the sums are equal
        } else {  // Step 7: Print "NO" if the sums are not equal
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
