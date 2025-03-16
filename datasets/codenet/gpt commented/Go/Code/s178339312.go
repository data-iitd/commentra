package main

import "fmt"

func main() {
    // Declare a variable 'x' of type int to store user input
	var x int 

    // Read an integer value from standard input and store it in 'x'
	fmt.Scan(&x)

    // Calculate the cube of 'x' and print the result to standard output
	fmt.Println(x*x*x)
}
