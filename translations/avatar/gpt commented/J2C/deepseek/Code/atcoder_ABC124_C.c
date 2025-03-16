#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

void solve(char* x) {
    int a1 = 0, a2 = 0;
    int n = strlen(x);
    
    // First pass: modify 'a' from left to right
    for (int i = 1; i < n; i++) {
        if (x[i] == x[i - 1]) {
            x[i] = x[i] == '1' ? '0' : '1';
            a1++;
        }
    }
    
    // Second pass: modify 'b' from right to left
    for (int i = n - 1; i > 0; i--) {
        if (x[i] == x[i - 1]) {
            x[i - 1] = x[i - 1] == '1' ? '0' : '1';
            a2++;
        }
    }
    
    // Output the minimum number of changes made in either pass
    printf("%d\n", min(a1, a2));
}

int main() {
    char x[100001];
    scanf("%s", x);
    solve(x);
    return 0;
}
