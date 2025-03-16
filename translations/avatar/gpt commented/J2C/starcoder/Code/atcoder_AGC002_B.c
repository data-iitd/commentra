#include <stdio.h>
#include <stdlib.h>

// Box class representing a box with a number and a color state
typedef struct {
    int num; // Number of items in the box
    int red; // Indicates if the box is red
} Box;

// Function to move items from this box to another box
void moveTo(Box *this, Box *other) {
    // If this box is empty, do nothing
    if (this->num == 0) {
        return;
    }
    // If this box has one item, transfer it to the other box
    else if (this->num == 1) {
        this->num = 0;
        other->num++;
        // If this box is red, the other box becomes red
        if (this->red) {
            other->red = 1;
        }
        this->red = 0; // This box is no longer red
    }
    // If this box has more than one item, transfer one item to the other box
    else {
        this->num--;
        other->num++;
        // If this box is red, the other box becomes red
        if (this->red) {
            other->red = 1;
        }
    }
}

// Main function
int main() {
    // Read the number of boxes (N) and the number of moves (M)
    int N, M;
    scanf("%d %d", &N, &M);

    // Initialize an array of Box objects
    Box *B = (Box *)malloc(N * sizeof(Box));

    // Create the first box as red and the rest as not red
    B[0].num = 1;
    B[0].red = 1;
    for (int i = 1; i < N; i++) {
        B[i].num = 1;
        B[i].red = 0;
    }

    // Process M moves based on user input
    for (int i = 0; i < M; i++) {
        // Read the indices of the boxes to move from and to
        int x, y;
        scanf("%d %d", &x, &y);
        // Move the contents from box x to box y
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

    // 