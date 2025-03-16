
package main

import "fmt"

func main() {
	// Initialize variables
	var n int

	// Read the number of elements from the standard input
	fmt.Scan(&n)

	as := make([]int, n+1) // Initialize array 'as' with size n+1
	bs := make([]int, n)   // Initialize array 'bs' with size n

	// Read elements of array 'as' from the standard input
	for i := range as {
		fmt.Scan(&as[i])
	}

	// Read elements of array 'bs' from the standard input
	for i := range bs {
		fmt.Scan(&bs[i])
	}

	// Initialize variable 'sum' to 0
	var sum int

	// Iterate through each index 'i' of arrays 'as' and 'bs'
	for i := 0; i <= n-1; i++ {
		// Assign the value of 'as[i]' to variable 'a'
		a := as[i]

		// Assign the value of 'bs[i]' to variable 'b'
		b := bs[i]

		// If 'a' is less than or equal to 'b', add 'a' to 'sum' and subtract 'a' from 'b'
		if a <= b {
			sum += a
			b -= a
		}

		// If there is an element after 'as[i]', check if it can be added to 'sum'
		if i+1 <= n {
			// Assign the value of 'as[i+1]' to variable 'an'
			an := as[i+1]

			// If 'an' is less than or equal to 'b', add 'an' to 'sum' and set 'as[i+1]' to 0
			if an <= b {
				sum += an
				as[i+1] = 0
			} else {
				// If 'an' is greater than 'b', add 'b' to 'sum' and subtract 'b' from 'an'
				sum += b
				as[i+1] -= b
			}
		}
	}

	// Print the final result 'sum' to the standard output
	fmt.Println(sum)
}

