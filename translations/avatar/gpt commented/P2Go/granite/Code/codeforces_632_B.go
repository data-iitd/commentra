
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input (the first input is ignored)
	reader := bufio.NewReader(os.Stdin)
	reader.ReadString('\n')

	// Read the second line of input, split it into integers and corresponding characters,
	// and create a tuple of pieces where each piece is a tuple of (score, character)
	nTemp, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nTemp)
	pieces := make([][2]int, n)
	for i := 0; i < n; i++ {
		temp, _ := reader.ReadString(' ')
		score, _ := strconv.Atoi(temp)
		pieces[i][0] = score
		pieces[i][1], _ = reader.ReadString('\n')
	}

	// Call the function to calculate Bob's maximum strength and return the result
	fmt.Println(Bob_sMaxStrength(pieces))
}

func Bob_sMaxStrength(pieces [][2]int) int {
	// Initialize scores for player A and player B, and their maximum scores
	pScore := sScore := pMaxScore := sMaxScore := 0
	for _, piece := range pieces {
		if piece[1] == "B" {
			pScore += piece[0]
		} else {
			pScore -= piece[0]
		}
		if pScore > pMaxScore {
			pMaxScore = pScore
		}
	}
	for i := len(pieces) - 1; i >= 0; i-- {
		if pieces[i][1] == "B" {
			sScore += pieces[i][0]
		} else {
			sScore -= pieces[i][0]
		}
		if sScore > sMaxScore {
			sMaxScore = sScore
		}
	}
	if pMaxScore > sMaxScore {
		return pMaxScore
	}
	return sMaxScore
}

