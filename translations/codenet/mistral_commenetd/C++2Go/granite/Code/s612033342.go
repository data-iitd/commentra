

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func pow2(a int) int {
	ret := 1 // Initialize result to 1
	for i := 0; i < a; i++ { // Iterate through each bit of the input number
		ret *= 2 // Multiply result by 2 for each iteration of the loop
	}
	return ret // Return the final result
}

func count(hw [][]int, a int, b int) int {
	sum := 0 // Initialize sum to 0
	for i := 0; i < len(hw); i++ { // Iterate through each row of the 2D grid
		for j := 0; j < len(hw[0]); j++ { // Iterate through each column of the current row
			if (a&(1<<i))!= 0 && (b&(1<<j))!= 0 && hw[i][j] == 1 { // If the bits at the corresponding positions in a and b are set and the corresponding cell in the grid is 1, increment sum
				sum++
			}
		}
	}
	return sum // Return the final sum
}

func main() {
	scanner := bufio.NewScanner(os.Stdin) // Create a scanner to read input from standard input
	var h, w, k int // Declare variables for height, width, and target count
	fmt.Fscan(scanner, &h, &w, &k) // Read input values for height, width, and target count from standard input
	hw := make([][]int, h) // Initialize 2D grid with zeroes
	for i := 0; i < h; i++ { // Iterate through each row of the 2D grid
		hw[i] = make([]int, w) // Initialize the current row with zeroes
		line, _ := scanner.ReadString('\n') // Read the current line from standard input
		for j := 0; j < w; j++ { // Iterate through each column of the current row
			if line[j] == '#' { // If the character at the current position is '#', set the corresponding cell in the grid to 1
				hw[i][j] = 1
			}
		}
	}
	sum := 0 // Initialize sum to 0
	for i := 0; i < pow2(h); i++ { // Iterate through all possible binary combinations of height
		for j := 0; j < pow2(w); j++ { // Iterate through all possible binary combinations of width
			if count(hw, i, j) == k { // If the number of 1's in the current combination matches the target count, increment sum
				sum++
			}
		}
	}
	fmt.Println(sum) // Output the final sum to standard output
}

