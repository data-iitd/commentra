package main

import (
	"fmt"
)

func main() {
	var input string
	fmt.Scan(&input)

	numG, numP := 0, 0
	score := 0

	for _, x := range input {
		if x == 'g' {
			if numG-numP > 0 {
				score++
				numP++
			} else {
				// score remains the same
				numG++
			}
		} else if x == 'p' {
			if numG-numP > 0 {
				// score remains the same
				numP++
			} else {
				score--
				numG++
			}
		}
	}
	fmt.Println(score)
}

// <END-OF-CODE>
