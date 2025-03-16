<<<<<<< HEAD

import (
=======
package main

import (
	"bufio"
>>>>>>> 98c87cb78a (data updated)
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a constant N for the size of the puzzle
const N = 4

// Define a structure for the puzzle
type Pazz struct {
	P [N][N]int
}

// Initialize a global variable Q to store the puzzle state
var Q Pazz

// Define an array for horizontal movement directions
var dx = [4]int{0, 1, 0, -1}

// Define an array for vertical movement directions
var dy = [4]int{1, 0, -1, 0}

// Heuristic function to calculate the Manhattan distance
func Heu(Q Pazz) int {
	var i, j int
	var hx, hy, sum int
	for i = 0; i < N; i++ {
		for j = 0; j < N; j++ {
			if Q.P[i][j] == 0 {
				continue
			}
			hx = (Q.P[i][j] - 1) % N - j
			hy = (Q.P[i][j] - 1) / N - i
			if hx < 0 {
				sum -= hx
			} else {
				sum += hx
			}
			if hy < 0 {
				sum -= hy
			} else {
				sum += hy
			}
		}
	}
	return sum
}

// Depth-first search function
func dfs(x, y, max, count, n int) int {
	var i, temp int
	var x0, y0, ans, h int

	h = Heu(Q) // Calculate the heuristic value of the current state

	if h == 0 {
		return count
	}
	if (count+h) > max {
		return -1
	}

	for i = 0; i < 4; i++ {
		x0 = x + dx[i]
		y0 = y + dy[i]
<<<<<<< HEAD
		if ((i == (n+2)%4 && n!= -1) ||!(0 <= x0 && x0 < N && 0 <= y0 && y0 < N)) {
=======
		if ((i == (n+2)%4) && (n!= -1)) ||!((0 <= x0) && (x0 < N) && (0 <= y0) && (y0 < N)) {
>>>>>>> 98c87cb78a (data updated)
			continue
		}
		temp = Q.P[y][x] // Swap the current tile with the target tile
		Q.P[y][x] = Q.P[y0][x0]
		Q.P[y0][x0] = temp

		ans = dfs(x0, y0, max, count+1, i) // Recursively call dfs with the new state

		if ans!= -1 {
			return ans
		}
		temp = Q.P[y][x] // Swap back to the original state
		Q.P[y][x] = Q.P[y0][x0]
		Q.P[y0][x0] = temp
	}

	return -1
}

func main() {
	var i, j int
	var kx, ky, ans, a int
	var tP Pazz

	// Read the puzzle from input
<<<<<<< HEAD
	for i = 0; i < N; i++ {
		for j = 0; j < N; j++ {
			a, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.ReadByte())))
=======
	reader := bufio.NewReader(os.Stdin)
	for i = 0; i < N; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		for j = 0; j < N; j++ {
			a, _ = strconv.Atoi(string(line[j]))
>>>>>>> 98c87cb78a (data updated)
			Q.P[i][j] = a
			if a == 0 {
				kx = j
				ky = i
			}
		}
	}

	tP = Q
	for i = 1; i < 46; i++ { // Iterate through possible depths
		Q = tP
		ans = dfs(kx, ky, i, 0, -1)
		if ans!= -1 {
			fmt.Println(ans) // Print the number of moves if a solution is found
			break
		}
	}
}

