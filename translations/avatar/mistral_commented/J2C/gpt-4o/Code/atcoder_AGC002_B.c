#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Box { // Defining the Box structure
    int num; // Initializing the number property
    bool red; // Initializing the red property
} Box;

// Function for moving the box to another box
void moveTo(Box* current, Box* other) {
    if (current->num == 0) { // If the current box is empty
        return; // Do nothing
    } else if (current->num == 1) { // If the current box has only one item
        current->num = 0; // Setting the current box to be empty
        other->num++; // Incrementing the number of items in the other box
        if (current->red) { // If the current box was red
            other->red = true; // Setting the other box to be red
        }
        current->red = false; // Setting the current box to be empty and not red
    } else { // If the current box has more than one item
        current->num--; // Decrementing the number of items in the current box
        other->num++; // Incrementing the number of items in the other box
        if (current->red) { // If the current box was red
            other->red = true; // Setting the other box to be red
        }
    }
}

int main() { // Defining the main function
    int N, M; // Number of boxes and number of moves
    scanf("%d %d", &N, &M); // Reading the first two integer inputs from the user

    Box* B = (Box*)malloc(N * sizeof(Box)); // Creating an array of Box objects with size N

    // Initializing the first box with red color
    B[0].num = 1;
    B[0].red = true;

    // Initializing the remaining boxes with red color set to false
    for (int i = 1; i < N; i++) {
        B[i].num = 1;
        B[i].red = false;
    }

    // Reading the moves from the user and performing them on the boxes
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y); // Reading the x and y coordinates of the boxes
        moveTo(&B[x - 1], &B[y - 1]); // Moving the box at index x to the box at index y
    }

    // Counting the number of red boxes
    int counter = 0;
    for (int i = 0; i < N; i++) { // Iterating through all the boxes in the array
        if (B[i].red) { // If the current box has red color
            counter++; // Increment the counter
        }
    }

    // Printing the result
    printf("%d\n", counter);

    free(B); // Freeing the allocated memory
    return 0; // Returning from the main function
}

// <END-OF-CODE>
