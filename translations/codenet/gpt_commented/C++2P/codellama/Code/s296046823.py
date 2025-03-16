#include <iostream>
#include <vector>

using namespace std;

int main() {
    # Declare variables N and K to hold the number of elements and the divisor respectively
    N, K = map(int, input().split())

    # Initialize a vector of size N to store the input elements
    v = [0] * N

    # Read N integers from standard input and store them in the vector v
    for i in range(N):
        v[i] = int(input())

    # Calculate the number of groups needed based on the formula ceil((N-1) / (K-1))
    # This is done using integer arithmetic to avoid floating-point operations
    count = ((N - 1) + ((K - 1) - 1)) // (K - 1)

    # Output the calculated count of groups
    print(count)
}

