package main

import "fmt"

func main() {
	t := make([][]string, 0) // Initialize an empty list to store the input data.

	// Loop to take input and store it in the list t.
	for i := 0; i < 4; i++ {
		l := make([]string, 0) // Take input, convert it to a list of characters, and append to t.
		for j := 0; j < 4; j++ {
			l = append(l, string(<-chan rune(os.Stdin)))
		}
		t = append(t, l)
	}

	black := 0 // Initialize the count of black cells to 0.
	white := 0 // Initialize the count of white cells to 0.
	correct := 0 // Initialize the correct flag to 0.

	// Nested loop to iterate over the 3x3 grid formed by the first 3 rows and columns of t.
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			// Count the number of black and white cells in the current 2x2 subgrid.
			if t[i][j] == '#' {
				black += 1
			} else {
				white += 1
			}
			if t[i][j + 1] == '#' {
				black += 1
			} else {
				white += 1
			}
			if t[i + 1][j] == '#' {
				black += 1
			} else {
				white += 1
			}
			if t[i + 1][j + 1] == '#' {
				black += 1
			} else {
				white += 1
			}

			// Check if the counts of black and white cells meet any of the specified conditions.
			if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4) {
				correct = 1
				break // If conditions are met, set correct to 1 and break out of the loop.
			}

			black = 0 // Reset the count of black cells.
			white = 0 // Reset the count of white cells.
		}
	}

	// Print 'YES' if correct is 1, otherwise print 'NO'.
	if correct == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

