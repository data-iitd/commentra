package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from standard input
	var input string
	fmt.Scanln(&input)

	// Split the input string into parts
	xxs := strings.Split(input, " ")
	x, _ := strconv.Atoi(xxs[0])
	t, _ := strconv.Atoi(xxs[1])
	a, _ := strconv.Atoi(xxs[2])
	b, _ := strconv.Atoi(xxs[3])
	da, _ := strconv.Atoi(xxs[4])
	db, _ := strconv.Atoi(xxs[5])

	// Check if the value of x is 0
	if x == 0 {
		fmt.Println("YES")
		return
	}

	// Calculate the maximum number of times a and b can be decremented within the time limit t
	aTime := min(a/da, t-1)
	bTime := min(b/db, t-1)

	// Iterate over all possible combinations of decrements for a and b within their respective limits
	for i := 0; i <= aTime; i++ {
		for j := 0; j <= bTime; j++ {
			// Check if either a or b (or their sum) equals x
			if a-da*i == x || b-db*j == x {
				fmt.Println("YES")
				return
			}
			if (a - da*i) + (b - db*j) == x {
				fmt.Println("YES")
				return
			}
		}
	}

	// Print "NO" if no combination results in x
	fmt.Println("NO")
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
