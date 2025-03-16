#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int number[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &number[i]);
    }
    
    int h1 = 0, h2 = 0;
    int x = 0;
    
    for (int i = 0; i < n; i++) {
        if (number[i] != 4 && number[i] != 7) {
            printf("NO\n");
            x += 1;
            break;
        }
        if (i < n / 2) {
            h1 += number[i];
        } else {
            h2 += number[i];
        }
    }
    
    if (x == 0) {
        if (h1 == h2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}

// <END-OF-CODE>
