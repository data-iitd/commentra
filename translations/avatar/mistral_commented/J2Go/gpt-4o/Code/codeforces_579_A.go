package main // Declaring the main package

import (
    "fmt" // Importing the fmt package for formatted I/O
)

func main() { // Defining the main function, which is the entry point of the program.
    var n int // Declaring an integer variable n to store user input.
    fmt.Scan(&n) // Reading the first integer input n from the user.

    s := "" // Initializing an empty string variable s to store the binary representation of the number n.

    for n > 0 { // Starting a for loop that continues as long as n is greater than zero.
        x := n % 2 // Calculating the last bit of the binary representation of n.
        n /= 2 // Updating the value of n by dividing it by 2 to get the next bit of the binary representation.
        s = fmt.Sprintf("%s%d", s, x) // Appending the calculated bit to the string s.
    }

    ans := 0 // Initializing an integer variable ans to 0 to store the number of 1's in the binary representation of n.

    for i := 0; i < len(s); i++ { // Starting a for loop that iterates through each character in the string s.
        if s[i] == '1' { // Checking if the current character is '1'.
            ans++ // If the character is '1', incrementing the value of ans by 1.
        }
    }

    fmt.Println(ans) // Printing the value of ans to the standard output stream.

    // No need to close any scanner in Go as we did in Java.
}

// <END-OF-CODE>
