
package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the input values for n and num
	var n, num int
	fmt.Scan(&n, &num)

	// Read the set of integers
	num_set := make(map[int]bool)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		num_set[x] = true
	}

	// Initialize an empty set to store the number of times each integer is divisible by 2
	two_times_set := make(map[int]bool)

	// Loop through each integer in the num_set
	for i := range num_set {
		// Divide the integer by 2 repeatedly until it is no longer even
		for j := 1; j < 30; j++ {
			i /= 2
			if i%2 != 0 {
				// Add the count to two_times_set
				two_times_set[j] = true
				break
			}
		}
		// If two_times_set contains more than one element, print 0 and break
		if len(two_times_set) != 1 {
			fmt.Println(0)
			break
		}
	}

	// If the loop completes, calculate the LCM of the integers in num_set
	num_list := make([]int, 0, len(num_set))
	for i := range num_set {
		num_list = append(num_list, i)
	}
	lcm := num_list[0]
	for i := 1; i < len(num_list); i++ {
		lcm = lcm * num_list[i] / int(math.GCD(float64(lcm), float64(num_list[i])))
	}

	// Calculate the number of integers in the range from 1 to num that are divisible by the LCM
	fmt.Println((num - lcm/2) / lcm + 1)
}

