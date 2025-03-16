<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

// Function A is not defined in the provided code.
func A() {
    // Function implementation here (if needed)
}

// Function B is defined to take input and calculate the number of iterations.
func B() {
    var x, sum int64
    fmt.Scanf("%d", &x)
    i := 0
    sum = 100
    for sum < x {
        sum += sum / 100
        i++
    }
    fmt.Println(i)
}

// Function C is not defined in the provided code.
func C() {
    // Function implementation here (if needed)
}

// Function D is not defined in the provided code.
func D() {
    // Function implementation here (if needed)
}

// Main function calls the B function.
func main() {
    B()
}

