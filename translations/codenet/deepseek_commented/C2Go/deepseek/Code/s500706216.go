package main

import (
	"fmt"
)

// Define the size of the arrays
const MAX_SIZE = 200000

// Define the data type for large integers
type ll int

// Declare the arrays and variables
var a, tmpa [MAX_SIZE]int
var light [MAX_SIZE + 10]int

func main() {
	// Declare variables for input
	var n, k int

	// Read the values of n and k from standard input
	fmt.Scan(&n, &k)

	// Read n integers from standard input and store them in array a
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize the light array based on the initial positions of the lights
	for i := 0; i < n; i++ {
		r := i - a[i]
		l := i + a[i]
		if r < 0 {
			r = 0
		}
		light[r]++
		if l+1 > n {
			l = n + 1
		} else {
			light[l+1]--
		}
	}

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
			r := j - tmpa[j]
			l := j + tmpa[j]
			if r < 0 {
				r = 0
			}
			light[r]--
			if l+1 > n {
				l = n + 1
			} else {
				light[l+1]++
			}
			r = j - a[j]
			l = j + a[j]
			if r < 0 {
				r = 0
			}
			light[r]++
			if l+1 > n {
				l = n + 1
			} else {
				light[l+1]--
			}
		}

		// Check if the array a has become stable
		isSame := true
		for j := 0; j < n-1; j++ {
			if a[j] != a[j+1] {
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
		//     fmt.Printf("%d", a[j])
		//     if j != n-1 {
		//         fmt.Print(" ")
		//     }
		// }
		// fmt.Println()
	}

	// Print the final state of array a
	for j := 0; j < n; j++ {
		fmt.Printf("%d", a[j])
		if j != n-1 {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}
