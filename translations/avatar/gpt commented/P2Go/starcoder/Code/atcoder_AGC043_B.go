package main

import "fmt"

func twos_in_factorial(n int) int {
    // Calculate the number of factors of 2 in n! by subtracting the count of 1s in the binary representation of n from n
    return n - len(fmt.Sprintf("%b", n))
}

func parity_of_nCr(n, i int) bool {
    // Determine the parity (even or odd) of the binomial coefficient C(n, i)
    f := twos_in_factorial  // Reference to the function that calculates the number of factors of 2
    // The binomial coefficient C(n, i) is odd if the number of factors of 2 in n! is greater than the sum of factors of 2 in (n-i)! and i!
    return f(n) - f(n - i) - f(i) > 0
}

func main() {
    // Read an integer n from input
    var n int
    fmt.Scanf("%d", &n)
    // Read a list of integers, subtracting 1 from each input value
    nums := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &nums[i])
        nums[i] -= 1
    }

    no_one := false  // Flag to check if there are no '1's in the input list
    if 1 not in nums {
        // If there are no '1's, divide each number in nums by 2
        for i := 0; i < n; i++ {
            nums[i] /= 2
        }
        no_one = true  // Set the flag to True since there were no '1's

    is_odd := false  // Flag to track if the overall parity is odd
    for i, num := range nums {
        // Check the parity of C(n-1, i) and if num is odd
        if!parity_of_nCr(n - 1, i) && num & 1 {
            is_odd ^= 1  // Toggle the is_odd flag if the conditions are met

    // Print the result based on the parity
    if!is_odd {
        fmt.Println(0)  // If the overall parity is even, print 0
    } else {
        fmt.Println(1 << no_one)  // If odd, print 1 or 2 based on the no_one flag
}

