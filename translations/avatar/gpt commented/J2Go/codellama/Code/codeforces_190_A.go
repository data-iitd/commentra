package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read two integers n and m from the input
	var n, m int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	m, _ = strconv.Atoi(sc.Text())

	// Check if n is zero
	if n == 0 {
		// If m is not zero, print "Impossible" since we cannot form a valid output
		if m != 0 {
			fmt.Println("Impossible")
		}
		// If m is also zero, print "0 0" as the valid output
		else {
			fmt.Println(0, 0)
		}
		return
	}

	// Check if m is less than or equal to n
	if m <= n {
		// If m is zero, set it to one to ensure valid output
		if m == 0 {
			m = 1
		}
		// Print n and the adjusted value of m
		fmt.Println(n, m+n-1)
		return
	}

	// If m is greater than n, print m and the adjusted value of m
	fmt.Println(m, m+n-1)
}

