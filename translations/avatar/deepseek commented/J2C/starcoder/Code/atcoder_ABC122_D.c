#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define N 100000
#define TOKENS "ACGT"

typedef struct {
    char last3[4] ; 
    long count ; 
} memo_t ; 

int N ; 
long memo[N][4] ; 

// Method to calculate the number of valid sequences
long calc() {
    return dfs(0, "TTT") ; 
}

// Method to check if the last four characters form a valid sequence
int isOK(char last4[]) {
    if (strstr(last4, "AGC")) {
        return 0 ; 
    }
    for (int i = 0 ; i < 3 ; ++i) {
        char tmp = last4[i] ; 
        last4[i] = last4[i + 1] ; 
        last4[i + 1] = tmp ; 
        if (strstr(last4, "AGC")) {
            return 0 ; 
        }
    }
    return 1 ; 
}

// Recursive method to count valid sequences using memoization
long dfs(int current, char last3[]) {
    if (memo[current][0]!= 0) {
        return memo[current][0] ; 
    }
    if (current == N) {
        return 1 ; 
    }
    long result = 0 ; 
    for (int i = 0 ; i < 4 ; ++i) {
        char c = TOKENS[i] ; 
        if (isOK(last3 + c)) {
            result = (result + dfs(current + 1, last3 + c)) % MOD ; 
        }
    }
    memo[current][0] = result ; 
    return result ; 
}

// Main method to run the program
int main(int argc, char** argv) {
    N = atoi(argv[1]) ; 
    printf("%ld\n", calc()) ; 
    return 0 ; 
}

