
package main

import "fmt"

func main() {

    var x, y int // Declaring two integer variables x and y

    fmt.Print("Enter a number: ") // Printing a message to ask user for input
    fmt.Scan(&x) // Reading an integer value from the user and storing it in variable x

    y = x * x * x // Assigning the value of x cubed to variable y

    fmt.Printf("The cube of %d is %d\n", x, y) // Printing the message with the input number and its cube
}

