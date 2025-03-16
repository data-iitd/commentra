
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Step 1: Reading the number of elements (n)
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr)

	// Step 2: Reading the list of elements (a)
	aStr, _ := reader.ReadString('\n')
	aStr = aStr[:len(aStr)-1]  // Remove the trailing newline character
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(aStr[i*2 : i*2+2])
	}

	// Step 3: Initializing variables
	pre := float64(1e9)  // Initialize pre to infinity
	ans := 0              // Initialize ans to 0

	// Step 4: Sorting the list in descending order
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if a[i] < a[j] {
				a[i], a[j] = a[j], a[i]
			}
		}
	}

	// Step 5: Iterating through the list
	for j := 0; j < n; j++ {
		// Calculate the maximum value that can be added to ans
		ans += int(max(0, min(pre-1, int64(a[j]))))
		// Update pre to be the maximum of 0 and the minimum of pre - 1 and the current element
		pre = max(0, min(pre-1, int64(a[j])))
	}

	// Step 6: Printing the result
	fmt.Println(ans)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

