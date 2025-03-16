#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007L
#define N 1000000000L
#define TOKENS "ACGT"

typedef struct {
    int N ; 
    long MOD ; 
    char* TOKENS ; 
    long** memo ; 
} Main ; 

// Constructor initializes N and sets up memoization array
Main* new_Main() {
    Main* ins = (Main*) malloc(sizeof(Main)) ; 
    ins->N = N ; 
    ins->MOD = MOD ; 
    ins->TOKENS = TOKENS ; 
    ins->memo = (long**) malloc(sizeof(long*) * (ins->N + 1)) ; 
    for (int i = 0 ; i < ins->memo[0] ; ++i) {
        ins->memo[i] = (long*) malloc(sizeof(long) * (ins->N + 1)) ; 
    }
    return ins ; 
}

// Method to calculate the number of valid sequences
long calc(Main* ins) {
    return dfs(ins, 0, "TTT") ; 
}

// Method to check if the last four characters form a valid sequence
int isOK(Main* ins, char* last4) {
    if (strstr(last4, "AGC")) {
        return 0 ; 
    }
    for (int i = 0 ; i < 3 ; ++i) {
        char* vals = (char*) malloc(sizeof(char) * 4) ; 
        strcpy(vals, last4) ; 
        vals[i] = last4[i + 1] ; 
        vals[i + 1] = last4[i] ; 
        if (strstr(vals, "AGC")) {
            return 0 ; 
        }
    }
    return 1 ; 
}

// Recursive method to count valid sequences using memoization
long dfs(Main* ins, int current, char* last3) {
    if (ins->memo[current][last3[0]] != 0) {
        return ins->memo[current][last3[0]] ; 
    }
    if (current == ins->N) {
        return 1 ; 
    }
    long result = 0 ; 
    for (int i = 0 ; i < 4 ; ++i) {
        if (isOK(ins, last3 + i)) {
            result = (result + dfs(ins, current + 1, last3 + i)) % MOD ; 
        }
    }
    ins->memo[current][last3[0]] = result ; 
    return result ; 
}

// Main method to run the program
int main(int argc, char** argv) {
    Main* ins = new_Main() ; 
    printf("%ld\n", calc(ins)) ; 
    return 0 ; 
}

