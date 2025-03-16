#include <iostream>

int main() {
    # Declare variables to hold input values
    N, A = 0, 0

    # Read an integer value for N from standard input
    N = int(input())

    # Read an integer value for A from standard input
    A = int(input())

    # Calculate the result by squaring N and subtracting A, then output the result
    print(N * N - A)

    return 0 # Indicate that the program ended successfully
}
