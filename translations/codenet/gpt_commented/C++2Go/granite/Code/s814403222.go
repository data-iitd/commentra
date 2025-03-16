
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Define a pair type to hold an integer and a string
type P struct {
	first  int
	second string
}

// Array to hold pairs of scores and names
var v [22]P

// Vector to hold lists of indices for each number
var d [33][]int

func main() {
	var n int // Variable to hold the number of participants

	// Read the number of participants until a zero is encountered
	for {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &n)
		if n == 0 {
			break
		}

		var m int // Variable to hold the number of scores for each participant

		// Clear the previous data in the vector of lists
		for i := 0; i < 33; i++ {
			d[i] = d[i][:0]
		}

		// Loop through each participant
		for i := 0; i < n; i++ {
			v[i].first = 0 // Initialize the score of the participant to zero

			// Read the participant's name and the number of scores
			fmt.Fscanf(bufio.NewReader(os.Stdin), "%s%d", &v[i].second, &m)

			// Loop through each score for the current participant
			for j := 0; j < m; j++ {
				var a int // Variable to hold the score value
				fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &a) // Read the score

				// Update the score of the current participant
				v[i].first += n - len(d[a])

				// Decrease the score of participants who have already received this score
				for k := 0; k < len(d[a]); k++ {
					v[d[a][k]].first--
				}

				// Add the current participant's index to the list for this score
				d[a] = append(d[a], i)
			}
		}

		// Sort the participants based on their scores
		sort.Slice(v[:n], func(i, j int) bool {
			return v[i].first > v[j].first
		})

		// Output the participant with the highest score
		fmt.Printf("%d %s\n", v[0].first, v[0].second)
	}
}
