package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N) // Reading the first integer value from the standard input stream

	count := 0 // Initializing the counter variable 'count' to zero
	temp := N  // Assigning the value of 'N' to the variable 'temp'

	// The following loop calculates the number of digits in the given integer 'N'
	for temp > 0 {
		temp /= 10 // Dividing the current value of 'temp' by 10 to get the last digit
		count++    // Incrementing the counter variable 'count' by 1
	}

	ans := 0 // Initializing the answer variable 'ans' to zero

	for i := 1; i <= count; i++ { // The following loop iterates through each digit of the given integer 'N'
		if i == count { // If the current digit is the last digit
			if N%10%2 == 1 { // If the last digit is odd
				ans += (N - int(math.Pow(10, float64(i-1))) + 1) // Adding the sum of digits before the last odd digit to the answer
			}
		} else { // If the current digit is not the last digit
			if i == 1 { // If the current digit is the first digit
				ans += 9 // Adding the number of digits after the first digit to the answer
			} else if i%2 == 1 { // If the current digit is odd
				ans += (int(math.Pow(10, float64(i))) - int(math.Pow(10, float64(i-1)))) // Adding the difference between the 10 raised to the power of the current digit and the 10 raised to the power of the previous digit to the answer
			}
		}
	}

	fmt.Println(ans) // Printing the final answer to the standard output stream
}

// <END-OF-CODE>
