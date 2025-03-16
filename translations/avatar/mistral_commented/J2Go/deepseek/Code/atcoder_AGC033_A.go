package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read the number of rows and columns from the input
	var H, W int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &H)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &W)

	// Initialize a 2D char array 'A' to store the input grid
	A := make([][]byte, H)

	// Initialize a Queue to store the cells to be processed
	queue := [][]int{}

	// Read the grid and initialize the queue with the starting points of 'B'
	for i := 0; i < H; i++ {
		scanner.Scan()
		row := scanner.Text()
		A[i] = make([]byte, W)
		for j := 0; j < W; j++ {
			A[i][j] = row[j]
			// If the cell contains '#', add its starting point to the queue
			if A[i][j] == '#' {
				queue = append(queue, []int{i, j, 0})
			}
		}
	}

	// Initialize a 2D int array 'flag' to mark the visited cells
	flag := make([][]int, H)
	for i := range flag {
		flag[i] = make([]int, W)
	}

	// Initialize variables for the answer and the directions
	ans := 0
	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1}

	// Process the queue and find the answer
	for len(queue) > 0 {
		temp := queue[0]
		queue = queue[1:]
		y := temp[0]
		x := temp[1]
		depth := temp[2]

		// Process the neighboring cells
		for i := 0; i < 4; i++ {
			newY := y + dy[i]
			newX := x + dx[i]

			// If the cell is within the grid and hasn't been visited yet,
			// and contains a '.', mark it as visited and add it to the queue
			if 0 <= newY && newY < H && 0 <= newX && newX < W {
				if flag[newY][newX] == 0 && A[newY][newX] == '.' {
					flag[newY][newX] = 1
					queue = append(queue, []int{newY, newX, depth + 1})
					ans = max(ans, depth + 1)
				}
			}
		}
	}

	// Print the answer
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

