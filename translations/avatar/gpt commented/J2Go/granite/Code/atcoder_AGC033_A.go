
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the height (H) and width (W) of the grid
	line, _ := reader.ReadString('\n')
	tokens := strings.Split(line, " ")
	H, _ := strconv.Atoi(tokens[0])
	W, _ := strconv.Atoi(tokens[1])

	// Initialize a 2D character array to store the grid
	A := make([][]byte, H)
	for i := 0; i < H; i++ {
		line, _ := reader.ReadString('\n')
		A[i] = []byte(line)
	}

	// Initialize a queue to perform BFS (Breadth-First Search)
	queue := make([][]int, 0)

	// Read the grid input and populate the character array
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			// If the current cell is a wall ('#'), add its position to the queue
			if A[i][j] == '#' {
				queue = append(queue, []int{i, j, 0}) // Store the position and initial depth
			}
		}
	}

	// Initialize a flag array to track visited cells
	flag := make([][]int, H)
	for i := 0; i < H; i++ {
		flag[i] = make([]int, W)
	}

	// Variable to store the maximum depth reached
	ans := 0

	// Direction vectors for moving up, down, left, and right
	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1}

	// Perform BFS until the queue is empty
	for len(queue) > 0 {
		temp := queue[0] // Remove the front element from the queue
		queue = queue[1:]
		y := temp[0] // Current y-coordinate
		x := temp[1] // Current x-coordinate
		depth := temp[2] // Current depth

		// Explore all four possible directions
		for i := 0; i < 4; i++ {
			// Calculate new coordinates
			newY := y + dy[i]
			newX := x + dx[i]

			// Check if the new coordinates are within bounds
			if 0 <= newY && newY < H && 0 <= newX && newX < W {
				// Check if the cell has not been visited and is an empty space ('.')
				if flag[newY][newX] == 0 && A[newY][newX] == '.' {
					flag[newY][newX] = 1 // Mark the cell as visited
					queue = append(queue, []int{newY, newX, depth + 1}) // Add the new position to the queue
					ans = depth + 1 // Update the maximum depth reached
				}
			}
		}
	}

	// Output the maximum depth reached
	fmt.Println(ans)
}
