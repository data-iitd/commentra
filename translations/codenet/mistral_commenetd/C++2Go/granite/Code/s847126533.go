
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var m int
	var n int
	for scanner.Scan() {
		m = scanInt()
		if m == 0 {
			break
		}
		n = scanInt()
		book := make([]int, n)
		for i := 0; i < n; i++ {
			book[i] = scanInt()
		}
		sort.Ints(book)
		l := 0
		r := 1500000
		ans := 0
		for l < r {
			mid := (l + r) / 2
			if check(m, mid, book) {
				ans = mid
				r = mid
			} else {
				l = mid + 1
			}
		}
		fmt.Println(ans)
	}
}

func scanInt() int {
	i := 0
	for scanner.Scan() {
		num, err := strconv.Atoi(scanner.Text())
		if err!= nil {
			panic(err)
		} else {
			i = num
			break
		}
	}
	return i
}

Translate the above Go code to Python and end with comment "