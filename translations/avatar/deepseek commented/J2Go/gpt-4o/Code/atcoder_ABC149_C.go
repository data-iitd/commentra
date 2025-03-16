package main

import (
	"fmt"
	"math"
)

func main() {
	var x int
	fmt.Scan(&x) // Reading an integer input from the user

	// Step 2: Check if the input is not equal to 2 and is even. If so, increment the input by 1.
	if x != 2 && x%2 == 0 {
		x++
	}

	// Step 3: Enter a loop where it checks if the number is a prime number.
	for {
		sqrtNum := math.Sqrt(float64(x)) // Calculate the square root of the number

		// Step 4: Check for factors from 3 up to the square root of the number, incrementing by 2 (only odd numbers)
		isPrime := true
		for i := 3; float64(i) <= sqrtNum; i += 2 {
			if x%i == 0 {
				isPrime = false // If a factor is found, mark as not prime
				break
			}
		}

		// Step 5: If no factors are found, the number is prime
		if isPrime {
			break // Exit the loop once a prime number is found
		}

		// If the number is not prime, increment by 2 and check again
		x += 2
	}

	// Step 5: Print the prime number found
	fmt.Println(x)
}

// <END-OF-CODE>
