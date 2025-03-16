package main

import (
	"fmt"
)

var flag []int // Declare a global slice to keep track of prime numbers

// Function to mark non-prime numbers up to a given number 'num'
func prime(num int) {
	flag = make([]int, num+1) // Allocate memory for the flag slice

	for i := 2; i*i <= num; i++ { // Iterate to mark non-prime numbers
		if flag[i] == 0 { // If 'i' is a prime number
			for j := 2; i*j <= num; j++ { // Mark multiples of 'i' as non-prime
				flag[i*j] = 1
			}
		}
	}
}

// Main function to read an integer, calculate pairs of primes summing to 'n', and print the result
func main() {
	var n int // Declare variable to store input
	prime(50000) // Call the prime function to mark non-prime numbers up to 50000

	for {
		fmt.Scan(&n) // Read an integer 'n' from the user
		if n == 0 {
			break // Exit the loop if 'n' is zero
		}
		cnt := 0 // Initialize the count of pairs
		for i := 2; i*2 <= n; i++ { // Loop to find pairs of primes summing to 'n'
			if flag[i] == 0 && flag[n-i] == 0 { // Check if both 'i' and 'n-i' are prime
				cnt++ // Increment the count if a valid pair is found
			}
		}
		fmt.Println(cnt) // Print the count of pairs of primes summing to 'n'
	}
}

// <END-OF-CODE>
