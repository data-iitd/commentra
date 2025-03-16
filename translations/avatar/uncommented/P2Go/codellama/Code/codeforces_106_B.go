package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	inputArray := make([][]int, n)
	for i := 0; i < n; i++ {
		input := strings.Split(fmt.Scanln(), " ")
		inputArray[i] = make([]int, 4)
		for j := 0; j < 4; j++ {
			inputArray[i][j], _ = strconv.Atoi(input[j])
		}
	}
	outdated := make([][]int, 0)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if inputArray[i][0] < inputArray[j][0] && inputArray[i][1] < inputArray[j][1] && inputArray[i][2] < inputArray[j][2] {
				outdated = append(outdated, inputArray[i])
			}
		}
	}
	outdated = removeDuplicates(outdated)
	minimumCost := 100000
	inputNumber := 0
	for i := 0; i < n; i++ {
		currentItem := inputArray[i]
		cost := currentItem[3]
		if !contains(outdated, currentItem) && cost < minimumCost {
			minimumCost = cost
			inputNumber = i + 1
		}
	}
	fmt.Println(inputNumber)
}

func removeDuplicates(s [][]int) [][]int {
	seen := make(map[string]bool)
	j := 0
	for i := 0; i < len(s); i++ {
		if !seen[string(s[i])] {
			seen[string(s[i])] = true
			s[j] = s[i]
			j++
		}
	}
	return s[:j]
}

func contains(s [][]int, e []int) bool {
	for _, a := range s {
		if a[0] == e[0] && a[1] == e[1] && a[2] == e[2] && a[3] == e[3] {
			return true
		}
	}
	return false
}

