
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Define a lambda function to read a list of integers from input
	na := func() []int {
		scanner := bufio.NewScanner(os.Stdin)
		scanner.Scan()
		line := scanner.Text()
		parts := strings.Split(line, " ")
		var a []int
		for _, part := range parts {
			i, _ := strconv.Atoi(part)
			a = append(a, i)
		}
		return a
	}

	// Read the number of elements (n) and the initial value (x) from input
	n, x := na()[0], na()[0]

	// Read and sort the list of integers
	a := na()
	sort.Ints(a)

	// Initialize the answer counter
	ans := 0

	// Check if the smallest element in the sorted list is greater than x
	if a[0] > x {
		// If true, print 0 and exit since no elements can be subtracted from x
		fmt.Println(0)
		return
	}

	// Iterate through the sorted list of integers
	for _, i := range a {
		// If the current element is greater than x, set x to 0 and break the loop
		if i > x {
			x = 0
			break
		}
		// Subtract the current element from x
		x -= i
		// Increment the answer counter
		ans += 1
	}

	// If there is any remaining value in x, decrement the answer counter
	if x!= 0 {
		ans -= 1
	}

	// Print the final answer
	fmt.Println(ans)
}
