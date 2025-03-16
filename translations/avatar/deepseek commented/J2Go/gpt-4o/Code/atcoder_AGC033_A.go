package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin) // Step 1: Initialize the scanner to read input
	scanner.Scan()
	var H, W int
	fmt.Sscanf(scanner.Text(), "%d %d", &H, &W) // Reading the height and width of the grid

	A := make([][]rune, H) // Step 2: Initialize the grid A
	for i := range A {
		A[i] = make([]rune, W)
	}

	queue := [][]int{} // Initialize the queue for BFS

	// Step 3: Read the grid row by row and initialize the queue with positions of '#' characters
	for i := 0; i < H; i++ {
		scanner.Scan()
		row := scanner.Text()
		for j, char := range row {
			A[i][j] = char // Storing the character in the grid
			if A[i][j] == '#' { // If the character is '#'
				queue = append(queue, []int{i, j, 0}) // Add the starting point to the queue
			}
		}
	}

	// Step 4: Initialize a flag array to keep track of visited cells
	flag := make([][]int, H)
	for i := range flag {
		flag[i] = make([]int, W)
	}
	ans := 0 // Variable to store the maximum distance

	// Directions for moving in the grid (right, left, down, up)
	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1}

	// Step 5: Perform BFS to find the maximum distance from any '#' to a '.'
	for len(queue) > 0 {
		temp := queue[0] // Remove the first element from the queue
		queue = queue[1:] // Update the queue
		y, x, depth := temp[0], temp[1], temp[2] // Current coordinates and depth

		// Check all four possible directions
		for i := 0; i < 4; i++ {
			newY := y + dy[i]
			newX := x + dx[i]
			if newY >= 0 && newY < H && newX >= 0 && newX < W {
				if flag[newY][newX] == 0 && A[newY][newX] == '.' {
					flag[newY][newX] = 1 // Mark the cell as visited
					queue = append(queue, []int{newY, newX, depth + 1}) // Add the new position to the queue
					ans = depth + 1 // Update the maximum distance
				}
			}
		}
	}

	// Step 6: Output the maximum distance found
	fmt.Println(ans)
}

// <END-OF-CODE>
