#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COLORS 256

int main() {
    char bought[MAX_COLORS];
    char made[MAX_COLORS];
    int bought_count[MAX_COLORS] = {0};
    int made_count[MAX_COLORS] = {0};
    
    // Read the bought colors
    fgets(bought, sizeof(bought), stdin);
    for (int i = 0; bought[i] != '\0' && bought[i] != '\n'; i++) {
        bought_count[(unsigned char)bought[i]]++;
    }

    // Read the made colors
    fgets(made, sizeof(made), stdin);
    for (int i = 0; made[i] != '\0' && made[i] != '\n'; i++) {
        made_count[(unsigned char)made[i]]++;
    }

    int res = 0;
    for (int i = 0; i < MAX_COLORS; i++) {
        if (made_count[i] > 0) {
            if (bought_count[i] == 0) {
                printf("-1\n");
                return 0;
            }
            res += (bought_count[i] < made_count[i]) ? bought_count[i] : made_count[i];
        }
    }
    
    printf("%d\n", res);
    return 0;
}

// <END-OF-CODE>
