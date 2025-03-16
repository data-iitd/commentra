
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Define a pair type with first integer and second string
<<<<<<< HEAD
type P struct {
=======
type Pair struct {
>>>>>>> 98c87cb78a (data updated)
	first  int
	second string
}

// Initialize an array of pairs v with size n
<<<<<<< HEAD
var v [22]P
=======
var v [22]Pair
>>>>>>> 98c87cb78a (data updated)

// Initialize a vector of integers d with size 33
var d [33][]int

// Main function
func main() {
	// Read the number of test cases n
	var n int
	for {
		if _, err := fmt.Scanf("%d", &n); err!= nil {
			break
		}

		// Initialize d array for each test case
		for i := 0; i < 33; i++ {
			d[i] = make([]int, 0)
		}

		// Process each test case
		for i := 0; i < n; i++ {
			// Initialize the first element of pair v[i] as 0
			v[i].first = 0

			// Read the name and number of students m for the current test case
			var m int
<<<<<<< HEAD
			if _, err := fmt.Scanf("%s %d", &v[i].second, &m); err!= nil {
				break
			}
=======
			fmt.Scanf("%s %d", &v[i].second, &m)
>>>>>>> 98c87cb78a (data updated)

			// For each student, read the number of absences a and update the scores accordingly
			for j := 0; j < m; j++ {
				var a int
				// Read the number of absences a for the current student
<<<<<<< HEAD
				if _, err := fmt.Scanf("%d", &a); err!= nil {
					break
				}
=======
				fmt.Scanf("%d", &a)
>>>>>>> 98c87cb78a (data updated)

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
		fmt.Printf("%d %s\n", v[0].first, v[0].second)
	}
}

