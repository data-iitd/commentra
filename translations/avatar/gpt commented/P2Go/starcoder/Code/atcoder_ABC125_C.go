package main

import "fmt"

func gcd(a, b int) int {
    if b == 0 {
        return a
    }
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
    left := make([]int, n + 1)
    right := make([]int, n + 1)
    
    // Calculate cumulative GCD from the left
    for i := 0; i < n; i++ {
        left[i + 1] = op(left[i], array[i])
    }
    
    // Calculate cumulative GCD from the right
    for i := n - 1; i >= 0; i-- {
        right[i] = op(right[i + 1], array[i])
    }
    
    // Return both cumulative GCD lists
    return left, right
}

func main() {
    // Read the number of elements in the array
    var n int
    fmt.Scanf("%d\n", &n)
    // Read the array elements from input and convert them to integers
    var a []int
    for i := 0; i < n; i++ {
        var x int
        fmt.Scanf("%d\n", &x)
        a = append(a, x)
    }
    
    // Compute the cumulative GCD from the left and right
    left, right := ruiseki_lr(a)
    
    // Initialize the answer variable to store the maximum GCD found
    ans := 0
    
    // Iterate through the array to find the maximum GCD of left and right parts
    for i := 0; i < n; i++ {
        ans = max(gcd(left[i], right[i + 1]), ans)
    }
    
    // Print the maximum GCD found
    fmt.Printf("%d\n", ans)
}

// 