package main

import "fmt"

func main() {
    // Declare two integer variables to hold user input
	var x, y int
	
    // Read two integers from standard input
	fmt.Scan(&x, &y)

    // Calculate the sum of x and half of y, then print the result
	fmt.Println(x + y/2)
}
