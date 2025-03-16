#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int *c = (int *)malloc(n * sizeof(int));
    int count = 0;
    int has_negative = 0;

    for (int i = 0; i < n; i++) {
        char s[101]; // Assuming the maximum length of the string is 100
        scanf("%s", s);
        
        int posG = -1, posS = -1;
        for (int j = 0; s[j] != '\0'; j++) {
            if (s[j] == 'G') {
                posG = j;
            } else if (s[j] == 'S') {
                posS = j;
            }
        }
        
        if (posG != -1 && posS != -1) {
            int diff = posS - posG;
            if (diff < 0) {
                has_negative = 1;
            } else {
                c[count++] = diff;
            }
        }
    }

    if (has_negative) {
        printf("-1\n");
    } else {
        printf("%d\n", count);
    }

    free(c);
    return 0;
}

// <END-OF-CODE>
