package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // The entry point of the program
    var n int // Declare an integer variable 'n' to store the number of elements in the array
    fmt.Scan(&n) // Read an integer value from the standard input and store it in 'n'

    a := make([]int, n) // Declare an integer slice 'a' of size 'n'

    for i := 0; i < n; i++ { // Iterate through each element of the slice 'a'
        fmt.Scan(&a[i]) // Read an integer value from the standard input and store it in the current element of slice 'a'
    }

    t := 0 // Initialize the variable 't' to zero

    for i := 0; i < n; i++ { // Iterate through each element of the slice 'a'
        s := 0 // Initialize the variable 's' to zero for summation

        for j := 1; j < n; j++ { // Iterate through all other elements of the slice 'a' except the current element 'i'
            if j <= i { // If the current index 'j' is less than or equal to the current index 'i', then skip the iteration
                continue
            }

            m := a[i] * a[j] // Multiply the current element 'a[i]' with the next element 'a[j]' and store the result in 'm'

            s += m // Add the product 'm' to the sum 's'
        }

        t += s // Add the sum 's' to the total sum 't'
    }

    fmt.Println(t) // Print the total sum 't' to the standard output
}

// <END-OF-CODE>
