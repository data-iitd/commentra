
#include<iostream>

// Declare variables
int r, c, n, flag, cnt;
int arr[16][16] = { 0 };

int main()
{
	// Initialize variables
	int r, c, n, flag, cnt;
	int arr[16][16] = { 0 };

	// Infinite loop until user inputs 0
	while (1)
	{
		std::cout << "Enter the size of the square matrix: ";
		std::cin >> n;

		// Break the loop if user inputs 0
		if (n == 0)
		{
			break;
		}

		flag = 1; // Initialize flag to 1
		r = (n + 1) / 2 + 1; // Calculate row and column indices
		c = (n + 1) / 2;

		// Set the first element of the matrix
		arr[r][c] = cnt = 1;

		// Fill the rest of the matrix
		while (cnt != n*n + 1)
		{
			++cnt;

			// If flag is 1, move to the next cell in the right direction
			if (flag)
			{
				++r;
				++c;

				// If we reach the end of the row, move to the first cell of the next row
				if (c > n)
				{
					c = 1;
				}

				// If we reach the end of the matrix, move to the first cell of the first row
				if (r > n)
				{
					r = 1;
				}

				// If the cell is already filled, move to the opposite cell
				if (arr[r][c])
				{
					flag = 0;
					--cnt;
				}
				// Otherwise, fill the cell with the current number
				else
				{
					arr[r][c] = cnt;
				}
			}
			// If flag is 0, move to the previous cell in the left direction
			else
			{
				++r;
				--c;

				// If we reach the beginning of the row, move to the last cell of the previous row
				if (c < 1)
				{
					c = n;
				}

				// If we reach the beginning of the matrix, move to the last cell of the last row
				if (r > n)
				{
					r = 1;
				}

				// If the cell is already filled, move to the opposite cell
				if (arr[r][c])
				{
					flag = 0;
				}
				// Otherwise, fill the cell with the current number and set flag to 1
				else
				{
					arr[r][c] = cnt;
					flag = 1;
				}
			}
		}

		// Print the filled matrix
		for (r = 1; r < n + 1; r++)
		{
			for (c = 1; c < n + 1; c++)
			{
				std::cout << std::setw(4) << arr[r][c];
				arr[r][c] = 0; // Reset the matrix for the next input
				if (c == n)
				{
					std::cout << std::endl;
				}
			}
		}
	}

	// Return 0 to indicate successful execution
	return 0;
}

