#include <iostream>
#include <map>
#include <set>
#include <vector>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

// Include necessary headers: These headers are essential for input/output operations, using maps, sets, and vectors respectively.

// Define a macro for loop: This simplifies the for loop syntax, making the code more readable.

// Namespace usage: The code uses the std namespace to avoid prefixing standard library components with'std::'.

def solve(N, T, M, P, X):
    # Solve function: This function processes the input data to calculate and output the results for each operation.
    REP(i, M) {
        # Loop through operations: For each operation, we calculate a new total time by modifying one dish's time.
        ans = 0;
        REP(j, N) {
            if (j == P[i] - 1) ans += X[i];
            else ans += T[j];
        }
        print(ans);
    }

if __name__ == "__main__":
    # Main function: This is the entry point of the program. It handles input, calls the solve function, and ensures efficient I/O operations.
    N = int(input())
    T = [int(x) for x in input().split()]
    M = int(input())
    P = [int(x) for x in input().split()]
    X = [int(x) for x in input().split()]
    solve(N, T, M, P, X)

