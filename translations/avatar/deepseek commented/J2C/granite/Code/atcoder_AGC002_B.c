

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int red;
} Box;

void moveTo(Box *source, Box *dest) {
    if (source->num == 0) {
        return; // Do nothing if the box is already empty
    } else if (source->num == 1) {
        source->num = 0; // Set the current box to empty
        dest->num++; // Increment the destination box's number
        if (source->red) {
            dest->red = 1; // If the current box was red, make the destination box red
        }
        source->red = 0; // The current box is no longer red
    } else {
        source->num--; // Decrement the current box's number
        dest->num++; // Increment the destination box's number
        if (source->red) {
            dest->red = 1; // If the current box was red, make the destination box red
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M); // Read the number of boxes and moves
    Box *boxes = (Box*)malloc(N * sizeof(Box));
    boxes[0] = (Box){1, 1}; // Initialize the first box with num=1 and red=true
    for (int i = 1; i < N; i++) {
        boxes[i] = (Box){1, 0}; // Initialize the rest of the boxes with num=1 and red=false
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y); // Read the source and destination box indices
        moveTo(&boxes[x - 1], &boxes[y - 1]); // Move the box from source to destination
    }
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (boxes[i].red) {
            counter++; // Count the number of red boxes
        }
    }
    printf("%d\n", counter); // Print the count of red boxes
    free(boxes); // Free the memory allocated for the boxes
    return 0;
}

