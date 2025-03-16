package main

import (
	"fmt"
	"math"
)

func main() {
	menu := [][]int{} // Initialize an empty slice to store menu items

	// Loop to collect 5 menu items from user input
	for i := 0; i < 5; i++ {
		var m string
		fmt.Scan(&m) // Take input from the user
		e := int(m[len(m)-1] - '0') // Extract the last character of the input and convert it to an integer
		if e == 0 {
			e = 10 // Change it to 10 (to avoid zero as a value)
		}
		menu = append(menu, []int{mToInt(m), e}) // Append a slice containing the integer value of m and e to the menu
	}

	// Sort the menu based on the second element (e) of each slice
	sortMenu(menu)

	ans := 0 // Initialize a variable to accumulate the total cost

	// Loop through the sorted menu starting from the second item
	for _, m := range menu[1:] {
		// Calculate the cost for each item, rounding up to the nearest multiple of 10
		ans += int(math.Ceil(float64(m[0]) / 10)) * 10
	}

	// Print the total cost, including the first item's original value
	fmt.Println(ans + menu[0][0]) // Add the first item's value to the accumulated cost and print the result
}

// Helper function to convert string to integer
func mToInt(m string) int {
	var result int
	for _, char := range m {
		result = result*10 + int(char-'0')
	}
	return result
}

// Helper function to sort the menu based on the second element (e) of each slice
func sortMenu(menu [][]int) {
	for i := 0; i < len(menu); i++ {
		for j := i + 1; j < len(menu); j++ {
			if menu[i][1] > menu[j][1] {
				menu[i], menu[j] = menu[j], menu[i]
			}
		}
	}
}

