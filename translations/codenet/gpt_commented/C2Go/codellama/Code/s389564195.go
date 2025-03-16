package main

import "fmt"

func main() {
    // Declare two integer variables: x for input and kotae for storing the result
    var x, kotae int

    // Prompt the user to enter an integer value
    fmt.Scanf("%d", &x)

    // Calculate the cube of the input value x and store it in kotae
    kotae = x * x * x

    // Output the result (the cube of x) to the console
    fmt.Printf("%d\n", kotae)
}

