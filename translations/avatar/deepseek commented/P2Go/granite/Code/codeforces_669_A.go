

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)  // Take an integer input from the user
    fmt.Println((n*2 + 1) / 3)  // Perform a calculation and print the result
}

func factorial(n int) int {
    if n == 0 {  // Base case: factorial of 0 is 1
        return 1
    } else {
        return n * factorial(n-1)  // Recursive case: n * factorial of (n - 1)
    }
}

func main() {
    var number int
    fmt.Scan(&number)  // Take an integer input from the user
    result := factorial(number)  // Calculate the factorial of the input number
    fmt.Println(result)  // Print the result
}

func fibonacci(n int) int {
    if n <= 0 {  // Return 0 for non-positive input
        return 0
    } else if n == 1 {  // Return 1 for input of 1
        return 1
    } else {
        a, b := 0, 1  // Initialize the first two Fibonacci numbers
        for i := 2; i <= n; i++ {  // Loop from 2 to n
            a, b = b, a+b  // Update the values of a and b
        }
        return b  // Return the nth Fibonacci number
    }
}

func main() {
    var index int
    fmt.Scan(&index)  // Take an integer input from the user
    fmt.Println(fibonacci(index))  // Print the nth Fibonacci number
}

