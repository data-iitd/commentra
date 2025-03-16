
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	h, w int
	s     []string
	ans   = 1 << 30
	dx    = []int{0, 1, 0, -1, 1, 1, 1, -1, -1}
	dy    = []int{1, 0, -1, 0, 1, -1, 1, 1, -1}
)

func gcd(a, b int) int {
	// Function to find the greatest common divisor of two numbers
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	// Function to find the least common multiple of two numbers
	return a / gcd(a, b) * b
}

func dfs(x, y, cnt int) {
	// Function to perform a depth-first search from a given position
	// with a given number of steps
	if cnt > 20 {
		return
	}

	// Print the current position, number of steps, and the current state of the grid
	// for debugging purposes
	//fmt.Printf("%d %d %d\n", x, y, cnt)
	// Print the current state of the grid
	//for i := 0; i < h; i++ {
	//	fmt.Println(s[i])
	//}

	// Check if the current position is the last row of the grid
	if x == h-1 {
		// Update the answer if the current number of steps is less than the previous answer
		ans = min(ans, cnt)
		return
	}

	// Iterate through all the possible directions
	for i := 0; i < 8; i++ {
		nx, ny := x+dx[i], y+dy[i]

		// Check if the next position is out of the grid
		if nx < 0 || nx >= h || ny < 0 || ny >= w {
			continue
		}

		// Check if the next position contains an 'X'
		if s[nx][ny]!= "X" {
			continue
		}

		// Perform a depth-first search from the next position with one more step
		c := true
		for c && s[nx][ny] == "X" {
			s[nx][ny] = "."
			nx += dx[i]
			ny += dy[i]
			if nx < 0 || nx >= h || ny < 0 || ny >= w {
				if nx >= h {
					ans = min(ans, cnt+1)
				}
				c = false
			}
		}

		// If the loop did not exit due to an out-of-grid position, perform the depth-first search
		if c {
			dfs(nx, ny, cnt+1)
		}

		// Backtrack by restoring the previous state of the grid
		for nx!= x || ny!= y {
			nx -= dx[i]
			ny -= dy[i]
			s[nx][ny] = "X"
		}

		// Restore the current position of the 'O'
		s[x][y] = "."
	}
}

func main() {
	// Initialize the 2D vector to store the grid
	s = make([]string, h)
	for i := 0; i < h; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%s", &s[i])
	}

	// Find the position of the 'O'
	sx, sy := -1, -1
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if s[i][j] == "O" {
				sx, sy = i, j
				s[i][j] = "."
			}
		}
	}

	// Perform a depth-first search from the position of the 'O' with 0 steps
	dfs(sx, sy, 0)

	// Print the answer if it is not equal to INF
	if ans == 1<<30 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

