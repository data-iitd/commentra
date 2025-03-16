
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// This method calculates a result based on a given string and character.
int cal(char *s, char c) { 
    int n = strlen(s); 
    int m = n - 1; 
    int ans = 0; 
    for (int i = 0; i < n; i++) { 
        if (s[i] == c && (m & i) == i) { 
            ans ^= 1; 
        } 
    } 
    return ans; 
} 

// This method is responsible for solving the problem by processing the input and outputting the result.
void solve() { 
    int n; 
    scanf("%d", &n); 
    char s[n]; 
    scanf("%s", s); 
    char sb[n - 1]; 
    for (int i = 1; i < n; i++) { 
        sb[i - 1] = abs(s[i] - s[i - 1]); 
    } 
    if (n == 2) { 
        printf("%c\n", sb[0]); 
        return; 
    } 
    s = sb; 
    if (strstr(s, "1")) { 
        printf("%d\n", cal(s, '1')); 
    } else { 
        printf("%d\n", cal(s, '2') * 2); 
    } 
} 

// The entry point of the program where objects are created and the solve method is called.
int main() { 
    solve(); 
    return 0; 
} 

