
// Include necessary header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// Uncomment the following lines to include Boost multiprecision libraries
/*
#include<boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/rational.hpp>
namespace mp = boost::multiprecision;
using Real = mp::number<mp::cpp_dec_float<1024>>;
using Bint = mp::cpp_int;
*/

// Define long long as int for convenience
#define int long long

// Macros for loop iterations
#define REP(i,s,e) for((i)=(s);(i)<(e);(i)++)
#define RREP(i,s,e) for((i)=((s)-1);(i)>=(e);(i)--)
#define FOR(i,n) for((i)=(0);(i)<(n);(i)++)
#define RFOR(i,n) for((i)=((n)-1);(i)>=(0);(i)--)

// Define a constant for modulo operation
#define MOD 1000000007

int main() {
    // Declare a vector to store strings and variables for input
    char** v;
    int N, L;

    // Read the number of strings (N) and the length of strings (L)
    scanf("%lld %lld", &N, &L);

    // Allocate memory for N strings and store them in the vector
    v = (char**)malloc(sizeof(char*) * N);
    for(int i = 0; i < N; i++) {
        v[i] = (char*)malloc(sizeof(char) * (L + 1));
        scanf("%s", v[i]);
    }

    // Sort the vector of strings in lexicographical order
    qsort(v, N, sizeof(char*), cmp);

    // Output the sorted strings
    for(int i = 0; i < N; i++) {
        printf("%s", v[i]); // Print each string in the sorted order
    }
    printf("\n"); // Print a newline at the end

    // Free the allocated memory
    for(int i = 0; i < N; i++) {
        free(v[i]);
    }
    free(v);

    return 0;
}

