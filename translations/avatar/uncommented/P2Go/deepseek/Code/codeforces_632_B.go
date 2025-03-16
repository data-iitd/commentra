package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	reader.ReadString('\n')
	input, _ := reader.ReadString('\n')
	pieces := make([][2]interface{}, len(strings.Split(input, " ")))
	nums := strings.Split(strings.TrimSpace(input), " ")
	for i := 0; i < len(nums); i++ {
		num, _ := strconv.Atoi(nums[i])
		pieces[i] = [2]interface{}{num, string(input[i])}
	}
	fmt.Println(Bob_sMaxStrength(pieces))
}

func Bob_sMaxStrength(pieces [][2]interface{}) int {
	pScore := sScore := pMaxScore := sMaxScore := 0
	for _, piece := range pieces {
		if piece[1] == "B" {
			pScore += piece[0].(int)
			if pScore > pMaxScore {
				pMaxScore = pScore
			}
		} else {
			pScore -= piece[0].(int)
		}
	}
	for i := len(pieces) - 1; i >= 0; i-- {
		if pieces[i][1] == "A" {
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
