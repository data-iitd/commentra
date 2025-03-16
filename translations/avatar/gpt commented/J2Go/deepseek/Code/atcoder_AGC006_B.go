package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, x int
	fmt.Scan(&n, &x)
	print(x, n)
}

func print(x, n int) {
	// Calculating the maximum value based on n
	max := n*2 - 1
	
	// Checking if x is equal to 1 or max, if so, print "No" and return
	if x == 1 || x == max {
		fmt.Println("No")
		return
	}
	
	// If x is valid, print "Yes"
	fmt.Println("Yes")
	
	// Prepare the line separator for formatting output
	sep := "\n"
	
	// Generate a sequence of numbers based on the input x and n
	var ans strings.Builder
	for i := x + n - 1; i < x + n + max - 1; i++ {
		ans.WriteString(fmt.Sprintf("%d%s", (i % max + 1), sep))
	}
	
	// Print the generated sequence
	fmt.Print(ans.String())
}

