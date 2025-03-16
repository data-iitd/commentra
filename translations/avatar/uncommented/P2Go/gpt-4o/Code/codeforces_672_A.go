package main

import (
	"fmt"
)

func main() {
	li := []int{}
	for i := 1; i < 371; i++ {
		temp := []int{}
		p, q := i, i
		count := 0

		// Count the number of digits in i
		for p != 0 {
			p /= 10
			count++
		}

		if count == 1 {
			li = append(li, i)
		}
		if count == 2 || count == 3 {
			// Extract digits and store them in temp
			for q != 0 {
				x := q % 10
				q /= 10
				temp = append(temp, x)
			}
			// Reverse temp and append to li
			for j := len(temp) - 1; j >= 0; j-- {
				li = append(li, temp[j])
			}
		}
	}

	// Remove the last two elements from li
	li = li[:len(li)-2]

	var n int
	fmt.Scan(&n)
	fmt.Println(li[n-1])
}

// <END-OF-CODE>
