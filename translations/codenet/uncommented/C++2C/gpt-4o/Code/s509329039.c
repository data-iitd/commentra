#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOR(i,b,e) for(int i=(b);i<(e);++i)

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int s[m], c[m];
    FOR(i, 0, m) {
        scanf("%d %d", &s[i], &c[i]);
        s[i]--; // Adjusting for 0-based index
    }
    
    FOR(i, 0, 1000) {
        char st[4]; // To hold numbers from 0 to 999 (3 digits + null terminator)
        sprintf(st, "%03d", i); // Format number to 3 digits
        
        if (strlen(st) != n) {
            continue;
        }
        
        int f = 1;
        FOR(j, 0, m) {
            if (st[s[j]] == c[j] + '0') {
                // Do nothing, condition satisfied
            } else {
                f = 0; // Condition not satisfied
                break; // No need to check further
            }
        }
        
        if (f) {
            printf("%d\n", i);
            return 0;
        }
    }
    
    printf("-1\n");
    return 0;
}

// <END-OF-CODE>
