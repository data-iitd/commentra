package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Take two integers as input and store them in list 'l' and 'r' respectively
	l, r := [2]int{}, [2]int{}
	fmt.Scan(&l[0], &l[1])
	fmt.Scan(&r[0], &r[1])

	// Initialize current number to 'r'
	curr := r[1]

	// Initialize sum variable 's' to 0
	s := 0

	// While 'curr' is not zero, perform the following operations
	for curr != 0 {
		// Increment the sum 's' by 1
		s++

		// Calculate the power of 10 raised to the value of 's' and store it in 'first'
		first := int(math.Pow(10, float64(s)))

		// Calculate half of 'first' and store it in 'second'
		second := first / 2

		// Initialize 'ans' with a negative value
		ans := -1

		// Iterate through the list containing 'l', 'r', 'first', and 'second'
		for i := 0; i < 4; i++ {
			// If 'i' lies within the range of 'l' and 'r', update 'curr' and 'rev'
			if l[i] <= curr && curr <= r[i] {
				curr = l[i]
				rev := ""

				// Reverse the digits of 'curr' and store it in 'rev'
				for _, k := range strconv.Itoa(curr) {
					rev = string(k) + rev
				}

				// Update 'ans' with the maximum value of the current 'ans' and the product of 'curr' and the reversed number
				ans = int(math.Max(float64(ans), float64(rev)*float64(curr)))
			}
		}
	}

	// Print the final answer
	fmt.Println(ans)
}

