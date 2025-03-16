<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a macro to return the absolute value of a number
const ABS = func(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	// Declare variables to store the values of N, t, x, y, and their initial positions nx, ny, and starting time nt
	var N, t, x, y, nx, ny, nt int
	// Declare loop counters
	var i, j, k, tmp int
	// Read the number of movements from the standard input
	fmt.Scanf("%d", &N)
	for i = 0; i < N; i++ {
		// Read the time and coordinates for each movement
		fmt.Scanf("%d%d%d", &t, &x, &y)
		tmp = t - nt - (ABS(x-nx) + ABS(y-ny))
		// Check if the difference is less than 0 or if it is odd
		if tmp < 0 || tmp%2!= 0 {
			fmt.Println("No")
			return
		}
		nx = x
		ny = y
		nt = t
	}
	fmt.Println("Yes")
}

