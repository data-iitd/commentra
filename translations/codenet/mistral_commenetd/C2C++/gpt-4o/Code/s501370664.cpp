#include <iostream>
#include <vector>

// Declare a flag vector to keep track of prime numbers
std::vector<int> flag;

// Function to find prime numbers up to a given limit
void prime(int num) {
    // Resize the flag vector to size num+1 and initialize with 0
    flag.resize(num + 1, 0);

    // Loop through numbers from 2 to sqrt(num)
    for (int i = 2; i * i <= num; i++) {
        // If a number is not marked as composite, mark all its multiples as composite
        if (flag[i] == 0) {
            for (int j = 2; i * j <= num; j++) {
                flag[i * j] = 1;
            }
        }
    }
}

int main() {
    int n, cnt;

    // Call prime function to find prime numbers up to 50000
    prime(50000);

    // Loop until user inputs 0
    while (true) {
        // Read user input for number n
        std::cin >> n;
        // Break the loop if user inputs 0
        if (n == 0) {
            break;
        }
        // Initialize cnt to 0
        cnt = 0;
        // Loop through numbers from 2 to square root of n
        for (int i = 2; i * i <= n; i++) {
            // If i and n-i are both prime, increment cnt
            if (!flag[i] && !flag[n - i]) {
                cnt++;
            }
        }
        // Print the result
        std::cout << cnt << std::endl;
    }

    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
