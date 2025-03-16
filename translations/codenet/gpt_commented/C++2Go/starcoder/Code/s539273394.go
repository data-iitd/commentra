package main

import (
    "fmt"
    "math"
)

// Global arrays for storing results and prime information
var kekka [2]int
var prime_or_not [1001]int
var prime_list [1001]int
var prime_num [1001]int
var prime_counter int

// Function to find all prime numbers up to 1000 using the Sieve of Eratosthenes
func sosuubunnpu() {
    // Initialize the prime_or_not array to 0 (indicating all numbers are initially assumed prime)
    for i := 1; i <= 1000; i++ {
        prime_or_not[i] = 0
    }
    
    // Mark non-prime numbers in the prime_or_not array
    for i := 2; i <= 1000; i++ {
        for j := 2; j <= int(math.Sqrt(float64(i))); j++ {
            if prime_or_not[i] == 0 { // If i is still marked as prime
                prime_or_not[i * j] = 1 // Mark multiples of i as non-prime
            }
        }
    }
    
    // Populate the prime_list with the actual prime numbers found
    for i := 2; i <= 1000; i++ {
        if prime_or_not[i] == 0 { // If i is prime
            prime_list[prime_counter] = i // Add to the prime list
            prime_counter++ // Increment the prime counter
        }
    }
}

// Function to perform prime factorization of N by dividing it by n
func innsuubunnkai(N, n int) {
    time := 0
    for {
        if N % n == 0 { // If N is divisible by n
            N = N / n // Divide N by n
            time++ // Increment the division count
        } else {
            break // Exit loop if N is no longer divisible by n
        }
    }
    kekka[0] = time // Store the count of divisions in kekka[0]
    kekka[1] = N // Store the remaining value of N in kekka[1]
}

func main() {
    // Generate the list of prime numbers
    sosuubunnpu()
    
    var N int
    fmt.Scan(&N) // Read the input number from the user
    var innsuu [11]int
    var A [N + 1][11]int
    
    // Initialize the prime_num array to 0
    for i := 0; i <= 1000; i++ {
        prime_num[i] = 0
    }
    
    result := 1 // Variable to store the final result
    
    // Loop through each number from 2 to N to factorize it
    for current_num := 2; current_num <= N; current_num++ {
        kekka[1] = current_num
        for i := 0; i < prime_counter; i++ {
            innsuubunnkai(kekka[1], prime_list[i])
            prime_num[i] += kekka[0]
        }
    }
    
    // Accumulate the counts of prime factors for each prime
    for current_num := 2; current_num <= N; current_num++ {
        for i := 0; i < 11; i++ {
            innsuu[i] += A[current_num][i]
        }
    }
    
    // Calculate the final result based on the counts of prime factors
    for i := 0; i < prime_counter; i++ {
        result = (result * (prime_num[i] + 1)) % 1000000007
    }
    
    // Output the final result
    fmt.Println(result)
}

