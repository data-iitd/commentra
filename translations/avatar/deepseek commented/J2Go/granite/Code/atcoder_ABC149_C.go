
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"math"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a number: ")
	text, _ := reader.ReadString('\n')
	number, _ := strconv.Atoi(text)

	// Step 2: Check if the input is not equal to 2 and is even. If so, increment the input by 1.
	if number!= 2 && number%2 == 0 {
		number++
	}

	// Step 3: Enter a loop where it checks if the number is a prime number.
	for {
		i := 3
		sqrtNum := math.Sqrt(float64(number)) // Calculate the square root of the number

		// Step 4: Check for factors from 3 up to the square root of the number, incrementing by 2 (only odd numbers)
		for i <= int(sqrtNum) {
			if number%i == 0 {
				break // If a factor is found, break out of the loop
			}
			i += 2
		}

		// Step 5: If no factors are found and i is greater than the square root, the number is prime
		if i > int(sqrtNum) {
			break // Exit the loop once a prime number is found
		}

		// If the number is not prime, increment by 2 and check again
		number += 2
	}

	// Step 5: Print the prime number found
	fmt.Println(number)
}

