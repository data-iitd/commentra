package main

import (
	"fmt"
	"runtime"
	"unsafe"
)

var flag []int

// Function to mark non-prime numbers up to a given number 'num'
func prime(num int) {
	i, j := 0, 0 // Declare loop variables

	flag = make([]int, num+1) // Allocate memory for the flag array

	for i = 2; i*i <= num; i++ { // Iterate to mark non-prime numbers
		if flag[i] == 0 { // If 'i' is a prime number
			for j = 2; i*j <= num; j++ { // Mark multiples of 'i' as non-prime
				flag[i*j] = 1
			}
		}
	}
}

// Main function to read an integer, calculate pairs of primes summing to 'n', and print the result
func main() {
	var n, i, cnt int // Declare variables to store input, loop index, and count of pairs

	prime(50000) // Call the prime function to mark non-prime numbers up to 50000

	for { // Infinite loop to read input until 'n' is zero
		_, err := fmt.Scan(&n) // Read an integer 'n' from the user
		if err != nil {
			break // Exit the loop if an error occurs
		}
		if n == 0 {
			break // Exit the loop if 'n' is zero
		}
		i = 2 // Initialize the starting prime number
		cnt = 0 // Initialize the count of pairs
		for i*2 <= n { // Loop to find pairs of primes summing to 'n'
			if flag[i] == 0 && flag[n-i] == 0 { // Check if both 'i' and 'n-i' are prime
				cnt++ // Increment the count if a valid pair is found
			}
			i++ // Move to the next potential prime number
		}
		fmt.Println(cnt) // Print the count of pairs of primes summing to 'n'
	}
}

