
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

func main() {
	// Declare an integer array 'c' of size 3 to store the input values
	c := make([]int, 3)

	// Start an infinite loop to read input values until EOF is reached
	for {
		// Read input values from stdin
		fmt.Scanf("%d %d %d", &c[0], &c[1], &c[2])

		// Check if EOF has been reached
		if fmt.Scanf("%s", &c[0]) == 0 {
			break
		}

		// Declare and initialize a character array 'card' of size 10 with all elements set to zero
		card := make([]byte, 10)
		for i := 0; i < 10; i++ {
			card[i] = 0
		}

		// Loop through the array 'c' to mark the corresponding index in 'card' array
		for i := 0; i < 3; i++ {
			card[c[i]-1] = 1
		}

		// Initialize count with 0
		count := 0

		// Loop through the array 'card' to check if there are at least 4 distinct numbers in the input
		for i := 0; i < 10; i++ {
			// If the index in 'card' array is not set to 1 and the sum of input values, index and 1 is less than or equal to 20
			if card[i] == 0 && c[0]+c[1]+i+1 <= 20 {
				count++
			}
		}

		// Check if the count is greater than or equal to 4 and print "YES" if true, otherwise print "NO"
		if count >= 4 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

