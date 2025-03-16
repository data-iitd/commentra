
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize an empty list called menu
	var menu [][2]int

	// Use a for loop to iterate 5 times
	for i := 0; i < 5; i++ {
		// Take user input and assign it to the variable m
		m := bufio.NewScanner(os.Stdin)
		m.Scan()
		m = strings.Split(m.Text(), " ")

		// Extract the last character of the string m to determine the exponent e
		e, _ := strconv.Atoi(m[1][len(m[1])-1:])

		// If e is 0, set it to 10
		if e == 0 {
			e = 10
		}

		// Append a list containing the integer value of m and the exponent e to the menu list
		menu = append(menu, [2]int{int(m[0]), e})
	}

	// Sort the menu list based on the exponent value using the sort() method with a lambda function as the key
	sort.Slice(menu, func(i, j int) bool {
		return menu[i][1] < menu[j][1]
	})

	// Initialize a variable called ans to 0
	ans := 0

	// Use a for loop to iterate through the menu list starting from the second element (index 1)
	for _, m := range menu[1:] {
		// Calculate the number of full 10s that can be obtained by dividing the integer value by 10 and rounding up using the ceil() function from the math module
		num_full_10s := int(math.Ceil(float64(m[0]) / 10))

		// Multiply this value by 10 and add it to the ans variable
		ans += num_full_10s * 10
	}

	// Finally, print the sum of the first element in the menu list (which is the initial number) and the value of ans
	fmt.Println(menu[0][0] + ans)
}

