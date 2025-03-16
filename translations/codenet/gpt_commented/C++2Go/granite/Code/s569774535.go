
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of elements
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr)

	// Initialize a slice to store the elements
	a := make([]int, n)

	// Input the elements into the slice
	for i := 0; i < n; i++ {
		aStr, _ := reader.ReadString('\n')
		a[i], _ = strconv.Atoi(aStr)
	}

	// Initialize the answer counter and a flag for the loop
	ans := 0
	ok := true

	// Loop until an odd number is found in the slice
	for ok {
		// Check each element in the slice
		for i := 0; i < n; i++ {
			// If the current element is odd, print the answer and exit
			if a[i]%2 == 1 {
				fmt.Println(ans)
				return
			}
			// If the current element is even, divide it by 2
			else {
				a[i] /= 2
			}
		}
		// Increment the answer counter for each complete iteration
		ans++
	}

	// Output the final count of divisions by 2 before encountering an odd number
	fmt.Println(ans)
}

