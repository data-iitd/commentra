
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Initialize scanner
var sc = bufio.NewScanner(os.Stdin)
sc.Split(bufio.ScanWords)

func main() {
	// Read the number of elements n and m from the standard input
	n := nextInt()
	m := nextInt()

	// Initialize h array with n elements and good array with n boolean values
	h := make([]int, n)
	good := make([]bool, n)

	// Read n integers from the standard input and initialize h and good arrays
	for i := 0; i < n; i++ {
		h[i] = nextInt()
		// Set good[i] to true initially
		good[i] = true
	}

	// Process m queries
	for i := 0; i < m; i++ {
		// Read two integers ai and bi from the standard input
		ai := nextInt() - 1
		bi := nextInt() - 1

		// Compare the heights of h[ai] and h[bi]
		if h[ai] > h[bi] {
			// If h[ai] is greater than h[bi], mark good[bi] as false
			good[bi] = false
		} else if h[ai] < h[bi] {
			// If h[ai] is less than h[bi], mark good[ai] as false
			good[ai] = false
		} else {
			// If heights are equal, mark both good[ai] and good[bi] as false
			good[ai] = false
			good[bi] = false
		}
	}

	// Initialize answer variable ans to 0
	ans := 0

	// Count the number of good elements in the h array
	for i := 0; i < n; i++ {
		if good[i] {
			// Increment ans if good[i] is true
			ans++
		}
	}

	// Print the answer
	fmt.Println(ans)
}

func nextInt() int {
	// Read an integer from the standard input and convert it to an integer
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		// If there is an error, panic with the error message
		panic(e)
	}
	return i
}

