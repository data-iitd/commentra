package main

import "fmt"

func main() {
	// Declare a variable to hold the size of the arrays
	var n int
	// Read the size of the arrays from standard input
	fmt.Scan(&n)

	// Initialize two slices: one for array 'as' with size n+1 and another for array 'bs' with size n
	as := make([]int, n+1)
	bs := make([]int, n)

	// Read values into the 'as' array
	for i := range as {
		fmt.Scan(&as[i])
	}

	// Read values into the 'bs' array
	for i := range bs {
		fmt.Scan(&bs[i])
	}

	// Initialize a variable to hold the cumulative sum
	var sum int
	// Iterate through the elements of the arrays
	for i := 0; i <= n-1; i++ {
		a := as[i] // Current element from 'as'
		b := bs[i] // Current element from 'bs'
		
		// Check if the current element of 'as' is less than or equal to the current element of 'bs'
		if a <= b {
			sum += a // Add 'a' to the sum
			b -= a   // Subtract 'a' from 'b'
			
			// Check if there is a next element in 'as'
			if i+1 <= n {
				an := as[i+1] // Next element from 'as'
				// Check if the next element of 'as' can be fully accommodated by the remaining 'b'
				if an <= b {
					sum += an // Add the next element to the sum
					as[i+1] = 0 // Set the next element to zero since it has been fully used
				} else {
					sum += b // Add the remaining 'b' to the sum
					as[i+1] -= b // Subtract the used portion from the next element of 'as'
				}
			}
		} else {
			// If 'a' is greater than 'b', add 'b' to the sum
			sum += b
		}
	}
	// Output the final computed sum
	fmt.Println(sum)
}
