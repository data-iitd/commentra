package main  // Define the main package

import (  // Import necessary packages
    "fmt"  // Import the fmt package for formatted I/O
)

func main() {  // Define the main function
    var S int  // Declare an integer variable S
    fmt.Scan(&S)  // Read an integer input from the user and store it in S

    // Check if S is less than 60
    if S < 60 {
        fmt.Printf("0:0:%d\n", S)  // Print "0:0:S" if S is less than 60
    } else if S < 3600 {  // Check if S is less than 3600
        fmt.Printf("0:%d:%d\n", S/60, S%60)  // Print "0:S/60:S%60" if S is less than 3600
    } else {  // If S is not less than 3600
        fmt.Printf("%d:%d:%d\n", S/3600, (S%3600)/60, S%60)  // Print "S/3600:S%3600/60:S%60" if S is not less than 3600
    }
}  // End of main function

// <END-OF-CODE>
