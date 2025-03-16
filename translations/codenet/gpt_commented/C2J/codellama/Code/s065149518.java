#include <stdio.h>
#include <string.h>
#define MAX 21

// Function prototypes
void init(int);
void move(int);

// Global variables to hold the state of the game
int n, x, y;
char fld[MAX][MAX];

public class Main {
    public static void main(String[] args) {
        int m;
        // Continuously read the size of the field until a zero is encountered
        while(~scanf("%d", &n), n) {
            // Initialize the field based on the size provided
            init(n);
            // Read the number of moves to be made
            scanf("%d", &m);
            // Execute the moves
            move(m);
            // Print "Yes" if all fields are cleared, otherwise print "No"
            printf("%s\n", n ? "No" : "Yes");
        }
    }

    // Function to initialize the game field
    public static void init(int i) {
        int a, b;
        // Set the starting position of the player
        x = y = 10;
        // Clear the field by setting all values to 0
        memset(fld, 0, sizeof(fld));
        // Read the positions of obstacles and mark them in the field
        while(i--) {
            scanf("%d %d", &a, &b);
            fld[b][a] = 1; // Mark the position as occupied
        }
    }

    // Function to process the moves made by the player
    public static void move(int i) {
        int a, d;
        char buf[2];
        // Process each move command
        while(i--) {
            // Read the direction and the number of steps
            scanf("%1s %d", buf, &a);
            // Determine the direction based on the input
            switch(buf[0]) {
              case 'N':
                d = 0; // North
                break;
              case 'E':
                d = 1; // East
                break;
              case 'S':
                d = 2; // South
                break;
              case 'W':
                d = 3; // West
                break;
            }
            // Move in the specified direction for the given number of steps
            while(a--) {
                // Update the position based on the direction
                d % 2 ? ~-d ? x-- : x++ : d ? y-- : y++;
                // Check if the new position has an obstacle
                if(fld[y][x]) {
                    // Remove the obstacle and decrement the count of remaining obstacles
                    fld[y][x] = 0;
                    n--;
                }
            }
        }
    }
}

