package main

import (
    "fmt"
    "math"
)

// Function to compute the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
    if b == 0 {
        return a
    }
    return gcd(b, a%b)
}

// Function to compute the least common multiple (LCM) of two numbers
func lcm(a, b int) int {
    return a / gcd(a, b) * b
}

// Function to get the prime factorization of a number
func getPrimeFactor(n int) map[int]int {
    res := make(map[int]int)
    // Iterate from 2 to the square root of n
    for i := 2; i*i <= n; i++ {
        // While i divides n, store i in the result map
        for j := 0; n%i == 0; n /= i {
            res[i]++
        }
    }
    // If n is still greater than 1, it is a prime factor
    if n!= 1 {
        res[n] = 1
    }
    return res
}

// Function to check if a number is prime
func IsPrimeNumber(num int) bool {
    if num <= 2 {
        return true // 0, 1, and 2 are considered prime
    } else if num%2 == 0 {
        return false // Exclude even numbers
    }

    sqrtNum := int(math.Sqrt(float64(num)))
    // Check for factors from 3 to the square root of num
    for i := 3; i <= sqrtNum; i += 2 {
        if num%i == 0 {
            return false // Found a factor, not prime
        }
    }

    return true // No factors found, num is prime
}

// Function to compute modular inverse using the Extended Euclidean Algorithm
func modinv(a, m int) int {
    b := m
    u := 1
    v := 0
    // Loop until b becomes zero
    for b!= 0 {
        t := a / b
        a -= t * b
        a, b = b, a
        u -= t * v
        u, v = v, u
    }
    u %= m // Ensure u is within the modulo
    if u < 0 {
        u += m // Adjust if u is negative
    }
    return u // Return the modular inverse
}

// Macro definitions for loop iterations
func rep(i, s, e int) {
    for ; i < e; i++ {
        fmt.Printf("%d ", i)
    }
    fmt.Printf("\n")
}

func repeq(i, s, e int) {
    for ; i <= e; i++ {
        fmt.Printf("%d ", i)
    }
    fmt.Printf("\n")
}

func main() {
    var N, K int
    // Input the number of elements and the value of K
    fmt.Scanf("%d %d\n", &N, &K)

    A := make([]int, N + 1)
    // Input the elements into the vector A
    repeq(i, 1, N) {
        fmt.Scanf("%d\n", &A[i])
    }

    cur := 1 // Initialize current position
    dic := make([]int, N + 1)
    // Dictionary to store the first occurrence of each index
    for i := 0; i <= N; i++ {
        dic[i] = -1
    }
    flg := false // Flag to indicate if we have entered a cycle

    // Process the sequence based on the value of K
    repeq(i, 1, K) {
        // If current index has not been seen before or we are in a cycle
        if dic[cur] < 0 || flg {
            dic[cur] = i // Record the current index
            cur = A[cur] // Move to the next index
        }
        // If we have seen this index before and are not in a cycle
        else if!flg {
            tmp := K - (dic[cur] - 1) // Calculate remaining steps
            tmp %= i - dic[cur] // Adjust steps based on the cycle length
            i = K - tmp // Update i to skip to the end of the cycle
            flg = true // Set the flag indicating we are in a cycle
        }
    }

    // Output the final position after K steps
    fmt.Printf("%d\n", cur)
}

