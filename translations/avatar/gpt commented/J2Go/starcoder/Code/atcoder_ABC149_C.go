package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"math"
)

func main() {
	// Create a new Scanner to read input from stdin
	scanner := bufio.NewScanner(os.Stdin)

	// Read an integer input from stdin
	scanner.Scan()
	x, _ := strconv.Atoi(scanner.Text())

	// If x is even and not equal to 2, increment x to make it odd
	if x!= 2 && x % 2 == 0 {
		x++
	}

	// Infinite loop to find the next prime number
	for {
		i := 3
		sqrtNum := math.Sqrt(float64(x))

		// Check for factors of x from 3 to the square root of x, incrementing by 2 (to check only odd numbers)
		for i <= int(sqrtNum) {
			// If i divides x, then x is not prime
			if x % i == 0 {
				break
			}
			i += 2
		}

		// If no divisors were found, i will be greater than sqrtNum, indicating x is prime
		if i > int(sqrtNum) {
			break
		}

		// Increment x by 2 to check the next odd number
		x += 2
	}

	// Output the next prime number
	fmt.Println(x)
}

