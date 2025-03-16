
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure Pazz to hold a 2D array P
type Pazz struct {
	P [4][4]int
}

<<<<<<< HEAD
var Q Pazz
var dx [4]int = [4]int{0, 1, 0, -1}
var dy [4]int = [4]int{1, 0, -1, 0}

// Function to calculate the heuristic value of the given Pazz structure Q
func Heu(Q Pazz) int {
	var i, j int
	var hx, hy, sum int
=======
var Q Pazz // Initialize an empty Pazz structure Q
var dx [4]int = [4]int{0, 1, 0, -1} // Define the possible moves in x direction
var dy [4]int = [4]int{1, 0, -1, 0} // Define the possible moves in y direction

// Function to calculate the heuristic value of the given Pazz structure Q
func Heu(Q Pazz) int {
	var i, j int // Iterator variables
	var hx, hy, sum int // Local variables
>>>>>>> 98c87cb78a (data updated)

	// Iterate through all the elements of the 2D array P in Q
	for i = 0; i < 4; i++ {
		for j = 0; j < 4; j++ {
			// If the current element is not part of the puzzle, continue to next iteration
			if Q.P[i][j] == 0 {
				continue
			}

			// Calculate the heuristic value hx and hy for the current element
			hx = (Q.P[i][j] - 1) % 4 - j
			hy = (Q.P[i][j] - 1) / 4 - i

			// Update the sum based on the heuristic values hx and hy
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
	// Return the final sum as the heuristic value of the given Pazz structure Q
	return sum
}

// Recursive function to find the solution using Depth First Search algorithm
func dfs(x, y, max, count, n int) int {
<<<<<<< HEAD
	var i, temp int
	var x0, y0, ans int = -1
=======
	var i, temp int // Local variables
	var x0, y0, ans int // Local variables to store the answer and temporary variables
>>>>>>> 98c87cb78a (data updated)

	// Calculate the heuristic value h of the current Pazz structure Q
	h := Heu(Q)

	// Base case: If the heuristic value h is 0, return the current count as the solution
	if h == 0 {
		return count
	}

	// Check if the current count plus the heuristic value h is greater than the maximum allowed count
	if (count+h) > max {
		return -1
	}

	// Iterate through all the possible moves from the current position (x,y)
	for i = 0; i < 4; i++ {
		// Calculate the new position (x0,y0) based on the current position (x,y) and the move i
		x0 = x + dx[i]
		y0 = y + dy[i]

		// Check if the new position (x0,y0) is valid or not
		if ((i == (n+2)%4 && n!= -1) ||!(0 <= x0 && x0 < 4 && 0 <= y0 && y0 < 4)) {
			continue
		}

		// Swap the current position (x,y) with the new position (x0,y0) in the Pazz structure Q
		temp = Q.P[y][x]
		Q.P[y][x] = Q.P[y0][x0]
		Q.P[y0][x0] = temp

		// Recursively call the function dfs with the new position (x0,y0), the maximum allowed count max, the current count+1, and the move i
		ans = dfs(x0, y0, max, count+1, i)

		// If the function call returns a valid solution, return it
		if ans!= -1 {
			return ans
		}

		// Swap back the current position (x,y) with the new position (x0,y0) in the Pazz structure Q
		temp = Q.P[y][x]
		Q.P[y][x] = Q.P[y0][x0]
		Q.P[y0][x0] = temp
	}

	// If no valid solution is found, return -1
	return -1
}

// Main function to read the input and call the function dfs to find the solution
func main() {
<<<<<<< HEAD
	var i, j int
	var kx, ky, ans, a int
=======
	var i, j int // Iterator variables
	var kx, ky, ans, a int // Local variables
	var tP Pazz // Temporary Pazz structure to store the original Pazz structure Q
>>>>>>> 98c87cb78a (data updated)

	// Initialize an empty Pazz structure Q
	for i = 0; i < 4; i++ {
		for j = 0; j < 4; j++ {
			// Read the input and store it in the Pazz structure Q
			a, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(1))))
			Q.P[i][j] = a
			if a == 0 {
				kx = j // Store the position of the empty cell in x direction
				ky = i // Store the position of the empty cell in y direction
			}
		}
	}

<<<<<<< HEAD
=======
	// Create a temporary Pazz structure tP to store the original Pazz structure Q
	tP = Q

>>>>>>> 98c87cb78a (data updated)
	// Call the function dfs with the initial position (kx,ky), the maximum allowed count 46, the initial count 0, and the initial move -1
	ans = dfs(kx, ky, 46, 0, -1)

	// If a valid solution is found, print it and exit the program
	if ans!= -1 {
		fmt.Printf("%d\n", ans)
		os.Exit(0)
	}

	// If no valid solution is found, print an error message and exit the program
	fmt.Printf("No solution found\n")
	os.Exit(1)
}

