package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Computes 2^a
func pow2(a int) int {
	ret := 1
	for i := 0; i < a; i++ {
		ret *= 2
	}
	return ret
}

// Counts the number of 1s in the grid hw where both the i-th row and the j-th column are selected
func count(hw [][]int, a int, b int) int {
	sum := 0
	for i := 0; i < len(hw); i++ {
		for j := 0; j < len(hw[0]); j++ {
			if a&(1<<i) != 0 && b&(1<<j) != 0 && hw[i][j] == 1 {
				sum++
			}
		}
	}
	return sum
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	inputs := strings.Split(scanner.Text(), " ")
	h, _ := strconv.Atoi(inputs[0])
	w, _ := strconv.Atoi(inputs[1])
	k, _ := strconv.Atoi(inputs[2])

	// Initialize the grid with dimensions h x w, filled with 0s
	hw := make([][]int, h)
	for i := range hw {
		hw[i] = make([]int, w)
	}

	// Read the grid and set 1s where there is a '#'
	for i := 0; i < h; i++ {
		scanner.Scan()
		line := scanner.Text()
		for j := 0; j < w; j++ {
			if line[j] == '#' {
				hw[i][j] = 1
			}
		}
	}

	sum := 0

	// Iterate over all possible combinations of row and column selections
	for i := 0; i < pow2(h); i++ {
		for j := 0; j < pow2(w); j++ {
			if count(hw, i, j) == k {
				sum++ // Check if the condition is met and sum the valid combinations
			}
		}
	}

	// Output the result
	fmt.Println(sum)
}
