#include <stdio.h>
#include <string.h>

void solve(const char *x) {
    int a1 = 0, a2 = 0;
    int len = strlen(x);
    char a[len + 1], b[len + 1];
    
    strcpy(a, x);
    strcpy(b, x);
    
    for (int i = 1; i < len; i++) {
        if (a[i] == a[i - 1]) {
            a[i] = (a[i] == '1') ? '0' : '1';
            a1++;
        }
    }
    
    for (int i = len - 1; i > 0; i--) {
        if (b[i] == b[i - 1]) {
            b[i - 1] = (b[i - 1] == '1') ? '0' : '1';
            a2++;
        }
    }
    
    printf("%d\n", (a1 < a2) ? a1 : a2);
}

int main() {
    char x[100001]; // Assuming the maximum length of x is 100000
    scanf("%s", x);
    solve(x);
    return 0;
}

// <END-OF-CODE>
