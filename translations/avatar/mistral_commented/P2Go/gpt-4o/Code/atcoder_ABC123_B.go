package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
)

func main() {
	// Initialize an empty slice called menu
	var menu [][]int

	// Use a for loop to iterate 5 times
	for i := 0; i < 5; i++ {
		var m string
		fmt.Scanln(&m)

		// Extract the last character of the string m to determine the exponent e
		e, _ := strconv.Atoi(string(m[len(m)-1]))

		// If e is 0, set it to 10
		if e == 0 {
			e = 10
		}

		// Append a slice containing the integer value of m and the exponent e to the menu slice
		value, _ := strconv.Atoi(m)
		menu = append(menu, []int{value, e})
	}

	// Sort the menu slice based on the exponent value
	sort.Slice(menu, func(i, j int) bool {
		return menu[i][1] < menu[j][1]
	})

	// Initialize a variable called ans to 0
	ans := 0

	// Use a for loop to iterate through the menu slice starting from the second element (index 1)
	for _, m := range menu[1:] {
		// Calculate the number of full 10s that can be obtained by dividing the integer value by 10 and rounding up
		numFull10s := int(math.Ceil(float64(m[0]) / 10))

		// Multiply this value by 10 and add it to the ans variable
		ans += numFull10s * 10
	}

	// Finally, print the sum of the first element in the menu slice (which is the initial number) and the value of ans
	fmt.Println(menu[0][0] + ans)
}

// <END-OF-CODE>
