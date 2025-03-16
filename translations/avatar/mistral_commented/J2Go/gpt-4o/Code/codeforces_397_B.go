package main

import (
	"fmt"
)

const MOD = 1e9 + 7 // Declaring a constant named MOD

func main() {
	var t int
	fmt.Scan(&t) // Reading the number of test cases

	for t > 0 {
		t-- // Decrementing the test case counter
		var n, a, b int64
		fmt.Scan(&n, &a, &b) // Reading the values of n, a, and b

		if n < a { // Checking if n is less than a
			fmt.Println("No") // If true, printing "No" and continuing to the next test case
			continue // Using continue to skip the rest of the current iteration
		}

		if a == b { // Checking if a is equal to b
			if n%a == 0 { // Checking if n is divisible by a
				fmt.Println("Yes") // If true, printing "Yes"
			} else { // If false
				fmt.Println("No") // Printing "No"
			}
			continue // Using continue to skip the rest of the current iteration
		}

		x := b / (b - a) // Calculating the value of x
		if n > x*a { // Checking if n is greater than x * a
			fmt.Println("Yes") // If true, printing "Yes" and continuing to the next test case
			continue // Using continue to skip the rest of the current iteration
		}

		low := int64(1) // Initializing a variable named low to 1
		high := x + 1   // Initializing a variable named high to x + 1
		ans := int64(1) // Initializing a variable named ans to 1

		for low <= high { // Starting a loop that runs until low is less than or equal to high
			mid := (low + high) / 2 // Calculating the middle value of low and high
			if mid*a < n { // Checking if mid * a is less than n
				low = mid + 1 // If true, setting low to mid + 1
			} else { // If false
				ans = mid // Setting ans to mid
				high = mid - 1 // Setting high to mid - 1
			}
		}

		if n > (ans-1)*b && n < ans*a { // Checking if n is between (ans - 1) * b and ans * a
			fmt.Println("No") // If true, printing "No"
		} else { // If false
			fmt.Println("Yes") // Printing "Yes"
		}
	}
}

// <END-OF-CODE>
