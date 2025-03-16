// Read an integer input from the user
X := int(input())

// Initialize a list to track prime numbers up to 100010
// Start by assuming all numbers are prime (True)
prime := make([]bool, 100010)
for i := 0; i < 100010; i++ {
    prime[i] = true
}

// Set 0 and 1 as non-prime (False)
prime[0] = false
prime[1] = false

// Eliminate all even numbers greater than 2 from the list of primes
for i := 4; i < 100010; i += 2 {
    prime[i] = false
}

// Start checking for prime numbers from 3 onwards
i := 3
// Use the Sieve of Eratosthenes method to find all primes up to 100008
for i*i <= 100008 {
    // If 'i' is still marked as prime
    if prime[i] {
        // Mark all multiples of 'i' as non-prime
        for j := i + i; j < 100008; j += i {
            prime[j] = false
        }
    }
    // Move to the next odd number
    i += 2
}

// Find and print the first prime number greater than or equal to X
for i := X; i < 100008; i++ {
    if prime[i] {
        fmt.Println(i) // Print the prime number found
        break // Exit the loop after finding the first prime
}

