<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Function to check if a weight can be carried by a knapsack of capacity 'wei'
func check(n int, wei int, book []int) bool {
	tmp := wei // Initialize temporary variable 'tmp' to 'wei'
	n--        // Decrement 'n' (number of items left to be put in the knapsack)

	// Loop through all the items in the vector 'book'
	for i := 0; i < len(book); i++ {
		// If the weight of the current item is greater than the remaining capacity,
		// check if there is still room for more items by decrementing 'n' and resetting 'tmp' to 'wei'
		if tmp < book[i] {
			if n > 0 { // If there are still items left to be put in the knapsack
				n-- // Decrement 'n'
				tmp = wei // Reset 'tmp' to 'wei'
				// Check if the current weight is less than the weight of the current item
				if tmp < book[i] {
					return false
				}
			} else { // If there are no more items left to be put in the knapsack
				return false
			}
		}

		// Subtract the weight of the current item from the remaining capacity
		tmp -= book[i]
	}

	// If all items have been considered and the remaining capacity is still greater than zero,
	// then the given weight can be carried by the knapsack
	return true
}

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Loop through the input until the end of the file is reached
	for {
<<<<<<< HEAD
		// Read the first line of input
=======
		// Read a line of input
>>>>>>> 98c87cb78a (data updated)
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}

<<<<<<< HEAD
		// Split the line into two space-separated integers
		line = strings.TrimSpace(line)
		m, n := strings.Split(line, " ")
		m, _ = strconv.Atoi(m)
		n, _ = strconv.Atoi(n)

		// If'm' is zero, then the input has ended
		if m == 0 {
			break
		}

		// Initialize an empty vector 'book' to store the weights of the items
		book := make([]int, n)

		// Loop through all the items and add their weights to the vector 'book'
		for i := 0; i < n; i++ {
			line, err = reader.ReadString('\n')
			if err!= nil {
				break
			}

			// Split the line into one integer
			line = strings.TrimSpace(line)
			book[i], _ = strconv.Atoi(line)
=======
		// Split the line into a slice of strings
		line = strings.Split(line, " ")

		// Convert the first string in the slice to an integer
		m, _ := strconv.Atoi(line[0])

		// Convert the second string in the slice to an integer
		n, _ := strconv.Atoi(line[1])

		// Initialize an empty slice to store the weights of the items
		book := make([]int, n)

		// Loop through all the items and add their weights to the slice 'book'
		for i := 0; i < n; i++ {
			// Convert the next string in the slice to an integer
			book[i], _ = strconv.Atoi(line[i+2])
>>>>>>> 98c87cb78a (data updated)
		}

		// Use binary search to find the maximum weight that can be carried by the knapsack
		l := 0
		r := 1500000
		ans := 0
		for l < r {
			// Calculate the middle value of the range [l, r]
			mid := (l + r) / 2

			// If the middle value can be carried by the knapsack, update 'ans' and shrink the range to [l, mid]
			if check(m, mid, book) {
				ans = mid
				r = mid
			}
			// If the middle value cannot be carried by the knapsack, shrink the range to [mid+1, r]
			else {
				l = mid + 1
			}
		}

		// Output the maximum weight that can be carried by the knapsack
		fmt.Println(ans)
	}
}

