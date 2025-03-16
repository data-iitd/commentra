package main

import (
	"fmt"
	"sort"
)

func main() {
	var s, x, d int
	fmt.Scan(&s) // Read the initial number from the user
	a := []int{s} // Create a slice to store the sequence of numbers

	for {
		if s%2 == 0 {
			x = s / 2
			sort.Ints(a) // Sort the slice to use binary search
			i := sort.SearchInts(a, x)
			if i < len(a) && a[i] == x {
				fmt.Println(d + 1) // Output the current step count and terminate the program
				return
			}
			a = append(a, x) // Append the halved number to the slice
		} else {
			x = 3*s + 1
			sort.Ints(a) // Sort the slice to use binary search
			i := sort.SearchInts(a, x)
			if i < len(a) && a[i] == x {
				fmt.Println(d + 1) // Output the current step count and terminate the program
				return
			}
			a = append(a, x) // Append the new number to the slice
		}
		s = x // Update the current number to the new number
		d++ // Increment the step count
	}

	fmt.Println(d) // Output the step count (this line will never be reached)
}

