
package main

import "fmt"

func main() {
	var li []int
	var ind int
	// Initialize an empty list and a variable to keep track of the index

	for i := 1; i <= 371; i++ {
		temp := []int{}
		p, q := i, i
		count := 0
		// Initialize an empty temporary list and set p and q to the current value of i
		// Initialize a counter to count the number of digits in i

		for p != 0 {
			p /= 10
			count++
		}
		// Count the number of digits in i by repeatedly dividing p by 10

		if count == 1 {
			li = append(li, i)
		}
		// If i has 1 digit, append it to the list li

		if count == 2 {
			temp = []int{}
			for q != 0 {
				x := q % 10
				q /= 10
				temp = append(temp, x)
			}
			for i := len(temp) - 1; i >= 0; i-- {
				li = append(li, temp[i])
			}
		}
		// If i has 2 digits, extract the digits and reverse them, then append to li

		if count == 3 {
			temp = []int{}
			for q != 0 {
				x := q % 10
				q /= 10
				temp = append(temp, x)
			}
			for i := len(temp) - 1; i >= 0; i-- {
				li = append(li, temp[i])
			}
		}
		// If i has 3 digits, extract the digits and reverse them, then append to li
	}

	li = li[:len(li)-2]
	// Remove the last two elements from li

	var n int
	fmt.Scan(&n)
	// Take an integer input from the user

	fmt.Println(li[n-1])
	// Print the nth element of li based on the user's input
}

