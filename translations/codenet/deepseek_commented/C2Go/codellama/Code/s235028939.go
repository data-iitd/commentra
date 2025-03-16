package main

import "fmt"

func main() {
	var n, m int // Declare two integer variables to store input values
	fmt.Scanf("%d %d", &n, &m) // Read two integers from the standard input and store them in n and m
	fmt.Printf("%d\n", (n-1)*(m-1)) // Print the result of the expression (n - 1) * (m - 1)
	// Ensure buffered output is written to the standard output stream immediately
	fmt.Println("