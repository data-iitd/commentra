

package main

import (
    "fmt"
    "os"
)

func main() {
    var a int // Declare an integer variable named a
    
    fmt.Println("Enter the number of seconds:") // Print a message to ask the user for the number of seconds
    fmt.Fscan(os.Stdin, &a) // Read an integer value from the standard input stream and assign it to the variable a
    
    hours := a / (60 * 60) // Extract the hours from the number of seconds
    minutes := (a % (60 * 60)) / 60 // Extract the minutes from the remaining seconds
    seconds := (a % (60 * 60)) % 60 // Extract the seconds from the remaining seconds
    
    fmt.Printf("%d:%d:%d\n", hours, minutes, seconds) // Print the time representation of the number of seconds
    
    os.Exit(0) // Exit the program with a status code of 0
}

