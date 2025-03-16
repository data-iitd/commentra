
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func gcd(a, b int) int {
    // Base case: if b is 0, return a as the GCD
    if b == 0 {
        return a
    }
    // Recursive case: call gcd with b and the remainder of a divided by b
    return gcd(b, a%b)
}

func ruiseki_lr(array []int) ([]int, []int) {
    // Define the operation to find the GCD of two numbers
    op := func(a, b int) int {
        return gcd(a, b)
    }

    // Initialize the identity element for GCD
    e := 0
    n := len(array)

    // Create lists to store cumulative GCD from the left and right
    left := make([]int, n+1)
    right := make([]int, n+1)

    // Calculate cumulative GCD from the left
    left[0] = e
    for i := 0; i < n; i++ {
        left[i+1] = op(left[i], array[i])
    }

    // Calculate cumulative GCD from the right
    right[n] = e
    for i := n - 1; i >= 0; i-- {
        right[i] = op(right[i+1], array[i])
    }

    // Return both cumulative GCD lists
    return left, right
}

func main() {
    // Read the number of elements in the array
    n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

    // Read the array elements from input and convert them to integers
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).Scan())
    }

    // Compute the cumulative GCD from the left and right
    left, right := ruiseki_lr(a)

    // Initialize the answer variable to store the maximum GCD found
    ans := 0

    // Iterate through the array to find the maximum GCD of left and right parts
    for i := 0; i < n; i++ {
        ans = max(gcd(left[i], right[i+1]), ans)
    }

    // Print the maximum GCD found
    fmt.Println(ans)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

