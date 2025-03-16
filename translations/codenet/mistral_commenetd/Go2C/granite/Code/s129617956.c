
#include <stdio.h>
#include <math.h>

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

// Function to find the minimum of two integers
int min(int i, int j) {
    // Return the smaller of the two integers
    if (i > j) {
        return j;
    }
    return i;
}

// Initialize variables and calculate the square root of n
int main() {
    // Read an integer from standard input and initialize n and rt variables
    int n, rt, minf;
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

// Function to find the minimum of two integers
int min(int i, int j) {
    // Return the smaller of the two integers
    if (i > j) {
        return j;
    }
    return i;
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    int n, rt, minf;
    scanf("%d", &n);
    rt = (int)sqrt(n);
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility(n, rt, &minf);

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility(int n, int rt, int *minf) {
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
            *minf = min(*minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    int n, rt, minf;
    scanf("%d", &n);
    rt = (int)sqrt(n);
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility(n, rt, &minf);

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility(int n, int rt, int *minf) {
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
            *minf = min(*minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    int n, rt, minf;
    scanf("%d", &n);
    rt = (int)sqrt(n);
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility(n, rt, &minf);

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility(int n, int rt, int *minf) {
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
            *minf = min(*minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    int n, rt, minf;
    scanf("%d", &n);
    rt = (int)sqrt(n);
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility(n, rt, &minf);

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility(int n, int rt, int *minf) {
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
            *minf = min(*minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    int n, rt, minf;
    scanf("%d", &n);
    rt = (int)sqrt(n);
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility(n, rt, &minf);

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility(int n, int rt, int *minf) {
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
            *minf = min(*minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    int n, rt, minf;
    scanf("%d", &n);
    rt = (int)sqrt(n);
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility(n, rt, &minf);

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility(int n, int rt, int *minf) {
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
            *minf = min(*minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    int n, rt, minf;
    scanf("%d", &n);
    rt = (int)sqrt(n);
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility(n, rt, &minf);

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility(int n, int rt, int *minf) {
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
            *minf = min(*minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    int n, rt, minf;
    scanf("%d", &n);
    rt = (int)sqrt(n);
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility(n, rt, &minf);

    // Print the result
    printf("%d\n", minf);

    return 0;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility(int n, int rt, int *minf) {
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
            *minf = min(*minf, ndigit);
        }
    }
}

// Initialize variables and call the checkDivisibility function
int main() {
    // Read an integer from standard input and initialize n variable
    int n, rt, minf;
    scanf("%d", &n);
    rt = (int)sqrt(n);
    minf = 100;

    // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
    checkDivisibility(n, rt, &