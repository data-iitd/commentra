#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    
    int lista[n];
    int listb[n]; // Assuming listb is needed for some purpose, though not used in the original code.
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &listb[i]);
    }
    
    for (int k = 0; k < n; k++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (k + 1 == lista[j]) {
                found = 1;
                break;
            }
        }
        if (found) {
            printf("1 ");
        } else {
            printf("2 ");
        }
    }
    
    return 0;
}

// <END-OF-CODE>
