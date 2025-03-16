package main

import (
	"fmt"
	"sort"
)

type Participant struct {
	score int
	name  string
}

func main() {
	var n int

	for {
		// Read the number of participants
		if _, err := fmt.Scan(&n); err != nil || n == 0 {
			break
		}

		m := 0
		participants := make([]Participant, n)
		scoreMap := make([][]int, 33)

		// Loop through each participant
		for i := 0; i < n; i++ {
			participants[i].score = 0 // Initialize the score of the participant to zero

			// Read the participant's name and the number of scores
			fmt.Scan(&participants[i].name, &m)

			// Loop through each score for the current participant
			for j := 0; j < m; j++ {
				var a int // Variable to hold the score value
				fmt.Scan(&a) // Read the score

				// Update the score of the current participant
				participants[i].score += n - len(scoreMap[a])

				// Decrease the score of participants who have already received this score
				for _, idx := range scoreMap[a] {
					participants[idx].score--
				}

				// Add the current participant's index to the list for this score
				scoreMap[a] = append(scoreMap[a], i)
			}
		}

		// Sort the participants based on their scores
		sort.Slice(participants, func(i, j int) bool {
			if participants[i].score == participants[j].score {
				return participants[i].name < participants[j].name
			}
			return participants[i].score > participants[j].score
		})

		// Output the participant with the highest score
		fmt.Printf("%d %s\n", participants[0].score, participants[0].name)
	}
}

// <END-OF-CODE>
