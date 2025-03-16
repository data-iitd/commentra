#include<stdio.h>

#define N 16

// Main function to generate and print magic squares of size n
int main()
{
    int r, c, n, flag, cnt;
    int arr[N][N] = { 0 }; // 2D array to store the magic square

    // Infinite loop to keep the program running until n is 0
    while (1)
    {
        scanf("%d", &n); // Read the size of the magic square from the user
        if (n == 0)
        {
            break; // Exit the loop if n is 0
        }

        // Initialize the starting position and the counter
        flag = 1;
        r = (n + 1) / 2 + 1; // Calculate the starting row
        c = (n + 1) / 2;     // Calculate the starting column
        arr[r][c] = cnt = 1; // Set the initial value and start the counter

        // Loop to fill the magic square
        while (cnt!= n*n + 1)
        {
            ++cnt; // Increment the counter
            if (flag)
            {
                ++r; // Move up-right
                ++c; // Move up-right
                if (c > n) c = 1; // Wrap around if column exceeds n
                if (r > n) r = 1; // Wrap around if row exceeds n
                if (arr[r][c]) // Check if the position is already filled
                {
                    flag = 0; // Change direction
                    --cnt; // Decrement the counter to repeat the last position
                }
                else
                {
                    arr[r][c] = cnt; // Fill the position
                }
            }
            else
            {
                ++r; // Move down-left
                --c; // Move down-left
                if (c < 1) c = n; // Wrap around if column goes below 1
                if (r > n) r = 1; // Wrap around if row exceeds n
                if (arr[r][c]) // Check if the position is already filled
                {
                    flag = 0; // Change direction
                }
                else
                {
                    arr[r][c] = cnt; // Fill the position
                    flag = 1; // Change direction for the next move
                }
            }
        }

        // Print the generated magic square
        for (r = 1; r < n + 1; r++)
        {
            for (c = 1; c < n + 1; c++)
            {
                printf("%4d", arr[r][c]); // Print each element with formatting
                arr[r][c] = 0; // Reset the element for the next iteration
                if (c == n)
                {
                    printf("\n"); // Move to the next line after each row
                }
            }
        }
    }

    return 0;
}

