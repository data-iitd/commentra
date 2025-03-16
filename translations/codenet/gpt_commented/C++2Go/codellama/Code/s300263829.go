package main

import "fmt"

func main() {
	var a, b int
	fmt.Print("Enter two integers: ")
	fmt.Scan(&a, &b)
	fmt.Println("The product is: ", a*b)
}

