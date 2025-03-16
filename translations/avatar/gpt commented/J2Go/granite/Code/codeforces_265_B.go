
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new scanner to read input from the console
	scn := bufio.NewScanner(os.Stdin)

	// Read the number of elements in the array
	scn.Scan()
	n, _ := strconv.Atoi(scn.Text())

	// Initialize an array to hold the input integers
	arr := make([]int, n)

	// Populate the array with integers from user input
	for i := 0; i < n; i++ {
		scn.Scan()
		arr[i], _ = strconv.Atoi(scn.Text())
	}

	// Initialize the answer with the first element of the array plus one
	ans := arr[0] + 1

	// Calculate the total distance based on the differences between consecutive elements
	for i := 1; i < n; i++ {
		// Add the absolute difference between the current and previous element, plus 2
		ans += int(math.Abs(float64(arr[i]-arr[i-1]))) + 2
	}

	// Output the final calculated answer
	fmt.Println(ans)
}

