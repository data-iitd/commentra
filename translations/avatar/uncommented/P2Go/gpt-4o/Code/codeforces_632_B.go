package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	pieces := make([][2]interface{}, n)

	var scores string
	fmt.Scan(&scores)
	scoreStrings := strings.Split(scores, " ")

	var types string
	fmt.Scan(&types)

	for i := 0; i < n; i++ {
		score, _ := strconv.Atoi(scoreStrings[i])
		pieces[i] = [2]interface{}{score, types[i]}
	}

	fmt.Println(BobsMaxStrength(pieces))
}

func BobsMaxStrength(pieces [][2]interface{}) int {
	pScore := 0
	sScore := 0
	pMaxScore := 0
	sMaxScore := 0

	for _, piece := range pieces {
		if piece[1] == 'B' {
			pScore += piece[0].(int)
		}
	}

	pMaxScore = pScore

	for _, piece := range pieces {
		if piece[1] == 'A' {
			pScore += piece[0].(int)
			if pScore > pMaxScore {
				pMaxScore = pScore
			}
		} else {
			pScore -= piece[0].(int)
		}
	}

	for i := len(pieces) - 1; i >= 0; i-- {
		if pieces[i][1] == 'A' {
			sScore += pieces[i][0].(int)
			if sScore > sMaxScore {
				sMaxScore = sScore
			}
		} else {
			sScore -= pieces[i][0].(int)
		}
	}

	if pMaxScore > sMaxScore {
		return pMaxScore
	}
	return sMaxScore
}

// <END-OF-CODE>
