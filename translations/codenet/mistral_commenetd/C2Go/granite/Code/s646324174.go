
package main

import (
 "bufio"
 "fmt"
 "os"
 "strconv"
)

// Initialize stack top to 0
var top = 0
var S [10000]int

// Function to push an element onto the stack
func push(x int) {
 // Increment the top index and push the element
 top++
 S[top] = x
}

// Function to pop an element from the stack
func pop() int {
 // Return the top element and decrement the top index
 top--
 return S[top+1]
}

// Main function
func main() {
 // Initialize variables
 var a, b int
 var s string

 // Initialize stack top to 0
 top = 0

 // Read input until end of file
 scanner := bufio.NewScanner(os.Stdin)
 for scanner.Scan() {
 s = scanner.Text()

 // Check if the input is an operator or a number
 if s[0] == '+' || s[0] == '-' || s[0] == '*' {
 // Pop the top two elements from the stack
 b = pop()
 a = pop()

 // Perform the operation and push the result back onto the stack
 if s[0] == '+' {
 push(a + b)
 } else if s[0] == '-' {
 push(a - b)
 } else { // s[0] == '*'
 push(a * b)
 }
 } else { // Input is a number
 // Push the number directly onto the stack
 push(mustParseInt(s))
 }
 }

 // Print the final result
 fmt.Println(pop())
}

// Function to parse an integer from a string
func mustParseInt(s string) int {
 i, err := strconv.Atoi(s)
 if err!= nil {
 panic(err)
 }
 return i
}

// End of code
