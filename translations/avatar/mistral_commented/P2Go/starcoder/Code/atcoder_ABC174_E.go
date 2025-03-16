
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to check if 'k' is positive after checking all elements in 'lis' with mid as divisor
func check(lis []int, k int, mid int) bool {
	// Iterate through each element in the list 'lis'
	for _, i := range lis {
		// If the element 'i' is divisible by'mid', increment 'k'
		if i%mid == 0 {
			k++
		}
		// Subtract the quotient of 'i' and'mid' from 'k'
		k -= i / mid
	}
	// Return True if 'k' is still positive after the loop, else False
	return k >= 0
}

// Function to find the answer
func find(n int, k int, lis []int) int {
	// Initialize the variables 'a' and 'b' with minimum and maximum values respectively
	a, b := 1, lis[0]
	// Initialize the variable 'ans' with the maximum value of 'b'
	ans := b
	// Binary search algorithm to find the answer
	for a <= b {
		// Calculate the middle value of 'a' and 'b'
		mid := (a + b) / 2
		// Check if 'k' is positive after checking all elements in 'lis' with'mid' as divisor
		if check(lis, k, mid) {
			// Update the answer if the condition is true
			ans = mid
			// Update the upper limit of the binary search 'b'
			b = mid - 1
		} else {
			// Update the lower limit of the binary search 'a'
			a = mid + 1
	}
	// Return the answer
	return ans
}

// Main function
func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the first line of input
	line, _ := reader.ReadString('\n')
	// Split the line into two space-separated integers
	n, k := strings.Split(line, " "), 0
	// Convert the first integer into an integer
	n, _ = strconv.Atoi(n[0])
	// Read the second line of input
	line, _ = reader.ReadString('\n')
	// Split the line into 'n' space-separated integers
	lis := strings.Split(line, " ")
	// Convert the integers into integers
	for i := 0; i < n; i++ {
		lis[i], _ = strconv.Atoi(lis[i])
	}
	// Call the function 'find' to find the answer
	ans := find(n, k, lis)
	// Print the answer
	fmt.Println(ans)
}

