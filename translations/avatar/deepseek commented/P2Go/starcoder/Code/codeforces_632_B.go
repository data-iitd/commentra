
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Take input from the user
	reader := bufio.NewReader(os.Stdin)
	reader.ReadString('\n')
	// Process the input to get a tuple of (value, type) pairs for each piece
	pieces := processInput(reader)
	// Call the Bob_sMaxStrength function with the processed pieces and return its result
	fmt.Println(Bob_sMaxStrength(pieces))
}

func processInput(reader *bufio.Reader) [][2]int {
	pieces := make([][2]int, 0)
	for {
		line, _, err := reader.ReadLine()
		if err!= nil {
			break
		}
		pieces = append(pieces, [2]int{
			int(strings.TrimSpace(string(line))),
			int(strings.TrimSpace(string(reader.ReadString('\n')))[0]),
		})
	}
	return pieces
}

func Bob_sMaxStrength(pieces [][2]int) int {
	// Initialize scores for both ends and their maximum scores
	pScore := sScore := pMaxScore := sMaxScore := 0
	for _, piece := range pieces {
		if piece[1] == 'B' {
			pScore += piece[0]
			if pScore > pMaxScore {
				pMaxScore = pScore
		} else {
			pScore -= piece[0]
		}
	}
	for i := len(pieces) - 1; i >= 0; i-- {
		if pieces[i][1] == 'B' {
			sScore += pieces[i][0]
			if sScore > sMaxScore {
				sMaxScore = sScore
		} else {
			sScore -= pieces[i][0]
		}
	}
	// Return the maximum score between the two ends
	if pMaxScore > sMaxScore {
		return pMaxScore
	}
	return sMaxScore
}

