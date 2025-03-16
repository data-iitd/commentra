#include <iostream>
#include <map>
#include <set>
#include <vector>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

// Include necessary headers: These headers are essential for input/output operations, using maps, sets, and vectors respectively.

// Define a macro for loop: This simplifies the for loop syntax, making the code more readable.

// Namespace usage: The code uses the std namespace to avoid prefixing standard library components with 'std::'.

void solve(long long N, std::vector<long long> T, long long M, std::vector<long long> P, std::vector<long long> X){
    // Solve function: This function processes the input data to calculate and output the results for each operation.
    REP(i, M) {
        // Loop through operations: For each operation, we calculate a new total time by modifying one dish's time.
        long long ans = 0;
        REP(j, N) {
            if (j == P[i] - 1) ans += X[i];
            else ans += T[j];
        }
        System.out.println(ans);
    }
}

public class Main {
    public static void main(String[] args) {
        // Main function: This is the entry point of the program. It handles input, calls the solve function, and ensures efficient I/O operations.
        Scanner sc = new Scanner(System.in);
        long long N = sc.nextLong();
        std::vector<long long> T(N);
        REP(i, N) T[i] = sc.nextLong();
        long long M = sc.nextLong();
        std::vector<long long> P(M);
        std::vector<long long> X(M);
        REP(i, M) {
            P[i] = sc.nextLong();
            X[i] = sc.nextLong();
        }
        solve(N, std::move(T), M, std::move(P), std::move(X));
    }
}

