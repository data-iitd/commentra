
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize Scanner to read input from standard input
	input := bufio.NewScanner(os.Stdin)
	// Initialize PrintWriter to write output to standard output
	out := bufio.NewWriter(os.Stdout)

	// Read the number of elements
	n, _ := strconv.Atoi(input.Text())

	// Initialize a 2D array to store the elements
	vec := make([][]int, n)
	for i := 0; i < n; i++ {
		vec[i] = make([]int, 4)
	}

	// Read the elements into the 2D array
	for i := 0; i < n; i++ {
		for j := 0; j < 4; j++ {
			vec[i][j], _ = strconv.Atoi(input.Text())
		}
	}

	// Initialize variables to store the best index and its price
	ans := 500
	ansprice := 20000

	// Loop through each element to find the best one
	for i := 0; i < n; i++ {
		fl := 1

		// Compare the current element with every other element
		for j := 0; j < n; j++ {
			if vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2] {
				fl = 0 // The element is dominated
			}
		}

		// If the element is not dominated, check its price
		if fl == 1 {
			if vec[i][3] < ansprice {
				ansprice = vec[i][3] // Update the minimum price
				ans = i + 1           // Update the best index
			}
		}
	}

	// Output the index of the best element
	fmt.Println(ans)

	// Close the PrintWriter to release resources
	out.Flush()
}

