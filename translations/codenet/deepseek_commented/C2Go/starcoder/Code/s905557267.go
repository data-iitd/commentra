<<<<<<< HEAD

import (
=======
package main

import (
	"bufio"
>>>>>>> 98c87cb78a (data updated)
	"fmt"
	"os"
	"strconv"
	"strings"
)

<<<<<<< HEAD
// min returns the minimum of two integers
=======
// Function to return the smaller of two integers
>>>>>>> 98c87cb78a (data updated)
func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

<<<<<<< HEAD
// Chain removes chains of four or more consecutive identical elements
func Chain(b []int) int {
	n := len(b)
	a := make([]int, n)
	copy(a, b)
	i := 0
	for i < n-4 {
		if a[i]!= 0 && a[i] == a[i+1] && a[i] == a[i+2] && a[i] == a[i+3] {
			// Debugging output to show the array before removal
			// fmt.Printf("-----\n")
			// for j := 0; j < n; j++ {
			// 	fmt.Printf("%d\n", a[j])
			// }
			// fmt.Printf("-----\n")

			count := 0
			color := a[i]
			for j := i; a[j] == color; j++ {
				a[j] = 0
				count++
			}
			for j := 0; i+j+count < n; j++ {
=======
// Function to remove chains of four or more consecutive identical elements
func Chain(b []int, n int) int {
	var i, j int
	var count int // To count the length of the chain
	var color int // To store the color of the chain
	var a []int // Temporary array to hold the modified sequence

	// Copy the original array to a temporary array
	a = make([]int, n)
	for i = 0; i < n; i++ {
		a[i] = b[i]
	}

	// Iterate through the array to find and remove chains of four or more elements
	for i = 0; i < n-4; i++ {
		if a[i]!= 0 && a[i] == a[i+1] && a[i] == a[i+2] && a[i] == a[i+3] {
			// Debugging output to show the array before removal
			/*
			fmt.Println("-----")
			for j = 0; j < n; j++ {
				fmt.Println(a[j])
			}
			fmt.Println("-----")
			*/

			count = 0
			color = a[i]

			// Remove the chain by setting all elements to 0
			for j = i; a[j] == color; j++ {
				a[j] = 0
				count++
			}

			// Shift the remaining elements to fill the gap left by the removed chain
			for j = 0; i+j+count < 10000; j++ {
>>>>>>> 98c87cb78a (data updated)
				a[i+j] = a[i+j+count]
				a[i+j+count] = 0
			}

			// Debugging output to show the array after removal
<<<<<<< HEAD
			// fmt.Printf("-----\n")
			// for j := 0; j < n; j++ {
			// 	fmt.Printf("%d\n", a[j])
			// }
			// fmt.Printf("-----\n")

			i = 0
		}
		i++
	}

	count := 0
	for a[count]!= 0 {
		count++
=======
			/*
			fmt.Println("-----")
			for j = 0; j < n; j++ {
				fmt.Println(a[j])
			}
			fmt.Println("-----")
			*/

			// Reset the index to start checking from the beginning
			i = 0
		}

	}

	count = 0
	for count = 0; a[count]!= 0; count++ {
>>>>>>> 98c87cb78a (data updated)
	}

	// Check if the remaining sequence is a chain of four or more elements
	if count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3] {
		return 0
	}

	return count
}

<<<<<<< HEAD
func main() {
	var n int
	var i, j int
	var a [10000]int
	var ans int
	var color int

	for {
		// Initialize the array with zeros
=======
// Main function to read input, process it, and print the result
func main() {
	var n int
	var i, j int
	var a []int
	var ans int
	var color int

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		// Initialize the array with zeros
		a = make([]int, 10000)
>>>>>>> 98c87cb78a (data updated)
		for i = 0; i < 10000; i++ {
			a[i] = 0
		}

		// Read the number of elements
<<<<<<< HEAD
		fmt.Scanf("%d", &n)
=======
		n, _ = strconv.Atoi(scanner.Text())
>>>>>>> 98c87cb78a (data updated)
		if n == 0 {
			break
		}
		ans = n

		// Read the elements themselves
		for i = 0; i < n; i++ {
<<<<<<< HEAD
			fmt.Scanf("%d", &a[i])
=======
			a[i], _ = strconv.Atoi(scanner.Text())
>>>>>>> 98c87cb78a (data updated)
		}

		// Iterate over possible starting points for chains of four or more elements
		for i = 0; i < n-4; i++ {
<<<<<<< HEAD
			count := [3]int{0, 0, 0} // To count occurrences of each color
=======
			var count [3]int // To count occurrences of each color
>>>>>>> 98c87cb78a (data updated)
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
<<<<<<< HEAD
					buf := a[j]
					a[j] = color
					ans = min(ans, Chain(a[:n]))
=======
					var buf int
					buf = a[j]
					a[j] = color
					ans = min(ans, Chain(a, n))
>>>>>>> 98c87cb78a (data updated)
					a[j] = buf
				}
			}
		}

		// Print the minimum length after processing
<<<<<<< HEAD
		fmt.Printf("%d\n", ans)
=======
		fmt.Println(ans)
>>>>>>> 98c87cb78a (data updated)
	}
}

