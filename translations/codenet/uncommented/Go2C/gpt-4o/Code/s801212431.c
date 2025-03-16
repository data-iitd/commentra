#include <stdio.h>
#include <string.h>

int min(int x, int y) {
    return (x < y) ? x : y;
}

int main() {
    char S[100000]; // Assuming the maximum length of S is 100000
    scanf("%s", S);

    int l0 = 0, l1 = 0;
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == '0') {
            l0++;
        } else {
            l1++;
        }
    }
    printf("%d\n", 2 * min(l0, l1));

    return 0;
}

// <END-OF-CODE>
