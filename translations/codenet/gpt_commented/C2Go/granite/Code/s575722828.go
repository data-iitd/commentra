
package main

import "fmt"

func main() {
    // Declare an integer variable to store the total seconds
    var S int

    // Read the total seconds from user input
    fmt.Scan(&S)

    // Calculate hours, minutes, and seconds from the total seconds
    // and print them in the format HH:MM:SS
    fmt.Printf("%d:%d:%d\n", 
        S/3600,                // Calculate hours
        (S%3600)/60,           // Calculate minutes
        S%60)                  // Calculate remaining seconds

    // Return 0 to indicate successful completion of the program
    return 0
}

