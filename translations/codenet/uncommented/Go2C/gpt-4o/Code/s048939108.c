#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    char S[MAX_LEN];
    fgets(S, sizeof(S), stdin);
    
    // Remove newline character if present
    S[strcspn(S, "\n")] = 0;

    if (strncmp(S, "YAKI", 4) == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
