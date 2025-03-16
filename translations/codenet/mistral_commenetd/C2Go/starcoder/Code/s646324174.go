<<<<<<< HEAD

import (
"fmt"
"os"
"strconv"
"strings"
)

func main() {
// Initialize variables
var a, b int
var s string

// Initialize stack top to 0
var top int = 0

// Read input until end of file
for {
s, _ = os.ReadLine()
if s == "" {
break
}

// Check if the input is an operator or a number
if strings.ContainsAny(s, "+-*/") {
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
push(atoi(s))
}
}

// Print the final result
fmt.Println(pop())
}

func push(x int) {
// Increment the top index and push the element
top++
S[top] = x
}

func pop() int {
// Return the top element and decrement the top index
return S[top--]
}

func atoi(s string) int {
// Convert string to integer
i, _ := strconv.Atoi(s)
return i
=======
package main

import "fmt"

// Initialize stack top to 0
var top int = 0
var S [10000]int

// Function to push an element onto the stack
func push(x int){
 // Increment the top index and push the element
 S[top+1] = x
 top++
}

// Function to pop an element from the stack
func pop() int{
 // Return the top element and decrement the top index
 top--
 return S[top]
}

// Main function
func main(){
 // Initialize variables
 var a, b int
 var s string

 // Initialize stack top to 0
 top = 0

 // Read input until end of file
 for{
 fmt.Scanf("%s", &s)
 // Check if the input is an operator or a number
 if s[0] == '+' || s[0] == '-' || s[0] == '*'{
 // Pop the top two elements from the stack
 b = pop()
 a = pop()

 // Perform the operation and push the result back onto the stack
 if s[0] == '+'{
 push(a+b)
 }else if s[0] == '-'{
 push(a-b)
 }else{ // s[0] == '*'
 push(a*b)
 }
 }else{ // Input is a number
 // Push the number directly onto the stack
 push(atoi(s))
 }
 }

 // Print the final result
 fmt.Printf("%d\n", pop())

 // Return 0 to indicate successful execution
 return 0
>>>>>>> 98c87cb78a (data updated)
}

