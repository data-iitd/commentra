package main

import (
 "fmt"
 "os"
 "strconv"
)

// Initialize stack top to 0
var top int
var S []int

// Function to push an element onto the stack
func push(x int) {
 // Increment the top index and push the element
 S = append(S, x)
 top++
}

// Function to pop an element from the stack
func pop() int {
 // Return the top element and decrement the top index
 if top == 0 {
 panic("Stack underflow")
 }
 x := S[top-1]
 S = S[:top-1]
 top--
 return x
}

// Main function
func main() {
 // Initialize variables
 var a, b int
 var s string

 // Initialize stack top to 0
 top = 0
 S = []int{}

 // Read input until end of file
 for {
 _, err := fmt.Scan(&s)
 if err != nil {
 if err == os.ErrEOF {
 break
 }
 panic(err)
 }

 // Check if the input is an operator or a number
 if s == "+" || s == "-" || s == "*" {
 // Pop the top two elements from the stack
 b = pop()
 a = pop()

 // Perform the operation and push the result back onto the stack
 if s == "+" {
 push(a + b)
 } else if s == "-" {
 push(a - b)
 } else { // s == "*"
 push(a * b)
 }
 } else { // Input is a number
 // Push the number directly onto the stack
 num, err := strconv.Atoi(s)
 if err != nil {
 panic(err)
 }
 push(num)
 }
 }

 // Print the final result
 fmt.Println(pop())
}

