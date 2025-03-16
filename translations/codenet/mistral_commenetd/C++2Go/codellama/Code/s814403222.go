
package main

import (
	"fmt"
	"sort"
)

// Define a pair type with first integer and second string
type P struct {
	first  int
	second string
}

// Initialize an array of pairs v with size n
var v [22]P

// Initialize a vector of integers d with size 33
var d [33][]int

// Main function
func main() {
	// Read the number of test cases n
	for {
		var n int
		fmt.Scan(&n)
		if n == 0 {
			break
		}

		// Initialize d array for each test case
		for i := 0; i < 33; i++ {
			d[i] = d[i][:0]
		}

		// Process each test case
		for i := 0; i < n; i++ {
			// Initialize the first element of pair v[i] as 0
			v[i].first = 0

			// Read the name and number of students m for the current test case
			var m int
			fmt.Scan(&v[i].second, &m)

			// For each student, read the number of absences a and update the scores accordingly
			for j := 0; j < m; j++ {
				var a int
				// Read the number of absences a for the current student
				fmt.Scan(&a)

				// Calculate the effect of the current student's absences on the scores of other students
				v[i].first += n - len(d[a])

				// Update the scores of students who have the same number of absences as the current student
				for k := 0; k < len(d[a]); k++ {
					// Decrease the score of the student whose index is in d[a] by 1
					v[d[a][k]].first--
				}

				// Add the index of the current student to the vector d[a]
				d[a] = append(d[a], i)
			}
		}

		// Sort the pairs in the array v in ascending order based on their first elements
		sort.Slice(v[:n], func(i, j int) bool {
			return v[i].first < v[j].first
		})

		// Print the name and the highest score of the student with the highest score
		fmt.Println(v[0].first, v[0].second)
	}
}

