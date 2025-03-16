package main

import (
    "fmt"
)

func main() {
    var n int
    var str string

    fmt.Scan(&n) // Reading an integer value from the console and assigning it to the variable n
    fmt.Scanln() // Consuming the newline character left after reading an integer value
    fmt.Scanln(&str) // Reading a line of text from the console and assigning it to the variable str

    a := "" // Declaring a string variable a

    for i := 0; i < n/2; i++ { // Starting a for loop that iterates n/2 times
        a += string(str[i]) // Appending the character at the current index of str to the variable a
    }

    if str == a+a { // Checking if the given string is a palindrome
        fmt.Println("Yes") // Printing "Yes" to the console if the given string is a palindrome
    } else {
        fmt.Println("No") // Printing "No" to the console if the given string is not a palindrome
    }
}

// <END-OF-CODE>
