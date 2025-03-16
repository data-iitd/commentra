package main

import (
	"fmt"
	"math"
)

// Type definitions for convenience
type ll int
type ld float64

const (
	EPS  = 0.0000000001
	INF  = 1e9
	LINF = ll(INF) * INF
	MOD  = 1000000007
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

// Global variables for the problem
var ans = INF
var h = 19
var w = 15
var dx = [8]int{0, 1, 0, -1, 1, 1, -1, -1}
var dy = [8]int{1, 0, -1, 0, 1, -1, 1, -1}
var s = [19]string{}

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
		if string(s[nx][ny]) != "X" {
			continue
		}

		c := true
		// Move in the current direction while possible
		for c && string(s[nx][ny]) == "X" {
			s[nx] = s[nx][:ny] + "." + s[nx][ny+1:]
			nx += dx[i]
			ny += dy[i]
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
		for nx != x || ny != y {
			nx -= dx[i]
			ny -= dy[i]
			s[nx] = s[nx][:ny] + "X" + s[nx][ny+1:]
		}
		s[x] = s[x][:y] + "." + s[x][y+1:]
	}
}

// Main function
func main() {
	// Input the grid
	for i := 0; i < h; i++ {
		fmt.Scan(&s[i])
	}
	var sx, sy int
	// Find the starting position 'O' and mark it as visited
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if string(s[i][j]) == "O" {
				sx, sy = i, j
				s[i] = s[i][:j] + "." + s[i][j+1:]
			}
		}
	}
	// Start DFS from the initial position
	dfs(sx, sy, 0)
	// Output the result: minimum moves or -1 if not reachable
	if ans == INF {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

