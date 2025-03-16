/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <stdio.h> // Include standard input-output library

#define mod 998244353 // Define a constant for modulo arithmetic
#define int long long // Define int as long long for large input
#define ld long double // Define ld for long double precision
#define pb push_back // Define pb for pushing back elements in a vector
#define vi int* // Define vi as a pointer to int (for dynamic array)
#define co(x) printf("%lld\n", x) // Define co for printing output
#define dbg(x) fprintf(stderr, "%s = %lld\n", #x, x) // Define dbg for debugging purpose
#define bitcount(x) __builtin_popcountll(x) // Define bitcount for counting set bits
#define sz(x) (sizeof(x) / sizeof(x[0])) // Define sz for getting size of an array
#define all(a) a, a + sizeof(a) / sizeof(a[0]) // Define all for getting pointer to the beginning and end of an array
#define ff first // Not applicable in C
#define ss second // Not applicable in C
#define pii long long // Define pii as long long (pair not directly applicable in C)
#define lcm(a,b) ((a)*(b))/gcd(a,b) // Define lcm for finding least common multiple of two numbers

// Function to compute gcd
long long gcd(long long a, long long b) {
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function declaration for solving the problem
void solve() {
    int n, ans = 0; // Declare variables for taking input and storing answer
    scanf("%lld", &n); // Read input for n
    co(!n); // Print output if n is not positive
}

int main() { // Main function declaration
    int n = 1; // Initialize a variable for number of test cases
    while (n--) solve(); // Call the solve function for each test case
    return 0; // Return 0 to indicate successful execution
}

/* <END-OF-CODE> */
