

package main

import "fmt"

func main() {
    var age int
    fmt.Scan(&age)  // Taking an integer input for the variable `age`
    if age == 1 {  // Checking if `age` is equal to 1
        fmt.Println("Hello World")  // If `age` is 1, it prints "Hello World"
    } else {  // If `age` is not 1
        var a, b int
        fmt.Scan(&a, &b)  // Taking two integer inputs and assigning them to variables `a` and `b`
        fmt.Println(a + b)  // Printing the sum of `a` and `b`
    }
}

