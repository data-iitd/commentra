#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> // setprecisionを使用するのに必要 cout << fixed << setprecision(15) << p でpを小数点以下15桁表示
using namespace std;
#define REPD(i, a, b) for (int i = (a); i < (b); ++i) // Macro for a for loop
#define REP(i, n) REPD(i, 0, n) // Macro for a for loop with range n
typedef long long ll;
#define fin(ans) cout << (ans) << '\n' // Macro to print the final answer

// Main function starts here
int main()
{
    // Initialize variables
    ll N, K;
    ll A[200100];
    ll B[200100] = {-1};
    int now = 1;
    ll cnt = 0;

    // Read input values
    cin >> N >> K;

    // Read array A
    REP(i, N) {
        cin >> A[i + 1];
    }

    // Initialize B array with -1
    REP(i, 200100) {
        B[i] = -1;
    }

    // B[1] is always 0
    B[1] = 0;

    // Simulation of the algorithm
    ll j;
    for (j = 1; j <= K; j++) {
        // Move to the next node
        now = A[now];

        // If the node has not been reached yet, update B[now]
        if (B[now] == -1) {
            B[now] = j;
        } else {
            // If the node has already been reached, calculate the answer
            cnt = j;
            break;
        }
    }

    // If the simulation has not reached the end, calculate the answer
    if (j < K) {
        ll tmp;
        tmp = (K - B[now]) % (cnt - B[now]);

        // Move to the final node
        for (ll j = 0; j < tmp; j++) {
            now = A[now];
        }
    }

    // Print the answer
    fin(now);

    return 0;
}
