#include<stdio.h>

int main()
{
    // Declare variables for rows, columns, size of the square, flag for control flow, and counter
    int r, c, n, flag, cnt;
    // Initialize a 16x16 array to store the magic square, filled with zeros
    int arr[16][16] = { 0 };

    // Infinite loop to continuously accept input until a zero is entered
    while (1)
    {
        // Read the size of the magic square
        scanf("%d", &n);
        // Exit the loop if the input is zero
        if (n == 0)
        {
            break;
        }
        
        // Initialize flag and starting position for the first number
        flag = 1;
        r = (n + 1) / 2 + 1; // Starting row
        c = (n + 1) / 2;     // Starting column
        arr[r][c] = cnt = 1; // Place the first number in the array

        // Loop to fill the magic square until all numbers are placed
        while (cnt != n*n + 1)
        {
            ++cnt; // Increment the counter for the next number
            
            // If flag is set, move diagonally up-right
            if (flag)
            {
                ++r; // Move down one row
                ++c; // Move right one column
                
                // Wrap around if going out of bounds
                if (c > n)
                {
                    c = 1; // Wrap to the first column
                }

                if (r > n)
                {
                    r = 1; // Wrap to the first row
                }

                // Check if the current position is already filled
                if (arr[r][c])
                {
                    flag = 0; // Change direction if the position is occupied
                    --cnt;    // Decrement the counter to retry placing the number
                }
                else
                {
                    arr[r][c] = cnt; // Place the number in the array
                }
            }
            else // If flag is not set, move down-left
            {
                ++r; // Move down one row
                --c; // Move left one column
                
                // Wrap around if going out of bounds
                if (c < 1)
                {
                    c = n; // Wrap to the last column
                }

                if (r > n)
                {
                    r = 1; // Wrap to the first row
                }

                // Check if the current position is already filled
                if (arr[r][c])
                {
                    flag = 0; // Change direction if the position is occupied
                }
                else
                {
                    arr[r][c] = cnt; // Place the number in the array
                    flag = 1; // Reset flag to move diagonally up-right next
                }
            }

            // Uncomment the following line for debugging purposes
            // printf("r=%d  c=%d   cnt=%d\n", r, c, cnt);
        }

        // Print the completed magic square
        for (r = 1; r < n + 1; r++)
        {
            for (c = 1; c < n + 1; c++)
            {
                printf("%4d", arr[r][c]); // Print each number in the magic square
                arr[r][c] = 0; // Reset the position in the array for the next iteration
                if (c == n)
                {
                    printf("\n"); // Print a newline at the end of each row
                }
            }
        }
    }

    return 0; // Return success
}
