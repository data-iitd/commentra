

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func gcd(a, b int) int {
    // Recursively calculates the greatest common divisor (GCD) of a and b
    if b == 0 {
        return a
    }
    return gcd(b, a%b)
}

func ruiseki_lr(array []int) ([]int, []int) {
    // Defines a lambda function to compute GCD
    op := func(a, b int) int {
        return gcd(a, b)
    }
    // Initial GCD value
    e := 0
    // Length of the input array
    n := len(array)
    // Initialize prefix and suffix GCD arrays
    left := make([]int, n+1)
    right := make([]int, n+1)
    // Compute prefix GCD array
    for i := 0; i < n; i++ {
        left[i+1] = op(left[i], array[i])
    }
    // Compute suffix GCD array
    for i := n - 1; i >= 0; i-- {
        right[i] = op(right[i+1], array[i])
    }
    return left, right
}

func main() {
    // Read the number of elements
    n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())
    // Read the list of elements
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).Scan())
    }
    // Compute prefix and suffix GCD arrays
    left, right := ruiseki_lr(a)
    // Initialize the answer variable
    ans := 0
    // Iterate through the array to find the maximum GCD
    for i := 0; i < n; i++ {
        ans = max(gcd(left[i], right[i+1]), ans)
    }
    // Print the result
    fmt.Println(ans)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

