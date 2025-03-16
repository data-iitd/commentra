package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the height (H) and width (W) of the grid
	H, _ := strconv.Atoi(readLine(reader))
	W, _ := strconv.Atoi(readLine(reader))

	// Initialize a 2D character array to store the grid
	A := make([][]byte, H)
	for i := range A {
		A[i] = []byte(readLine(reader))
	}

	// Initialize a queue to perform BFS (Breadth-First Search)
	queue := make([][]int, 0)

	// Read the grid input and populate the character array
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if A[i][j] == byte('#') {
				start := []int{i, j, 0} // Store the position and initial depth
				queue = append(queue, start) // Add the starting position to the queue
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
	for len(queue) > 0 {
		temp := queue[0]
		queue = queue[1:]
		y := temp[0]
		x := temp[1]
		depth := temp[2]

		// Explore all four possible directions
		for i := 0; i < 4; i++ {
			// Calculate new coordinates
			newY := y + dy[i]
			newX := x + dx[i]

			// Check if the new coordinates are within bounds
			if 0 <= newY && newY <= H-1 && 0 <= newX && newX <= W-1 {
				// Check if the cell has not been visited and is an empty space ('.')
				if flag[newY][newX] == 0 && A[newY][newX] == byte('.') {
					flag[newY][newX] = 1
					queue_add := []int{newY, newX, depth + 1} // Prepare the new position and updated depth
					queue = append(queue, queue_add) // Add the new position to the queue
					ans = depth + 1 // Update the maximum depth reached
				}
			}
		}
	}

	// Output the maximum depth reached
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

