package main

import (
	"fmt"
)

func main() {
	var a, b, c, i, j, k int // Initialize variables a, b, c, i, j, and k of integer data type
	var max int              // Initialize variable max of integer data type

	fmt.Print("Enter the number of test cases: ") // Prompt user to enter the number of test cases
	fmt.Scan(&j) // Read the number of test cases from the user and store it in variable j

	for i = 0; i < j; i++ { // Loop through each test case
		fmt.Printf("Enter the values of a, b, and c for test case %d: ", i+1) // Prompt user to enter the values of a, b, and c for the current test case
		fmt.Scan(&a) // Read the value of a from the user and store it in variable a
		fmt.Scan(&b) // Read the value of b from the user and store it in variable b
		fmt.Scan(&c) // Read the value of c from the user and store it in variable c

		max = a // Initialize max with the value of a
		k = 0   // Initialize k with 0

		if max <= b { // Check if max is less than or equal to b
			max = b // If true, update max with the value of b
			k = 1   // Set k to 1 to indicate that b is greater than a
		}

		if max <= c { // Check if max is less than or equal to c
			max = c // If true, update max with the value of c
			k = 2   // Set k to 2 to indicate that c is greater than max (which was previously a or b)
		}

		max *= max // Multiply max with itself to calculate max*max
		a *= a     // Multiply a with itself to calculate a*a
		b *= b     // Multiply b with itself to calculate b*b
		c *= c     // Multiply c with itself to calculate c*c

		if k == 0 && max == b+c { // Check if k is 0 and max is equal to the sum of b and c
			fmt.Println("YES") // If true, print "YES" to the console
		} else if k == 1 && max == a+c { // Check if k is 1 and max is equal to the sum of a and c
			fmt.Println("YES") // If true, print "YES" to the console
		} else if k == 2 && max == a+b { // Check if k is 2 and max is equal to the sum of a and b
			fmt.Println("YES") // If true, print "YES" to the console
		} else { // If none of the above conditions are true
			fmt.Println("NO") // Print "NO" to the console
		}
	}
}

// <END-OF-CODE>
