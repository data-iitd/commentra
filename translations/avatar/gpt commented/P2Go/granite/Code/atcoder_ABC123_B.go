
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	menu := make([][]int, 5)  // Initialize a 2D slice to store menu items
	reader := bufio.NewReader(os.Stdin)  // Create a buffer reader for user input

	// Loop to collect 5 menu items from user input
	for i := 0; i < 5; i++ {
		m, _ := reader.ReadString('\n')  // Read a line of input from the user
		m = strings.TrimSpace(m)  // Remove leading and trailing whitespace
		e, _ := strconv.Atoi(string(m[len(m)-1]))  // Extract the last character of the input and convert it to an integer
		if e == 0 {  // If the last digit is 0
			e = 10  // Change it to 10 (to avoid zero as a value)
		}
		menu[i] = []int{strconv.Atoi(m), e}  // Append a slice containing the integer value of m and e to the menu
	}

	// Sort the menu based on the second element (e) of each slice
	for i := 0; i < len(menu); i++ {
		for j := i + 1; j < len(menu); j++ {
			if menu[i][1] > menu[j][1] {  // Compare the second element of each slice
				menu[i], menu[j] = menu[j], menu[i]  // Swap the slices if the second element is greater
			}
		}
	}

	ans := 0  // Initialize a variable to accumulate the total cost
	for _, m := range menu[1:] {  // Loop through the sorted menu starting from the second item
		ans += int(math.Ceil(float64(m[0]) / 10)) * 10  // Calculate the cost for each item, rounding up to the nearest multiple of 10
	}
	ans += menu[0][0]  // Add the first item's value to the accumulated cost

	fmt.Println(ans)  // Print the total cost
}

