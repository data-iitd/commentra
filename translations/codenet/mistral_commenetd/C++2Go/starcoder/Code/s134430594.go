<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a struct to store information about intervals
type Ban struct {
	l, r, val int
}

// Define a struct to store the minimum value in each segment of the segment tree
type Sp struct {
	mn [20][200007]int
}

// A function to initialize the segment tree
func (s *Sp) init(a []int) {
	n := len(a)
	// Initialize the first level of the segment tree
	for i := 0; i < n; i++ {
		s.mn[0][i] = a[i] // Store the value of the element at index i in the first level of the segment tree
	}
	// Build the segment tree recursively
	for i := 0; i + 1 < 20; i++ {
		for j := 0; j + (1 << (i + 1)) <= n; j++ {
			s.mn[i + 1][j] = max(s.mn[i][j], s.mn[i][j + (1 << i)]) // Find the minimum value in the current segment and store it in the next level of the segment tree
		}
	}
}

// A function to get the minimum value in a segment of the segment tree
func (s *Sp) get(l, r int) int {
	r++ // Adjust the index of the right endpoint of the segment to be one more than the actual index
	p := 1 << uint(r - l) // Calculate the depth of the segment tree for the given segment
	return min(s.mn[p][l], s.mn[p][r - (1 << p)]) // Return the minimum value in the given segment
}

func main() {
	// Read the number of elements in the array
	var n int
	fmt.Scanln(&n)

	// Read the elements of the array
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanln(&a[i])
	}

	// Initialize some variables
	dl := make([]int, n) // An array to store the difference between the index and the index of the element in the array
	ans := 0               // The answer
	bans := make([]Ban, 0) // A vector to store some information about the intervals

	// Calculate the differences between the indices and the elements in the array
	for i := 0; i < n; i++ {
		if a[i] > i { // Check if the element is out of its position
			fmt.Println(-1) // Output -1 if the element is out of its position
			return
		}
		dl[i] = i - a[i] // Calculate the difference between the index and the element
	}

	// Calculate the answer and store some information about the intervals in a vector
	for i := 0; i < n; i++ {
		r := i // Initialize a variable to store the right endpoint of the current interval
		for r + 1 < n && a[r] + 1 == a[r + 1] { // Check if there is a longer interval with the same value
			r++ // Move to the next index if there is
		}
		ans += a[r] // Add the value of the right endpoint of the current interval to the answer
		i = r      // Update the index to be the right endpoint of the current interval
		bans = append(bans, Ban{r - a[r], r, r - a[r]}) // Store some information about the current interval in the vector
	}

	// Initialize the segment tree using the differences between the indices and the elements in the array
	s := new(Sp)
	s.init(dl)

	// Check some conditions and calculate the answer if possible
	for _, t := range bans {
		if s.get(t.l, t.r) > t.val { // Check if the minimum value in the segment of the segment tree is greater than the value of the interval
			fmt.Println(-1) // Output -1 if the condition is not satisfied
			return
		}
	}

	// Output the answer
	fmt.Println(ans)
}

