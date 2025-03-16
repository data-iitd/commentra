
###
# Code
###

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Define input variables
    var n, L, R, QL, QR int
    // Read input from standard input
    scanner := bufio.NewScanner(os.Stdin)
    // Read first line of input
    scanner.Scan()
    // Split first line of input into individual integers
    line := strings.Split(scanner.Text(), " ")
    // Convert each integer to its respective type
    n, _ = strconv.Atoi(line[0])
    L, _ = strconv.Atoi(line[1])
    R, _ = strconv.Atoi(line[2])
    QL, _ = strconv.Atoi(line[3])
    QR, _ = strconv.Atoi(line[4])
    // Read second line of input
    scanner.Scan()
    // Split second line of input into individual integers
    line = strings.Split(scanner.Text(), " ")
    // Convert each integer to its respective type
    W := make([]int, n)
    for i := 0; i < n; i++ {
        W[i], _ = strconv.Atoi(line[i])
    }

    // Initialize empty list to store sum of elements
    sum_el := make([]int, n+1)

    // Calculate sum of elements from 1 to n
    for i := 1; i <= n; i++ {
        // Add current element and previous sum to get sum of current element
        sum_el[i] = W[i-1] + sum_el[i-1]
    }

    // Calculate answer
    answer := QR * (n - 1) + sum_el[n] * R

    // Iterate through all elements to find minimum energy
    for i := 1; i <= n; i++ {
        // Calculate energy for current index
        energy := L * sum_el[i] + R * (sum_el[n] - sum_el[i])

        // Check if current index is greater than its mirror index
        if i > (n - i) {
            // If true, add energy of segments between current index and its mirror index
            energy += (i - (n - i) - 1) * QL
        }

        // Check if mirror index is greater than current index
        if (n - i) > i {
            // If true, add energy of segments between mirror index and current index
            energy += ( (n - i) - i - 1) * QR
        }

        // Update answer if current energy is less than previous answer
        if energy < answer {
            answer = energy
        }
    }

    // Print the answer
    fmt.Println(answer)
}
