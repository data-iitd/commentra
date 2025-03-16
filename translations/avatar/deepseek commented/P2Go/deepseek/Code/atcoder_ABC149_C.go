package main

import (
	"fmt"
)

func main() {
	var X int
	fmt.Scan(&X) // Take an integer input from the user and store it in X

	prime := make([]bool, 100010) // Initialize a slice 'prime' with 100010 elements, all set to True
	for i := 0; i < 100010; i++ {
		prime[i] = true
	}
	prime[0] = false // 0 is not a prime number
	prime[1] = false // 1 is not a prime number

	// Mark all even numbers (except 2) as not prime
	for i := 4; i < 100010; i += 2 {
		prime[i] = false
	}

	// Use a while loop to mark non-prime numbers using the Sieve of Eratosthenes algorithm
	i := 3
	for (i * i <= 100008) {
		if prime[i] {
			for j := i + i; j <= 100008; j += i {
				prime[j] = false
			}
		}
		i += 2
	}

	// Iterate through the range from X to 100008 and print the first prime number found
	for i := X; i <= 100008; i++ {
		if prime[i] {
			fmt.Println(i)
			break
		}
	}
}

