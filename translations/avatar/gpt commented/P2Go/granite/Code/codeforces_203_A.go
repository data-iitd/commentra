
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input values and split them into a list
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	xxs := strings.Split(input, " ")

	// Convert the input strings to integers
	x, t, a, b, da, db := 0, 0, 0, 0, 0, 0
	for i := 0; i < len(xxs); i++ {
		xx, _ := strconv.Atoi(xxs[i])
		switch i {
		case 0:
			x = xx
		case 1:
			t = xx
		case 2:
			a = xx
		case 3:
			b = xx
		case 4:
			da = xx
		case 5:
			db = xx
		}
	}

	// Check if the target value x is zero
	if x == 0 {
		fmt.Println("YES") // If x is zero, print "YES" and return
		return
	}

	// Calculate the maximum time available for a and b, constrained by t
	aTime := min(a/da, t-1)
	bTime := min(b/db, t-1)

	// Iterate through all possible values of i and j within the calculated time limits
	for i := 0; i <= aTime; i++ {
		for j := 0; j <= bTime; j++ {
			// Check if either a or b can be reduced to x by subtracting multiples of da or db
			if a-da*i == x || b-db*j == x {
				fmt.Println("YES") // If found, print "YES" and return
				return
			}
			// Check if the sum of the remaining values of a and b equals x
			if (a-da*i)+(b-db*j) == x {
				fmt.Println("YES") // If found, print "YES" and return
				return
			}
		}
	}

	// If no valid combination is found, print "NO"
	fmt.Println("NO")
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

