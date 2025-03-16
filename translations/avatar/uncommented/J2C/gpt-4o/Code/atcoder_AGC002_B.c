#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int red; // Using int for boolean representation (0 for false, 1 for true)
} Box;

void moveTo(Box* self, Box* other) {
    if (self->num == 0) {
        return;
    } else if (self->num == 1) {
        self->num = 0;
        other->num++;
        if (self->red) {
            other->red = 1; // Set red to true
        }
        self->red = 0; // Set red to false
    } else {
        self->num--;
        other->num++;
        if (self->red) {
            other->red = 1; // Set red to true
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    Box* B = (Box*)malloc(N * sizeof(Box));
    B[0].num = 1;
    B[0].red = 1; // true
    for (int i = 1; i < N; i++) {
        B[i].num = 1;
        B[i].red = 0; // false
    }
    
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        moveTo(&B[x - 1], &B[y - 1]); // Adjusting for 0-based index
    }
    
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (B[i].red) {
            counter++;
        }
    }
    
    printf("%d\n", counter);
    
    free(B); // Free allocated memory
    return 0;
}

// <END-OF-CODE>
