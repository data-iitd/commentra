package main

import (
	"container/list"
	"fmt"
)

func main() {
	var H, W int
	fmt.Scan(&H, &W)

	// Initialize a 2D slice 'A' to store the input grid
	A := make([][]rune, H)
	for i := range A {
		A[i] = make([]rune, W)
	}

	// Initialize a Queue to store the cells to be processed
	queue := list.New()

	// Read the grid and initialize the queue with the starting points of 'B'
	for i := 0; i < H; i++ {
		var row string
		fmt.Scan(&row)
		for j := 0; j < W; j++ {
			A[i][j] = rune(row[j])
			// If the cell contains '#', add its starting point to the queue
			if A[i][j] == '#' {
				queue.PushBack([3]int{i, j, 0})
			}
		}
	}

	// Initialize a 2D slice 'flag' to mark the visited cells
	flag := make([][]int, H)
	for i := range flag {
		flag[i] = make([]int, W)
	}

	// Initialize variables for the answer and the directions
	ans := 0
	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1}

	// Process the queue and find the answer
	for queue.Len() > 0 {
		temp := queue.Remove(queue.Front()).([3]int)
		y, x, depth := temp[0], temp[1], temp[2]

		// Process the neighboring cells
		for i := 0; i < 4; i++ {
			newY := y + dy[i]
			newX := x + dx[i]

			// If the cell is within the grid and hasn't been visited yet,
			// and contains a '.', mark it as visited and add it to the queue
			if newY >= 0 && newY < H && newX >= 0 && newX < W {
				if flag[newY][newX] == 0 && A[newY][newX] == '.' {
					flag[newY][newX] = 1
					queue.PushBack([3]int{newY, newX, depth + 1})
					ans = max(ans, depth+1)
				}
			}
		}
	}

	// Print the answer
	fmt.Println(ans)
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
