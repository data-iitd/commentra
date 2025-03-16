#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    char input[100]; // Assuming the input will not exceed 100 characters
    scanf("%s", input);
    
    int sa = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '-') {
            sa++;
        }
    }
    
    sa = (n - sa < sa) ? (n - sa) : sa;
    
    char ss[m]; // To store the results
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        b -= a;
        
        if (b % 2 && b <= (sa << 1)) {
            ss[i] = '1';
        } else {
            ss[i] = '0';
        }
    }
    
    for (int i = 0; i < m; i++) {
        printf("%c\n", ss[i]);
    }
    
    return 0;
}

// <END-OF-CODE>
