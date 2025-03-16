#include <iostream>
#include <cmath>

using namespace std;

// Function to read input from standard input in buffer
void read(char *buffer, int size) {
    int i = 0;
    while (i < size) {
        buffer[i] = getchar();
        i++;
    }
}

// Function to read a single line from standard input in buffer
void readline(char *buffer, int size) {
    int i = 0;
    while (i < size) {
        buffer[i] = getchar();
        if (buffer[i] == '\n') {
            break;
        }
        i++;
    }
}

// Function to read multiple lines from standard input in buffer
void readlines(char *buffer, int size) {
    int i = 0;
    while (i < size) {
        buffer[i] = getchar();
        if (buffer[i] == '\n') {
            i++;
            break;
        }
        i++;
    }
}

// Function definition: main function takes three arguments N, d, and x
double main(int N, double d, double x) {
    // Initializing the result variable to 0
    double ret = 0;

    // Loop continues as long as N is greater than 0
    while (N > 0) {
        // Adding the current term to the result
        ret += d + (N - 0.5) * x;

        // Updating the value of d for the next iteration
        d += d / N + (5 * x) / (2 * N);

        // Updating the value of x for the next iteration
        x += 2 * x / N;

        // Decrementing the value of N for the next iteration
        N -= 1;
    }

    // Returning the final result
    return ret;
}

// Calling the main function and printing the result
int main() {
    int N;
    double d, x;
    cin >> N >> d >> x;
    cout << main(N, d, x) << endl;
    return 0;
}

