
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Define a constant for the maximum value to check for primes
    const MAX_V = 999999

    // Array to hold the prime status of numbers from 0 to MAX_V
    prime := make([]int, MAX_V+1)
    var i, k, n int

    // Initialize the prime array; assume all numbers are prime initially
    for i = 2; i <= MAX_V; i++ {
        prime[i] = 1 // 1 indicates that the number is prime
    }

    // Implement the Sieve of Eratosthenes algorithm to find all primes up to MAX_V
    for i = 2; i*i <= MAX_V; i++ {
        if prime[i] == 1 { // If i is still marked as prime
            // Mark all multiples of i as non-prime
            for k = 2 * i; k <= MAX_V; k += i {
                prime[k] = 0 // 0 indicates that the number is not prime
            }
        }
    }

    // Explicitly mark 0 and 1 as non-prime
    prime[0] = 0
    prime[1] = 0

    // Variable to count the number of inputs processed
    count := 0

    // Read integers from standard input until EOF
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        count++ // Increment the count of numbers processed
        n, _ = strconv.Atoi(scanner.Text()) // Convert the input to an integer
        cnt := 0 // Counter for the number of primes less than or equal to n

        // Count how many primes are less than or equal to n
        for i = n; i > 0; i-- {
            if prime[i] == 1 { // Check if the number is prime
                cnt++ // Increment the prime count
            }
        }

        // Output the count of primes found
        fmt.Println(cnt)

        // Stop processing after 30 numbers
        if count == 30 {
            break
        }
    }

    // Handle any errors that may occur during input reading
    if err := scanner.Err(); err!= nil {
        fmt.Println("Error reading input:", err)
    }
}

