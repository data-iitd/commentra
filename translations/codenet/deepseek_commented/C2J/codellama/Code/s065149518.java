#include <stdio.h>
#include <string.h>
#define MAX 21

// Function prototypes
void init(int);
void move(int);

// Global variables
int n, x, y;
char fld[MAX][MAX];

public class Main {
    public static void main(String[] args) {
        int m;
        // Read the number of items to be collected
        while(~scanf("%d", &n), n) {
            // Initialize the grid and the robot's position
            init(n);
            // Read the number of movements
            scanf("%d", &m);
            // Perform the movements
            move(m);
            // Output the result
            printf("%s\n", n ? "No" : "Yes");
        }
    }
}

// Initializes the grid with items and sets the robot's starting position
void init(int i) {
    int a, b;
    // Set the starting position of the robot
    x = y = 10;
    // Clear the grid
    memset(fld, 0, sizeof(fld));
    // Read the positions of items and mark them in the grid
    while(i--) {
        scanf("%d %d", &a, &b);
        fld[b][a] = 1;
    }
}

// Moves the robot according to the given directions and collects items
void move(int i) {
    int a, d;
    char buf[2];
    // Read each movement and execute it
    while(i--) {
        scanf("%1s %d", buf, &a);
        // Determine the direction and convert it to an index
        switch(buf[0]) {
          case 'N':
            d = 0;
            break;
          case 'E':
            d = 1;
            break;
          case 'S':
            d = 2;
            break;
          case 'W':
            d = 3;
            break;
        }
        // Move the robot and collect items
        while(a--) {
            // Update the robot's position based on the direction
            d % 2 ? ~-d ? x-- : x++ : d ? y-- : y++;
            // Check if the robot collects an item
            if(fld[y][x]) {
                fld[y][x] = 0;
                n--;
            }
        }
    }
}

