

package main

import "fmt"

func main() {
	var a, b, h int
	fmt.Println("Enter the values of a, b, and h:")
	fmt.Scan(&a, &b, &h)
	fmt.Println((a + b) * h / 2)
}

