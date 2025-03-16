#include <iostream>
#include <map>
#include <set>
#include <vector>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

#include <iostream>
#include <map>
#include <set>
#include <vector>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

void solve(long long N, std::vector<long long> T, long long M, std::vector<long long> P, std::vector<long long> X){
    // Solve function: This function processes the input data to calculate and output the results for each operation.
    REP(i, M) {
        // Loop through operations: For each operation, we calculate a new total time by modifying one dish's time.
        long long ans = 0;
        REP(j, N) {
            if (j == P[i] - 1) ans += X[i];
            else ans += T[j];
        }
        print(ans)
    }
}

int main(){
    // Main function: This is the entry point of the program. It handles input, calls the solve function, and ensures efficient I/O operations.
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long N;
    cin >> N;
    std::vector<long long> T(N);
    REP(i, N) cin >> T[i];
    long long M;
    cin >> M;
    std::vector<long long> P(M);
    std::vector<long long> X(M);
    REP(i, M) cin >> P[i] >> X[i];
    solve(N, std::move(T), M, std::move(P), std::move(X));
    return 0;
}


