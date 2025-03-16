<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Array to store the result of prime factorization
var kekka [2]int

// Array to determine if a number is prime or not (0 for prime, 1 for not prime)
var prime_or_not [1001]int

// Array to store prime numbers
var prime_list [1001]int

// Array to store the power of each prime factor
var prime_num [1001]int

// Counter to keep track of the number of prime numbers found
var prime_counter int = 0

// Function to find all prime numbers up to 1000
func sosuubunnpu(){
	// Initialize the prime_or_not array to 0 (indicating all numbers are potential primes)
	for i := 1; i <= 1000; i++ {
		prime_or_not[i] = 0
	}

	// Mark non-prime numbers using the Sieve of Eratosthenes algorithm
	for i := 2; i <= 1000; i++ {
<<<<<<< HEAD
		for j := 2; j <= int(math.Floor(float64(1000/i))); j++ {
=======
		for j := 2; j <= int(math.Floor(float64(1000)/float64(i))); j++ {
>>>>>>> 98c87cb78a (data updated)
			if prime_or_not[i] == 0 {
				prime_or_not[i*j] = 1
			}
		}
	}

	// Collect all prime numbers into the prime_list array
	for i := 2; i <= 1000; i++ {
		if prime_or_not[i] == 0 {
			prime_list[prime_counter] = i
			prime_counter++
		}
	}
}

// Function to find the power of a prime factor in the factorization of a number
func innsuubunnkai(N int, n int){
	time := 0
	for {
		if N%n == 0 {
			N = N/n
			time++
		}else{
			break
		}
	}
	kekka[0] = time
	kekka[1] = N
}

func main() {
	// Call the function to find all prime numbers up to 1000
	sosuubunnpu()

	// Read the integer N
	var N int
	fmt.Scanf("%d\n", &N)

	// Initialize arrays to store the prime factorization of numbers up to N
<<<<<<< HEAD
	innsuu := make([]int, 11)
	A := make([][]int, N+1)
=======
	var innsuu [11]int
	var A [N+1][11]int
>>>>>>> 98c87cb78a (data updated)
	for i := 0; i <= 1000; i++ {
		prime_num[i] = 0
	}

	// Calculate the prime factorization of each number up to N
	result := 1
	for current_num := 2; current_num <= N; current_num++ {
		kekka[1] = current_num
		for i := 0; i < prime_counter; i++ {
<<<<<<< HEAD
			innsuubunnkai(kekka[1], prime_list[i])
=======
			innsuubunnkai(kekka[1],prime_list[i])
>>>>>>> 98c87cb78a (data updated)
			prime_num[i] += kekka[0]
		}
	}

	// Sum the powers of each prime factor for all numbers up to N
	for current_num := 2; current_num <= N; current_num++ {
		for i := 0; i < 11; i++ {
			innsuu[i] += A[current_num][i]
		}
	}

	// Calculate the result using the formula for the number of divisors
	for i := 0; i < prime_counter; i++ {
		result = (result*(prime_num[i]+1))%1000000007
	}

	// Print the final result
	fmt.Printf("%d\n", result)
}

