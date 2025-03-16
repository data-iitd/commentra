#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int red; // Using int for boolean representation (0 for false, 1 for true)
} Box;

void moveTo(Box* current, Box* other) {
    if (current->num == 0) {
        return; // Do nothing if the box is already empty
    } else if (current->num == 1) {
        current->num = 0; // Set the current box to empty
        other->num++; // Increment the destination box's number
        if (current->red) {
            other->red = 1; // If the current box was red, make the destination box red
        }
        current->red = 0; // The current box is no longer red
    } else {
        current->num--; // Decrement the current box's number
        other->num++; // Increment the destination box's number
        if (current->red) {
            other->red = 1; // If the current box was red, make the destination box red
        }
    }
}

int main() {
    int N, M;
    scanf("%d", &N); // Read the number of boxes
    scanf("%d", &M); // Read the number of moves

    Box* B = (Box*)malloc(N * sizeof(Box));
    B[0].num = 1;
    B[0].red = 1; // Initialize the first box with num=1 and red=true

    for (int i = 1; i < N; i++) {
        B[i].num = 1;
        B[i].red = 0; // Initialize the rest of the boxes with num=1 and red=false
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y); // Read the source and destination box indices (1-based)
        moveTo(&B[x - 1], &B[y - 1]); // Move the box from source to destination
    }

    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (B[i].red) {
            counter++; // Count the number of red boxes
        }
    }

    printf("%d\n", counter); // Print the count of red boxes

    free(B); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
