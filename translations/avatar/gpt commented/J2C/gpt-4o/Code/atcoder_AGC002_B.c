#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int num;      // Number of items in the box
    bool red;     // Indicates if the box is red
} Box;

// Function to move items from one box to another
void moveTo(Box* from, Box* to) {
    // If the from box is empty, do nothing
    if (from->num == 0) {
        return;
    }
    // If the from box has one item, transfer it to the to box
    else if (from->num == 1) {
        from->num = 0;
        to->num++;
        // If the from box is red, the to box becomes red
        if (from->red) {
            to->red = true;
        }
        from->red = false; // The from box is no longer red
    }
    // If the from box has more than one item, transfer one item to the to box
    else {
        from->num--;
        to->num++;
        // If the from box is red, the to box becomes red
        if (from->red) {
            to->red = true;
        }
    }
}

int main() {
    // Read the number of boxes (N) and the number of moves (M)
    int N, M;
    scanf("%d %d", &N, &M);

    // Allocate memory for an array of Box objects
    Box* B = (Box*)malloc(N * sizeof(Box));

    // Create the first box as red and the rest as not red
    B[0].num = 1;
    B[0].red = true;
    for (int i = 1; i < N; i++) {
        B[i].num = 1;
        B[i].red = false;
    }

    // Process M moves based on user input
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        // Move the contents from box x to box y (adjusting for 0-based index)
        moveTo(&B[x - 1], &B[y - 1]);
    }

    // Count the number of red boxes after all moves
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (B[i].red) {
            counter++;
        }
    }

    // Output the count of red boxes
    printf("%d\n", counter);

    // Free allocated memory
    free(B);

    return 0;
}

// <END-OF-CODE>
