
package main

import "fmt"
import "bufio"
import "os"

func main() {
    reader := bufio.NewReader(os.Stdin) // Creating a reader to read input from the user
    
    a, _ := reader.ReadString('\n') // Reading the first integer input from the user
    b, _ := reader.ReadString('\n') // Reading the second integer input from the user
    
    a = a[:len(a)-1] // Trimming the newline character from the first input
    b = b[:len(b)-1] // Trimming the newline character from the second input
    
    aInt, _ := strconv.Atoi(a) // Converting the first input to an integer
    bInt, _ := strconv.Atoi(b) // Converting the second input to an integer
    
    // Checking if the first number is positive
    if aInt > 0 {
        fmt.Println("Positive") // Printing "Positive" if the first number is greater than 0
    } 
    // Checking if the first number is zero or the second number is non-negative
    else if bInt >= 0 {
        fmt.Println("Zero") // Printing "Zero" if the second number is non-negative
    } 
    // Checking if the difference between b and a plus one is even
    else if (bInt - aInt + 1) % 2 == 0 {
        fmt.Println("Positive") // Printing "Positive" if the difference is even
    } 
    else {
        fmt.Println("Negative") // Printing "Negative" if none of the above conditions are met
    }
}

