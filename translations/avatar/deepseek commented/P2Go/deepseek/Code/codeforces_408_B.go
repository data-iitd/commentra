package main

import (
	"bufio"
	"fmt"
	"collections"
	"functools"
	"heapq"
	"sort"
	"strconv"
	"strings"
)

// Helper functions to pop and push elements from/to the heap
func hpop(h *heapq.PriorityQueue) (interface{}, bool) {
	if h.Len() == 0 {
		return nil, false
	}
	return h.Pop(h)
}

func hpush(h *heapq.PriorityQueue, x interface{}) {
	h.Push(h, x)
}

func solution() {
	// Read the first line of input and create a Counter object for the bought colors
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	split := strings.Split(line, "")
	boughtCount := make(map[string]int)
	for _, color := range split {
		boughtCount[color]++
	}

	// Read the second line of input and create a Counter object for the colors to be made
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	split = strings.Split(line, "")
	madeCount := make(map[string]int)
	for _, color := range split {
		madeCount[color]++
	}

	// Initialize the result variable to store the total number of colors that can be made
	res := 0

	// Iterate over each color in the 'madeCount' Counter
	for color := range madeCount {
		// Check if the color is not in the 'boughtCount' Counter
		if _, exists := boughtCount[color]; !exists {
			// If a color is not bought, print -1 and exit
			fmt.Println(-1)
			return
		}
		// Calculate the minimum of the counts of the current color in both 'boughtCount' and 'madeCount'
		// and add this to the result
		res += min(boughtCount[color], madeCount[color])
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
