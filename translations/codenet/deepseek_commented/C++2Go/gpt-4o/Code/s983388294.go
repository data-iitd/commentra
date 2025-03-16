package main

import (
	"fmt"
)

func main() {
	/*
	 * Step 1: Define main function
	 * The main function is the entry point of the program. It initializes variables and processes the input.
	 */
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		/*
		 * Step 2: Read input
		 * The program reads an integer `n` which represents the number of elements in the array.
		 * It then reads `n` integers and stores them in a slice `a`.
		 */
		fmt.Scan(&a[i])
	}

	curr := 0
	for i := 0; i < n; i++ {
		/*
		 * Step 3: Process the array
		 * The program initializes a variable `curr` to 0.
		 * It iterates through the slice `a` and updates `curr` based on the condition `a[i] == curr + 1`.
		 */
		if a[i] == curr+1 {
			curr++
		}
	}

	if curr > 0 {
		/*
		 * Step 4: Output the result
		 * If `curr` is greater than 0, it prints the number of elements that need to be removed to make the sequence continuous, which is `n - curr`.
		 * If `curr` is 0, it prints `-1` indicating that it's not possible to make the sequence continuous.
		 */
		fmt.Println(n - curr)
	} else {
		fmt.Println(-1)
	}

	/*
	 * Step 5: Return from main
	 * The main function ends here, indicating successful execution.
	 */
}
