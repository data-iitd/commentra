package main

import (
 "fmt"
)

func main() {
 // Initializing the Scanner object to read input from the console
 var n int
 fmt.Scan(&n)

 // Creating an integer array 'a' of size 'n' to store the input elements
 a := make([]int, n)

 // Initializing the XOR result to 0
 r := 0

 // Reading the elements of the array 'a' from the user input and performing XOR operation
 for i := 0; i < n; i++ {
 // Reading the next integer from the user input
 fmt.Scan(&a[i])

 // Performing XOR operation between 'r' and the current element 'a[i]' and updating the value of 'r'
 r ^= a[i]
 }

 // Printing the XOR result
 for i := 0; i < n; i++ {
 // If it's not the first element, print a space before the current element
 if i != 0 {
 fmt.Print(" ")
 }

 // Printing the XOR result of 'r' and the current element 'a[i]'
 fmt.Print(r ^ a[i])
 }
}

