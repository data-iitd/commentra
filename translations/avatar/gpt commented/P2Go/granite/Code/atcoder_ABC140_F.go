
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Function to read a single integer from standard input
func I() int {
	s := readLine()
	i, _ := strconv.Atoi(s)
	return i
}

// Function to read a list of integers from standard input
func LI() []int {
	s := readLine()
	a := make([]int, 0)
	for _, x := range strings.Split(s, " ") {
		i, _ := strconv.Atoi(x)
		a = append(a, i)
	}
	return a
}

func main() {
	// Read the number of elements
	N := I()

	// Read the list of integers, sort it in descending order
	S := LI()
	sort.Slice(S, func(i, j int) bool {
		return S[i] > S[j]
	})

	// Initialize a flag list to track which elements have been used
	flag := make([]bool, len(S))
	for i := range flag {
		flag[i] = true
	}

	// Initialize the current list with the largest element
	cur := make([]int, 0)
	cur = append(cur, S[0])

	// Mark the first element as used
	flag[0] = false

	// Iterate N times to build the current list
	for i := 0; i < N; i++ {
		j := 0 // Index for the current list
		jM := len(cur) // Length of the current list

		// Try to find the next largest unused element
		for k := 0; k < len(S); k++ {
			// Check if the current element is unused and smaller than the last added element
			if flag[k] && S[k] < cur[j] {
				cur = append(cur, S[k]) // Add the element to the current list
				j++ // Move to the next index in the current list
				flag[k] = false // Mark this element as used

				// If we have added enough elements, break out of the loop
				if j == jM {
					break
				}
			}
		}

		// Sort the current list in descending order for the next iteration
		sort.Slice(cur, func(i, j int) bool {
			return cur[i] > cur[j]
		})
	}

	// If we successfully built the list, print "Yes"
	fmt.Println("Yes")
}

// Function to read a single line from standard input
func readLine() string {
	buf := new(bytes.Buffer)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	buf.Read(scanner.Bytes())
	return buf.String()
}

// Entry point of the program
func main() {
	main()
}
