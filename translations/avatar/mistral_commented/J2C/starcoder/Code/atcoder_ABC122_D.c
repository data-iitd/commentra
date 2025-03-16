
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 100000
#define MAX_S 100000

typedef struct {
    char c ;
    int count ;
} Token ;

typedef struct {
    char s[MAX_S] ;
    int n ;
} Input ;

typedef struct {
    char s[MAX_S] ;
    int n ;
} Output ;

typedef struct {
    char s[MAX_S] ;
    int n ;
} Memo ;

Token tokens[4] = {
    { 'A', 0 },
    { 'C', 0 },
    { 'G', 0 },
    { 'T', 0 }
} ;

Input input[MAX_N] ;
Output output[MAX_N] ;
Memo memo[MAX_N][4] ;

int isOK(char *last4) {
    if (strstr(last4, "AGC")!= NULL) {
        return 0 ;
    }

    for (int i = 0 ; i < 3 ; ++i) {
        char tmp[4] = { last4[i], last4[i+1], '\0' } ;
        if (strstr(last4, tmp)!= NULL) {
            return 0 ;
        }
    }

    return 1 ;
}

int dfs(int current, char *last3) {
    if (memo[current][0].n > 0) {
        return memo[current][0].count ;
    }

    if (current == input[0].n) {
        memo[current][0].n = 1 ;
        memo[current][0].count = 1 ;
        return 1 ;
    }

    int result = 0 ;

    for (int i = 0 ; i < 4 ; ++i) {
        if (tokens[i].count == 0) {
            continue ;
        }

        if (isOK(strcat(last3, tokens[i].c))) {
            result = (result + dfs(current+1, strcat(last3+1, tokens[i].c))) % MOD ;
        }
    }

    memo[current][0].n = 1 ;
    memo[current][0].count = result ;
    return result ;
}

int main(int argc, char **argv) {
    int n ;
    scanf("%d", &n) ;
    for (int i = 0 ; i < n ; ++i) {
        scanf("%d", &input[i].n) ;
        scanf("%s", input[i].s) ;
    }

    for (int i = 0 ; i < n ; ++i) {
        output[i].count = dfs(0, input[i].s) ;
    }

    for (int i = 0 ; i < n ; ++i) {
        printf("%d\n", output[i].count) ;
    }

    return 0 ;
}

