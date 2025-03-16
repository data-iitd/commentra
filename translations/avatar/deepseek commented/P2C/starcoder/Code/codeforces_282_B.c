
#include <stdio.h>
#include <stdlib.h>

int main() {
    int firstline, total, A, G;
    char *memory;
    scanf("%d", &firstline);
    total = 0;
    memory = (char *)malloc(firstline * sizeof(char));
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
    printf("%s", memory);
    return 0;
}

