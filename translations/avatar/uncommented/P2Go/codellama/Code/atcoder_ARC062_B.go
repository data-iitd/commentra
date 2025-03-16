
package main

import "fmt"

func main() {
	s := []rune(input())
	numG, numP := 0, 0
	score := 0
	for _, x := range s {
		if x == 'g' {
			if numG-numP > 0 {
				score++
				numP++
			} else {
				score = score
				numG++
			}
		} else if x == 'p' {
			if numG-numP > 0 {
				score = score
				numP++
			} else {
				score--
				numG++
			}
		}
	}
	fmt.Println(score)
}

