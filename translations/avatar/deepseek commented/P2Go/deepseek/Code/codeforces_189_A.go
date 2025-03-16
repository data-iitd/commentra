package main

import (
	"fmt"
	"sort"
)

func cutRibbon() {
	// Take input from the user, which is expected to be a list of three integers
	var arr [3]int
	fmt.Scan(&arr[0], &arr[1], &arr[2])
	
	// Sort the remaining three integers in ascending order
	sort.Slice(arr[:], func(i, j int) bool {
		return arr[i] < arr[j]
	})
	
	// Assign the first integer in the input list to the variable 'length'
	length := arr[0]
	
	// Check if 'length' is perfectly divisible by the largest integer in 'arr'
	if length % arr[2] == 0 {
		// Print the quotient and return if true
		fmt.Println(length / arr[2])
		return
	}
	
	// Initialize 'ans' to 0 for storing the maximum number of ribbons
	ans := 0
	
	// If the two smaller integers are equal, proceed with this block
	if arr[0] == arr[1] {
		k := 0
		// Iterate through possible combinations of the two smaller integers
		for i := 0; i <= length / arr[2]; i++ {
			check := length - i * arr[2]
			if check >= 0 && check % arr[0] == 0 {
				k = check / arr[0]
				if k + i > ans {
					ans = k + i
				}
			}
		}
	} else {
		// If the two smaller integers are not equal, iterate through all three integers
		for i := 0; i <= length / arr[2]; i++ {
			for j := 0; j <= length / arr[1]; j++ {
				check := length - i * arr[2] - j * arr[1]
				if check >= 0 && check % arr[0] == 0 {
					k := check / arr[0]
					if k + i + j > ans {
						ans = k + i + j
					}
				}
			}
		}
	}
	
	// Print the maximum number of ribbons that can be cut and return
	fmt.Println(ans)
}

func main() {
	cutRibbon()
}

