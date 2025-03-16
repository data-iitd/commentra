package main

import "fmt"

func twos_in_factorial(n int) int {
    // Calculate the number of factors of 2 in the factorial of n
    return n - len(fmt.Sprintf("%b", n))
}

func parity_of_nCr(n, i int) bool {
    // Determine the parity (odd or even) of the binomial coefficient nCr
    f := twos_in_factorial
    return f(n) - f(n - i) - f(i) > 0
}

func main() {
    // Read an integer n and a list of integers from the input
    var n int
    fmt.Scanf("%d", &n)
    nums := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &nums[i])
    }
    
    // If the list does not contain the number 1, halve each number in the list and set no_one to True
    no_one := false
    if 1 not in nums {
        for i := range nums {
            nums[i] /= 2
        }
        no_one = true
    }
    
    // Initialize is_odd to False
    is_odd := false
    
    // Iterate over the list nums, checking the parity of nCr for each element and the corresponding index
    for i, num := range nums {
        if!parity_of_nCr(n - 1, i) && num & 1 {
            is_odd ^= 1
    }
    
    // If is_odd is False, print 0; otherwise, print 1 << no_one (which is equivalent to 2 ** no_one)
    if!is_odd {
        fmt.Println(0)
    } else {
        fmt.Println(1 << no_one)
}

}

