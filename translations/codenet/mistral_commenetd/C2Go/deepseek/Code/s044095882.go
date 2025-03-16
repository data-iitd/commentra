package main

import (
	"fmt"
)

func main() {
	var n int

	fmt.Print("Enter the number of elements: ")
	fmt.Scan(&n)

	a := make([]int, n)
	count := make([]int, n)

	fmt.Printf("Enter %d numbers:\n", n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	fmt.Println("Initializing count array with zeros:")
	for i := 0; i < n; i++ {
		count[i] = 0
	}

	fmt.Println("Counting occurrences:")
	for i := 0; i < n; i++ {
		count[a[i]-1]++
	}

	fmt.Println("Printing the contents of the count array:")
	for i := 0; i < n; i++ {
		fmt.Println(count[i])
	}

	fmt.Println("Program completed successfully.")
}

