

#include <stdio.h>
#include <string.h>

int main() {
    char record_of_movements[1000];  // Declare a character array to store the movements of a character
    scanf("%s", record_of_movements);  // Take input for the movements of a character
    int x = 0, y = 0;  // Initialize the starting position (x, y) to (0, 0)
    int d_movement[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};  // Define a 2D array that maps each direction to its coordinate changes
    int d[1000][2] = {{0, 0}};  // Initialize a 2D array to keep track of visited positions
    int bug = 0;  // Initialize a flag bug to 0
    int i;  // Declare a loop variable
    
    for (i = 0; record_of_movements[i]!= '\0'; i++) {  // Iterate over each movement in the input
        int temp_x = x, temp_y = y;  // Store the current position in temporary variables
        x += d_movement[record_of_movements[i] - 'L'][0];  // Update the x-coordinate based on the direction
        y += d_movement[record_of_movements[i] - 'L'][1];  // Update the y-coordinate based on the direction
        
        if (x!= temp_x || y!= temp_y) {  // Check if the new position has been visited before
            int j;  // Declare a loop variable
            for (j = 0; j < 4; j++) {  // Check the surrounding positions
                if ((x + d_movement[j][0]!= temp_x || y + d_movement[j][1]!= temp_y) && (x + d_movement[j][0], y + d_movement[j][1]) in d) {
                    bug = 1;  // Set the bug flag to 1 if a bug is detected
                    break;  // Break out of the loop if a bug is detected
                }
            }
        } else {
            bug = 1;  // Set the bug flag to 1 if the new position has been visited before
        }
        
        if (bug) {  // Check if a bug was detected
            break;  // Break out of the loop if a bug was detected
        }
        
        d[i][0] = x;  // Add the new position to the 2D array d
        d[i][1] = y;
    }
    
    if (bug) {  // Check if a bug was detected
        printf("BUG\n");  // Print 'BUG' if a bug was detected
    } else {
        printf("OK\n");  // Print 'OK' if no bug was detected
    }
    
    return 0;  // Return 0 to indicate successful execution
}
