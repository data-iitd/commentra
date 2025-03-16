#include <stdio.h>

int main() {
    int firstline, total = 0;
    int A, G;
    char memory[500];
    scanf("%d", &firstline);
    for (int x = 0; x < firstline; x++) {
        scanf("%d %d", &A, &G);
        if (total + A <= 500) {
            total += A;
            memory[x] = 'A';
        } else {
            total -= G;
            memory[x] = 'G';
        }
    }
    memory[firstline] = '\0'; // Null-terminate the string
    printf("%s\n", memory);
    return 0;
}
