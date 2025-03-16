#include <stdio.h>

<<<<<<< HEAD
void solve(long long N, long long T[], long long M, long long P[], long long X[]) {
    // Iterate over each modification request
    for (long long i = 0; i < M; i++) {
        long long ans = 0; // Initialize the answer for the current modification
        // Calculate the total time considering the current modification
        for (long long j = 0; j < N; j++) {
=======
#define REP(i, n) for (int i = 0; i < (n); i++)

// Function to solve the problem based on the given parameters
void solve(long long N, long long T[], long long M, long long P[], long long X[]) {
    // Iterate over each modification request
    REP(i, M) {
        long long ans = 0; // Initialize the answer for the current modification
        // Calculate the total time considering the current modification
        REP(j, N) {
>>>>>>> 98c87cb78a (data updated)
            // If the current index matches the modified position, add the new time value
            if (j == P[i] - 1) ans += X[i];
            // Otherwise, add the original time value
            else ans += T[j];
        }
        // Output the result for the current modification
        printf("%lld\n", ans);
    }
}

int main() {
    long long N; // Number of original time values
    scanf("%lld", &N); // Read the number of time values
    long long T[N]; // Array to store the original time values
<<<<<<< HEAD
    for (long long i = 0; i < N; i++) scanf("%lld", &T[i]); // Read the original time values into the array
=======
    REP(i, N) scanf("%lld", &T[i]); // Read the original time values into the array
>>>>>>> 98c87cb78a (data updated)

    long long M; // Number of modifications
    scanf("%lld", &M); // Read the number of modifications
    long long P[M]; // Array to store the positions of modifications
    long long X[M]; // Array to store the new time values for modifications
<<<<<<< HEAD
    for (long long i = 0; i < M; i++) scanf("%lld %lld", &P[i], &X[i]); // Read the modification positions and new time values
=======
    REP(i, M) scanf("%lld %lld", &P[i], &X[i]); // Read the modification positions and new time values
>>>>>>> 98c87cb78a (data updated)

    // Call the solve function to process the modifications and output results
    solve(N, T, M, P, X);
    return 0; // Indicate successful completion of the program
}

// <END-OF-CODE>
