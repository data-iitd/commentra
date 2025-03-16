
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Initialize the array A and read its elements from the standard input
func main() {
    reader := bufio.NewReader(os.Stdin)

    // Read the number of elements in the array A
    N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    // Allocate memory for the array A of size N
    A := make([]int, N)

    // Read the elements of the array A from the standard input
    for i := 0; i < N; i++ {
        A[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
    }

    // Initialize arrays M, L, and R
    M := make([]int, N)
    L := make([]int, N)
    R := make([]int, N)

    // Initialize the first elements of L and R arrays
    L[0] = A[0]
    R[N-1] = A[N-1]

    // Calculate the gcd of consecutive pairs of elements in the array A,
    // starting from the second element, and store the results in the L array
    for i := 1; i < N; i++ {
        L[i] = gcd(L[i-1], A[i])
    }

    // Calculate the gcd of consecutive pairs of elements in the array A,
    // starting from the last element, and store the results in the R array
    for i := N - 2; i >= 0; i-- {
        R[i] = gcd(R[i+1], A[i])
    }

    // Find the maximum value among the gcd of consecutive pairs of elements
    // in the subarrays [0, i] and [i+1, N-1] for all i from 0 to N-2
    answer := max(L[N-2], R[1])
    for i := 1; i < N-1; i++ {
        answer = max(answer, gcd(L[i-1], R[i+1]))
    }

    // Print the result
    fmt.Println(answer)
}

// Read a line from the standard input
func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return string(str)
    }

    return ""
}

// Calculate the greatest common divisor of two integers using Euclid's algorithm
func gcd(a, b int) int {
    var tmp int

    // If b is greater than a, swap a and b
    if b > a {
        tmp = a
        a = b
        b = tmp
    }

    // If b is zero, return a as the gcd
    if b == 0 {
        return a
    }

    // Calculate the remainder of the division of a by b, and repeat the process
    r := -1
    for r!= 0 {
        r = a % b
        a = b
        b = r
    }

    // Return the final result
    return a
}

// Calculate the maximum value among two integers
func max(a, b int) int {
    if a > b {
        return a
    }

    return b
}

// Translate the above Java code to C++ and end with comment "