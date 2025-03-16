
#include <stdio.h>

int main() {
    int firstline;
    scanf("%d", &firstline);

    int total = 0;
    char memory[firstline];
    int i;
    for (i = 0; i < firstline; i++) {
        int A, G;
        scanf("%d %d", &A, &G);

        if (total + A <= 500) {
            total += A;
            memory[i] = 'A';
        } else {
            total -= G;
            memory[i] = 'G';
        }
    }

    memory[i] = '\0';
    printf("%s\n", memory);

    return 0;
}
// END-OF-CODE