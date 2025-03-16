package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var t [][]string

	// Loop to take input and store it in the list t.
	for i := 0; i < 4; i++ {
		line, _ := reader.ReadString('\n')
		t = append(t, []string{})
		for _, char := range line {
			if char != '\n' {
				t[i] = append(t[i], string(char))
			}
		}
	}

	black := 0
	white := 0
	correct := 0

	// Nested loop to iterate over the 3x3 grid formed by the first 3 rows and columns of t.
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			// Count the number of black and white cells in the current 2x2 subgrid.
			if t[i][j] == "#" {
				black++
			} else {
				white++
			}
			if t[i][j+1] == "#" {
				black++
			} else {
				white++
			}
			if t[i+1][j] == "#" {
				black++
			} else {
				white++
			}
			if t[i+1][j+1] == "#" {
				black++
			} else {
				white++
			}

			// Check if the counts of black and white cells meet any of the specified conditions.
			if black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4 {
				correct = 1
				break // If conditions are met, set correct to 1 and break out of the loop.
			}

			black = 0 // Reset the count of black cells.
			white = 0 // Reset the count of white cells.
		}
		if correct == 1 {
			break
		}
	}

	// Print 'YES' if correct is 1, otherwise print 'NO'.
	if correct == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
