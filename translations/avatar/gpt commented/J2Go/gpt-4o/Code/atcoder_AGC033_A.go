package main

import (
	"container/list"
	"fmt"
)

func main() {
	var H, W int
	fmt.Scan(&H, &W)

	// Initialize a 2D slice to store the grid
	A := make([][]rune, H)
	for i := range A {
		A[i] = make([]rune, W)
	}

	// Initialize a queue to perform BFS (Breadth-First Search)
	queue := list.New()

	// Read the grid input and populate the character array
	for i := 0; i < H; i++ {
		var row string
		fmt.Scan(&row)
		for j, ch := range row {
			A[i][j] = ch

			// If the current cell is a wall ('#'), add its position to the queue
			if A[i][j] == '#' {
				queue.PushBack([3]int{i, j, 0}) // Store the position and initial depth
			}
		}
	}

	// Initialize a flag array to track visited cells
	flag := make([][]int, H)
	for i := range flag {
		flag[i] = make([]int, W)
	}

	// Variable to store the maximum depth reached
	ans := 0

	// Direction vectors for moving up, down, left, and right
	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1}

	// Perform BFS until the queue is empty
	for queue.Len() > 0 {
		// Remove the front element from the queue
		element := queue.Front()
		queue.Remove(element)
		temp := element.Value.([3]int)
		y, x, depth := temp[0], temp[1], temp[2]

		// Explore all four possible directions
		for i := 0; i < 4; i++ {
			newY := y + dy[i]
			newX := x + dx[i]

			// Check if the new coordinates are within bounds
			if 0 <= newY && newY < H && 0 <= newX && newX < W {
				// Check if the cell has not been visited and is an empty space ('.')
				if flag[newY][newX] == 0 && A[newY][newX] == '.' {
					flag[newY][newX] = 1 // Mark the cell as visited
					queue.PushBack([3]int{newY, newX, depth + 1}) // Add the new position to the queue
					ans = depth + 1 // Update the maximum depth reached
				}
			}
		}
	}

	// Output the maximum depth reached
	fmt.Println(ans)
}

// <END-OF-CODE>
