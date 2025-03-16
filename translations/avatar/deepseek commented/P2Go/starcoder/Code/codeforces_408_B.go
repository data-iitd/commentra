
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Helper functions to pop and push elements from/to the heap
func hpop(h []int) int {
	v := h[0]
	h[0] = h[len(h)-1]
	h = h[:len(h)-1]
	return v
}

func hpush(h []int, v int) {
	h = append(h, v)
	i := len(h) - 1
	for ; i > 0 && h[i/2] > h[i]; i /= 2 {
		h[i/2], h[i] = h[i], h[i/2]
	}
}

func solution() {
	// Read the first line of input and create a Counter object for the bought colors
	line := bufio.NewReader(os.Stdin).ReadString('\n')
	bought_count := make(map[string]int)
	for _, c := range strings.Split(line[:len(line)-1], " ") {
		bought_count[c]++
	}

	// Read the second line of input and create a Counter object for the colors to be made
	line = bufio.NewReader(os.Stdin).ReadString('\n')
	made_count := make(map[string]int)
	for _, c := range strings.Split(line[:len(line)-1], " ") {
		made_count[c]++
	}

	// Initialize the result variable to store the total number of colors that can be made
	res := 0

	// Iterate over each color in the'made_cout' Counter
	for color := range made_count {
		// Check if the color is not in the 'bought_count' Counter
		if _, ok := bought_count[color];!ok {
			// If a color is not bought, print -1 and exit
			fmt.Println(-1)
			return
		}
		// Calculate the minimum of the counts of the current color in both 'bought_count' and'made_cout'
		// and add this to the result
		res += min(bought_count[color], made_count[color])
	}

	// Print the final result
	fmt.Println(res)
}

func main() {
	// Set the number of test cases to 1
	t := 1
	// Run the solution function for one test case
	for i := 0; i < t; i++ {
		solution()
	}
}

