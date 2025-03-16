#include <iostream>
using namespace std;

int main() {
    # Declare variables A and B to hold input values
    A, B = input().split()
    # Initialize ans to count the number of iterations
    ans = 0
    # Initialize out to 1, which will be used in the loop
    out = 1

    # Loop until out is less than B
    while out < B:
        # Decrement out by 1
        out -= 1
        # Increment out by the value of A
        out += A
        # Increment the answer counter for each iteration
        ans += 1

    # Output the final count of iterations
    print(ans)

    # Return 0 to indicate successful execution of the program
    return 0
}

