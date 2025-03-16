package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of items from the input

	vec := make([][4]int, n) // Creating a 2D array of size n x 4 to store the items

	// Initializing the 2D array with input values
	for i := 0; i < n; i++ {
		fmt.Scan(&vec[i][0], &vec[i][1], &vec[i][2], &vec[i][3]) // Reading the elements of the current item
	}

	ans := 500      // Initializing answer variables with default values
	ansprice := 20000

	// Finding the answer by comparing all items and keeping track of the minimum price item found so far
	for i := 0; i < n; i++ {
		flag := 1 // Initializing a flag variable to check if the current item is smaller than all other items

		for j := 0; j < n; j++ {
			if vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2] {
				flag = 0 // If the current item is smaller than the other item, set the flag to 0
				break    // Exit the inner loop as we don't need to check further if the current item is smaller
			}
		}

		if flag == 1 { // If the current item is not smaller than any other item, check if its price is lower than the current answer
			if vec[i][3] < ansprice {
				ansprice = vec[i][3] // Update the answer price if the current item's price is lower
				ans = i + 1          // Update the answer index
			}
		}
	}

	// Printing the answer
	fmt.Println(ans)
}

// <END-OF-CODE>
