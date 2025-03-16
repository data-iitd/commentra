
package main

import "fmt"

func main() {

    var x, kotae int // Declare two integer variables, x and kotae


    // Ask the user to input an integer value for x
    fmt.Print("Enter an integer value for x: ")
    fmt.Scan(&x)


    // Calculate the cube of the input integer x and store the result in the variable kotae
    kotae = x*x*x


    // Print the result (the cube of the input integer) to the console
    fmt.Printf("The cube of %d is %d.\n", x, kotae)


}

