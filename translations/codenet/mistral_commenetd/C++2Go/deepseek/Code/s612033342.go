package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to calculate 2 raised to the power of a given number
func pow2(a int) int {
	ret := 1
	for i := 0; i < a; i++ {
		ret *= 2
	}
	return ret
}

// Function to count the number of 1's in the given 2D grid that match the binary representation of a and b
func count(hw [][]int, a int, b int) int {
	sum := 0
	for i := 0; i < len(hw); i++ {
		for j := 0; j < len(hw[0]); j++ {
			if (a & (1 << i)) != 0 && (b & (1 << j)) != 0 && hw[i][j] == 1 {
				sum++
			}
		}
	}
	return sum
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read input values for height, width, and target count
	var h, w, k int
	scanner.Scan()
	h, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	w, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ = strconv.Atoi(scanner.Text())

	// Initialize 2D grid with zeroes
	hw := make([][]int, h)
	for i := 0; i < h; i++ {
		hw[i] = make([]int, w)
		for j := 0; j < w; j++ {
			hw[i][j] = 0
		}
	}

	// Read the grid from standard input
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			var c string
			scanner.Scan()
			c = scanner.Text()
			if c == "#" {
				hw[i][j] = 1
			}
		}
	}

	sum := 0
	// Iterate through all possible binary combinations of height
	for i := 0; i < pow2(h); i++ {
		// Iterate through all possible binary combinations of width
		for j := 0; j < pow2(w); j++ {
			if count(hw, i, j) == k {
				sum++
			}
		}
	}

	// Output the final sum to standard output
	fmt.Println(sum)
}

