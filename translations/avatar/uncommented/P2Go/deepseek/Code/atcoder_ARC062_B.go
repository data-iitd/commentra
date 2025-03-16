package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	s := []rune(input)
	numG, numP := 0, 0
	score := 0

	for _, x := range s {
		if x == 'g' {
			if numG-numP > 0 {
				score += 1
				numP += 1
			} else {
				score = score
				numG += 1
			}
		} else if x == 'p' {
			if numG-numP > 0 {
				score = score
				numP += 1
			} else {
				score -= 1
				numG += 1
			}
		}
	}
	fmt.Println(score)
}

