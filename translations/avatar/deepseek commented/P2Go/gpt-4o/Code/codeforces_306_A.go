package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Take two integers n and m as input

	q := n / m // Calculate the quotient, which is the number of items each group will have
	r := n % m // Calculate the remainder, which is the number of items that will be left over

	a := make([]int, m) // Initialize a slice a of length m

	for i := 0; i < m; i++ {
		a[i] = q // Set each element in the slice a to q
	}

	for i := 0; i < r; i++ { // Loop for the number of remaining items r
		a[i]++ // Increment the corresponding element in the slice a by 1
	}

	for i := 0; i < m; i++ { // Loop to print the elements of the slice a
		fmt.Print(a[i], " ") // Print each element separated by a space
	}
}

// <END-OF-CODE>
