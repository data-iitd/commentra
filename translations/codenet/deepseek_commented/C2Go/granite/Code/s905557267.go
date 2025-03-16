
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func Chain(b []int, n int) int {
	i, j := 0, 0
	count, color := 0, 0
	a := make([]int, n)

	// Copy the original array to a temporary array
	for i = 0; i < n; i++ {
		a[i] = b[i]
	}

	// Iterate through the array to find and remove chains of four or more elements
	for i = 0; i < n-4; i++ {
		if a[i]!= 0 && a[i] == a[i+1] && a[i] == a[i+2] && a[i] == a[i+3] {
			// Debugging output to show the array before removal
			// fmt.Printf("-----\n")
			// for j = 0; j < n; j++ {
			// 	fmt.Printf("%d\n", a[j])
			// }
			// fmt.Printf("-----\n")

			count = 0
			color = a[i]

			// Remove the chain by setting all elements to 0
			for j = i; a[j] == color; j++ {
				a[j] = 0
				count++
			}

			// Shift the remaining elements to fill the gap left by the removed chain
			for j = 0; i+j+count < 10000; j++ {
				a[i+j] = a[i+j+count]
				a[i+j+count] = 0
			}

			// Debugging output to show the array after removal
			// fmt.Printf("-----\n")
			// for j = 0; j < n; j++ {
			// 	fmt.Printf("%d\n", a[j])
			// }
			// fmt.Printf("-----\n")

			// Reset the index to start checking from the beginning
			i = 0
		}
	}

	count = 0
	for a[count]!= 0 {
		count++
	}

	// Check if the remaining sequence is a chain of four or more elements
	if count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3] {
		return 0
	}

	return count
}

func main() {
	var n int
	var i, j int
	var a []int
	var ans, color int
	scanner := bufio.NewScanner(os.Stdin)

	for {
		// Initialize the array with zeros
		a = make([]int, 10000)
		for i = 0; i < 10000; i++ {
			a[i] = 0
		}

		// Read the number of elements
		if!scanner.Scan() {
			break
		}
		n, _ = strconv.Atoi(scanner.Text())
		if n == 0 {
			break
		}
		ans = n

		// Read the elements themselves
		for i = 0; i < n; i++ {
			if!scanner.Scan() {
				break
			}
			a[i], _ = strconv.Atoi(scanner.Text())
		}

		// Iterate over possible starting points for chains of four or more elements
		for i = 0; i < n-4; i++ {
			count := [3]int{0, 0, 0} // To count occurrences of each color
			for j = i; j < i+4; j++ {
				if a[j]-1 >= 0 {
					count[a[j]-1]++
				}
			}

			color = 0
			for j = 0; j < 3; j++ {
				if count[j] >= 3 {
					color = j + 1
					break
				}
			}

			if color!= 0 {
				for j = i; j < i+4; j++ {
					buf := a[j]
					a[j] = color
					ans = min(ans, Chain(a, n))
					a[j] = buf
				}
			}
		}

		// Print the minimum length after processing
		fmt.Println(ans)
	}
}

