
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read the number of elements (n) and the number of iterations (k)
	var n, k int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d", &n, &k)

	// Input the initial values into the array 'a'
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &a[i])
	}

	// Calculate the influence range for each element in 'a'
	light := make([]int, n+1)
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

	// Perform k iterations to update the array 'a'
	for i := 0; i < k; i++ {
		sum := 0
		tmpa := make([]int, n)
		copy(tmpa, a) // Store the current state of 'a' in 'tmpa'

		// Update 'a' based on the current influence ranges
		for j := 0; j < n; j++ {
			sum += light[j] // Accumulate the influence
			a[j] = sum // Update 'a' with the accumulated influence
		}

		// Update the influence ranges based on the new values in 'a'
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
		}

		// Check if all elements in 'a' are the same and equal to n
		isSame := true
		for j := 0; j < n-1; j++ {
			if a[j]!= a[j+1] {
				isSame = false // Set flag to false if any elements differ
				break
			}
		}
		// If all elements are the same and equal to n, exit the loop
		if isSame && a[0] == n {
			break
		}
	}

	// Output the final state of the array 'a'
	for j := 0; j < n; j++ {
		fmt.Printf("%d", a[j]) // Print each element of 'a'
		if j == n-1 {
			fmt.Println() // Print a newline after the last element
		} else {
			fmt.Print(" ") // Print a space after each element
		}
	}
}

