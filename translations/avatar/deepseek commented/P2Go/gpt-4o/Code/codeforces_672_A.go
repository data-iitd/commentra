package main

import (
	"fmt"
)

func main() {
	li := []int{}
	// Initialize an empty slice to keep track of the numbers

	for i := 1; i <= 370; i++ {
		temp := []int{}
		p, q := i, i
		count := 0
		// Initialize an empty temporary slice and set p and q to the current value of i
		// Initialize a counter to count the number of digits in i

		for p != 0 {
			p /= 10
			count++
		}
		// Count the number of digits in i by repeatedly dividing p by 10

		if count == 1 {
			li = append(li, i)
		}
		// If i has 1 digit, append it to the slice li

		if count == 2 || count == 3 {
			temp = []int{}
			for q != 0 {
				x := q % 10
				q /= 10
				temp = append(temp, x)
			}
			// If i has 2 or 3 digits, extract the digits and store them in temp

			for j := len(temp) - 1; j >= 0; j-- {
				li = append(li, temp[j])
			}
			// Reverse temp and append to li
		}
	}

	li = li[:len(li)-2]
	// Remove the last two elements from li

	var n int
	fmt.Scan(&n)
	// Take an integer input from the user

	fmt.Println(li[n-1])
	// Print the nth element of li based on the user's input
}

// <END-OF-CODE>
