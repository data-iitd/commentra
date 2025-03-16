#include <stdio.h>
#include <string.h>

int N;

// Define a function named `aaa` that takes an argument `n`
int aaa(char *n) {
    // Check if the integer value of `n` is greater than N. If it is, return 0
    if (atoi(n) > N) {
        return 0;
    }
    
    // Check if the digits of `n` are '7', '5', and '3'. If they are, set `ans` to 1; otherwise, set `ans` to 0
    int ans = 1;
    for (int i = 0; i < strlen(n); i++) {
        if (n[i] != '7' && n[i] != '5' && n[i] != '3') {
            ans = 0;
            break;
        }
    }
    
    // Iterate over the string '753' and recursively call the function `aaa` with `n` incremented by each digit
    for (int i = 0; i < 3; i++) {
        char next[10];
        strcpy(next, n);
        next[strlen(n)] = '7' + i;
        ans += aaa(next);
    }
    
    // Return the value of `ans`
    return ans;
}

int main() {
    // Take an integer input N
    scanf("%d", &N);
    
    // Call the function `aaa` with the initial argument '0' and print the result
    printf("%d\n", aaa("0"));
    
    return 0;
}

