

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    // Initialize variables
    int n, rt, minf;

    // Read an integer from standard input and initialize n, rt, and minf variables
    scanf("%d", &n);
    rt = (int)sqrt(n);
    minf = 100;

    // Check divisibility for numbers from 1 to the square root of n
    for (int i = 1; i <= rt; i++) {
        // Check if n is divisible by i
        if (n % i == 0) {
            // Calculate the number of digits in the divisor
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            // Update minimum factor if a divisor with fewer digits is found
            minf = min(minf, ndigit);
        }
    }

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
    int rt = (int)sqrt(n);
    for (int i = 1; i <= rt; i++) {
        if (n % i == 0) {
            // Calculate the number of digits in the divisor
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            // Update minimum factor if a divisor with fewer digits is found
            minf = min(minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    scanf("%d", &n);

    // Initialize minimum factor with a large value
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility();

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
    int rt = (int)sqrt(n);
    for (int i = 1; i <= rt; i++) {
        if (n % i == 0) {
            // Calculate the number of digits in the divisor
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            // Update minimum factor if a divisor with fewer digits is found
            minf = min(minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    scanf("%d", &n);

    // Initialize minimum factor with a large value
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility();

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
    int rt = (int)sqrt(n);
    for (int i = 1; i <= rt; i++) {
        if (n % i == 0) {
            // Calculate the number of digits in the divisor
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            // Update minimum factor if a divisor with fewer digits is found
            minf = min(minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    scanf("%d", &n);

    // Initialize minimum factor with a large value
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility();

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
    int rt = (int)sqrt(n);
    for (int i = 1; i <= rt; i++) {
        if (n % i == 0) {
            // Calculate the number of digits in the divisor
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            // Update minimum factor if a divisor with fewer digits is found
            minf = min(minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    scanf("%d", &n);

    // Initialize minimum factor with a large value
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility();

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
    int rt = (int)sqrt(n);
    for (int i = 1; i <= rt; i++) {
        if (n % i == 0) {
            // Calculate the number of digits in the divisor
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            // Update minimum factor if a divisor with fewer digits is found
            minf = min(minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    scanf("%d", &n);

    // Initialize minimum factor with a large value
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility();

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
    int rt = (int)sqrt(n);
    for (int i = 1; i <= rt; i++) {
        if (n % i == 0) {
            // Calculate the number of digits in the divisor
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            // Update minimum factor if a divisor with fewer digits is found
            minf = min(minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    scanf("%d", &n);

    // Initialize minimum factor with a large value
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility();

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
    int rt = (int)sqrt(n);
    for (int i = 1; i <= rt; i++) {
        if (n % i == 0) {
            // Calculate the number of digits in the divisor
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            // Update minimum factor if a divisor with fewer digits is found
            minf = min(minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    scanf("%d", &n);

    // Initialize minimum factor with a large value
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility();

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
    int rt = (int)sqrt(n);
    for (int i = 1; i <= rt; i++) {
        if (n % i == 0) {
            // Calculate the number of digits in the divisor
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            // Update minimum factor if a divisor with fewer digits is found
            minf = min(minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    scanf("%d", &n);

    // Initialize minimum factor with a large value
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility();

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
    int rt = (int)sqrt(n);
    for (int i = 1; i <= rt; i++) {
        if (n % i == 0) {
            // Calculate the number of digits in the divisor
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++
            }
            // Update minimum factor if a divisor with fewer digits is found
            minf = min(minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    scanf("%d", &n);

    // Initialize minimum factor with a large value
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility();

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
    int rt = (int)sqrt(n);
    for (int i = 1; i <= rt; i++) {
        if (n % i == 0) {
            // Calculate the number of digits in the divisor
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++
            }
            // Update minimum factor if a divisor with fewer digits is found
            minf = min(minf, ndigit)
        }
    }
}

// Initialize v