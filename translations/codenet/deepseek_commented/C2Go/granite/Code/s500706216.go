
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Define the size of the arrays
	const MAX_SIZE = 200000

	// Define the data type for large integers
	type ll = int64

	// Declare the arrays and variables
	var (
		n, k int
		a     [MAX_SIZE]int
		tmpa  [MAX_SIZE]int
		light [MAX_SIZE + 10]int
	)

	// Read the values of n and k from standard input
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d\n", &n, &k)

	// Read n integers from standard input and store them in array a
	for i := 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &a[i])
	}

	// Initialize the light array based on the initial positions of the lights
	for i := 0; i < n; i++ {
		r, l := i-a[i], i+a[i]
		if r < 0 {
			r = 0
		}
		if l > n {
			l = n + 1
		}
		light[r]++
		light[l]--
	}

	// Debugging: Print the light array
	// for i := 0; i <= n; i++ {
	// 	fmt.Printf("%d ", light[i])
	// }
	// fmt.Println()

	// Apply the lights k times
	for i := 0; i < k; i++ {
		sum := 0
		// Update array a based on the light array
		for j := 0; j < n; j++ {
			tmpa[j] = a[j]
			sum += light[j]
			a[j] = sum
		}

		// Adjust the light array based on the new state of array a
		for j := 0; j < n; j++ {
			r, l := j-tmpa[j], j+tmpa[j]
			if r < 0 {
				r = 0
			}
			if l > n {
				l = n + 1
			}
			light[r]--
			light[l]++
			r, l = j-a[j], j+a[j]
			if r < 0 {
				r = 0
			}
			if l > n {
				l = n + 1
			}
			light[r]++
			light[l]--
		}

		// Check if the array a has become stable
		isSame := true
		for j := 0; j < n-1; j++ {
			if a[j]!= a[j+1] {
				isSame = false
				break
			}
		}

		// Check if the array a is stable and the first element is n
		if isSame && a[0] == n {
			break
		}

		// Debugging: Print the array a after each iteration
		// for j := 0; j < n; j++ {
		// 	fmt.Printf("%d", a[j])
		// 	if j == n-1 {
		// 		fmt.Println()
		// 	} else {
		// 		fmt.Printf(" ")
		// 	}
		// }
	}

	// Print the final state of array a
	for j := 0; j < n; j++ {
		fmt.Printf("%d", a[j])
		if j == n-1 {
			fmt.Println()
		} else {
			fmt.Printf(" ")
		}
	}
}

