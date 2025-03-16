package main  // Declare the main package

import (  // Import necessary packages
    "fmt"  // Import the fmt package for formatted I/O
)

func main() {  // Define the main function
    var n int  // Declare an integer variable 'n' to store the number of elements
    var a [101]int  // Declare an array 'a' of size 101 to store the elements

    fmt.Scan(&n)  // Input the number of elements for the array 'a'
    for i := 0; i < n; i++ {  // Loop to take 'n' integer inputs and store them in the array 'a'
        fmt.Scan(&a[i])
    }

    fmt.Print(a[n-1])  // Output the last element of the array 'a'
    for i := 1; i < n; i++ {  // Loop to output the remaining elements of the array 'a' in reverse order
        fmt.Print(" ", a[n-i-1])
    }
    fmt.Println()  // End the line after outputting all the elements
}

// <END-OF-CODE>
