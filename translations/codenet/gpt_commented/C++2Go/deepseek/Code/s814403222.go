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
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of participants until a zero is encountered
	for {
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())
		if n == 0 {
			break
		}

		int m int

		// Clear the previous data in the vector of lists
		for i := 0; i < 33; i++ {
			d[i] = []int{}
		}

		// Loop through each participant
		for i := 0; i < n; i++ {
			v[i].first = 0

			// Read the participant's name and the number of scores
			scanner.Scan()
			line := scanner.Text()
			parts := strings.Split(line, " ")
			v[i].second = parts[0]
			m, _ = strconv.Atoi(parts[1])

			// Loop through each score for the current participant
			for j := 0; j < m; j++ {
				scanner.Scan()
				a, _ := strconv.Atoi(scanner.Text())

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
		fmt.Println(v[0].first, v[0].second)
	}
}

