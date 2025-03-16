
package main

import (
	"fmt"
	"math"
	"strings"
)

// Type definitions for convenience
type ll int //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
type ld float64

// Redefining int as long long for larger integer support
type int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Type definitions for commonly used data structures
type vi []int
type vs []string
type pii []int
type vp []pii

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

// Global variables for the problem
var ans int = math.MaxInt32 // Variable to store the minimum number of moves
var h, w int = 19, 15        // Dimensions of the grid
var dx = []int{0, 1, 0, -1, 1, 1, -1, -1}
var dy = []int{1, 0, -1, 0, 1, -1, 1, -1}
var s []string // 2D grid representation

// Depth-First Search (DFS) function to explore the grid
func dfs(x, y, cnt int) {
	// Base case: if the count exceeds 20, stop the search
	if cnt > 20 {
		return
	}

	// Check if the bottom row is reached
	if x == h-1 {
		ans = int(math.Min(float64(ans), float64(cnt))) // Update the answer with the minimum moves
		return
	}

	// Explore all 8 possible directions
	for i := 0; i < 8; i++ {
		nx := x + dx[i] // New x-coordinate
		ny := y + dy[i] // New y-coordinate
		// Check if the new coordinates are within bounds
		if nx < 0 || nx >= h || ny < 0 || ny >= w {
			continue
		}
		// Check if the current cell is not blocked
		if s[nx][ny] != 'X' {
			continue
		}

		c := true // Flag to control the loop
		// Move in the current direction while possible
		for c && s[nx][ny] == 'X' {
			s[nx][ny] = '.' // Mark the cell as visited
			nx += dx[i]     // Move to the next cell in the direction
			ny += dy[i]
			// Check if the new coordinates are out of bounds
			if nx < 0 || nx >= h || ny < 0 || ny >= w {
				if nx >= h {
					ans = int(math.Min(float64(ans), float64(cnt+1))) // Update answer if out of bounds
				}
				c = false // Stop the loop
			}
		}
		// Recursive DFS call for the new position
		if c {
			dfs(nx, ny, cnt+1)
		}
		// Backtrack: restore the grid to its previous state
		for nx != x || ny != y {
			nx -= dx[i]
			ny -= dy[i]
			s[nx][ny] = 'X' // Restore the cell
		}
		s[x][y] = '.' // Mark the original cell as visited
	}
}

// Main function
func main() {
	// Input the grid
	s = strings.Split(strings.TrimSpace(readLine()), "")
	var sx, sy int // Starting coordinates
	// Find the starting position 'O' and mark it as visited
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if s[i][j] == 'O' {
				sx = i
				sy = j
				s[i][j] = '.'
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

