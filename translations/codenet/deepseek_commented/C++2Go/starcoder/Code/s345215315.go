
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Global variables for the problem
var (
	ans int = math.MaxInt32
	h   int = 19
	w   int = 15
	dx  = []int{0, 1, 0, -1, 1, 1, -1, -1}
	dy  = []int{1, 0, -1, 0, 1, -1, 1, -1}
	s   = make([]string, 19)
)

// Function to compute the Greatest Common Divisor (GCD) of two numbers
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to compute the Least Common Multiple (LCM) of two numbers
func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

// Depth-First Search (DFS) function to explore the grid
func dfs(x, y, cnt int) {
	// Base case: if the count exceeds 20, stop the search
	if cnt > 20 {
		return
	}

	// Check if the bottom row is reached
	if x == h-1 {
		ans = min(ans, cnt)
		return
	}

	// Explore all 8 possible directions
	for i := 0; i < 8; i++ {
		nx := x + dx[i]
		ny := y + dy[i]
		// Check if the new coordinates are within bounds
		if nx < 0 || nx >= h || ny < 0 || ny >= w {
			continue
		}
		// Check if the current cell is not blocked
		if s[nx][ny]!= 'X' {
			continue
		}

		c := true
		// Move in the current direction while possible
		for c && s[nx][ny] == 'X' {
			s[nx][ny] = '.'
			nx += dx[i]
			ny += dy[i]
			// Check if the new coordinates are out of bounds
			if nx < 0 || nx >= h || ny < 0 || ny >= w {
				if nx >= h {
					ans = min(ans, cnt+1)
				}
				c = false
			}
		}
		// Recursive DFS call for the new position
		if c {
			dfs(nx, ny, cnt+1)
		}
		// Backtrack: restore the grid to its previous state
		for nx!= x || ny!= y {
			nx -= dx[i]
			ny -= dy[i]
			s[nx][ny] = 'X'
		}
		s[x][y] = '.'
	}
}

// Main function
func main() {
	// Input the grid
	for i := 0; i < h; i++ {
		s[i] = strings.TrimSpace(string(os.Stdin.ReadByte()))
	}
	sx, sy := 0, 0
	// Find the starting position 'O' and mark it as visited
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if s[i][j] == 'O' {
<<<<<<< HEAD
				sx = i
				sy = j
=======
				sx, sy = i, j
>>>>>>> 98c87cb78a (data updated)
				s[i][j] = '.'
				break
			}
		}
	}
	// Start DFS from the initial position
	dfs(sx, sy, 0)
	// Output the result: minimum moves or -1 if not reachable
	if ans == math.MaxInt32 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

