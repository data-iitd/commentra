package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to check if 'k' is positive after checking all elements in 'lis' with mid as divisor
func check(lis []int, k, mid int) bool {
	// Iterate through each element in the list 'lis'
	for _, i := range lis {
		// If the element 'i' is divisible by 'mid', increment 'k'
		if i % mid == 0 {
			k += 1
		}
		// Subtract the quotient of 'i' and 'mid' from 'k'
		k -= (i / mid)
	}
	// Return true if 'k' is still positive after the loop, else false
	return k >= 0
}

func main() {
	// Create a new scanner to read input
	scanner := bufio.NewScanner(os.Stdin)

	// Scan for 'n' and 'k'
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())

	// Scan for 'n' number of elements in the list 'lis' and store them in a slice
	scanner.Scan()
	lisStr := scanner.Text()
	lis := []int{}
	for _, numStr := range strings.Split(lisStr, " ") {
		num, _ := strconv.Atoi(numStr)
		lis = append(lis, num)
	}

	// Initialize the variables 'a' and 'b' with minimum and maximum values respectively
	a, b := 1, lis[0]
	for _, num := range lis {
		if num > b {
			b = num
		}
	}

	// Initialize the variable 'ans' with the maximum value of 'b'
	ans := b

	// Binary search algorithm to find the answer
	for a <= b {
		// Calculate the middle value of 'a' and 'b'
		mid := (a + b) / 2
		// Check if 'k' is positive after checking all elements in 'lis' with 'mid' as divisor
		if check(lis, k, mid) {
			// Update the answer if the condition is true
			ans = mid
			// Update the upper limit of the binary search 'b'
			b = mid - 1
		} else {
			// Update the lower limit of the binary search 'a'
			a = mid + 1
		}
	}

	// Print the answer
	fmt.Println(ans)
}
