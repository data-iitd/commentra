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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	// Process the input to get a tuple of (value, type) pairs for each piece
	pieces := make([][2]interface{}, 0)
	scanner.Scan()
	values := strings.Split(scanner.Text(), " ")
	types := scanner.Text()
	for i := 0; i < len(values); i++ {
		value, _ := strconv.Atoi(values[i])
		pieces = append(pieces, [2]interface{}{value, string(types[i])})
	}
	// Call the Bob_sMaxStrength function with the processed pieces and return its result
	fmt.Println(Bob_sMaxStrength(pieces))
}

func Bob_sMaxStrength(pieces [][2]interface{}) int {
	// Initialize scores for both ends and their maximum scores
	pScore := 0
	sScore := 0
	pMaxScore := 0
	sMaxScore := 0
	
	for _, piece := range pieces {
		if piece[1] == "B" {
			pScore += piece[0].(int)
		} else {
			pScore -= piece[0].(int)
		}
		if pScore > pMaxScore {
			pMaxScore = pScore
		}
	}
	
	for i := len(pieces) - 1; i >= 0; i-- {
		if pieces[i][1] == "B" {
			sScore += pieces[i][0].(int)
		} else {
			sScore -= pieces[i][0].(int)
		}
		if sScore > sMaxScore {
			sMaxScore = sScore
		}
	}
	
	// Return the maximum score between the two ends
	if pMaxScore > sMaxScore {
		return pMaxScore
	}
	return sMaxScore
}

