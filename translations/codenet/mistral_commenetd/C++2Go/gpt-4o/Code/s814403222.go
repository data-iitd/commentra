package main

import (
	"fmt"
	"sort"
)

type Pair struct {
	first  int
	second string
}

func main() {
	var n int
	for {
		// Read the number of test cases n
		if _, err := fmt.Scan(&n); err != nil || n == 0 {
			break
		}

		// Initialize a slice of pairs v
		v := make([]Pair, n)
		// Initialize a slice of slices for absences
		d := make([][]int, 33)

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
				for _, index := range d[a] {
					// Decrease the score of the student whose index is in d[a] by 1
					v[index].first--
				}

				// Add the index of the current student to the slice d[a]
				d[a] = append(d[a], i)
			}
		}

		// Sort the pairs in the slice v in ascending order based on their first elements
		sort.Slice(v, func(i, j int) bool {
			return v[i].first < v[j].first
		})

		// Print the name and the highest score of the student with the highest score
		fmt.Printf("%d %s\n", v[0].first, v[0].second)
	}
}

// <END-OF-CODE>
