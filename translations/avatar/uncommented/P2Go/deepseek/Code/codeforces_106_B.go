package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	inputArray := make([][4]int, n)
	for i := 0; i < n; i++ {
		var S, R, H, C int
		fmt.Scan(&S, &R, &H, &C)
		inputArray[i] = [4]int{S, R, H, C}
	}

	outdated := make([][4]int, 0)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if inputArray[i][0] < inputArray[j][0] && inputArray[i][1] < inputArray[j][1] && inputArray[i][2] < inputArray[j][2] {
				outdated = append(outdated, inputArray[i])
			}
		}
	}

	outdatedSet := make(map[[4]int]bool)
	for _, item := range outdated {
		outdatedSet[item] = true
	}

	minimumCost := 100000
	inputNumber := 0
	for i := 0; i < n; i++ {
		currentItem := inputArray[i]
		cost := currentItem[3]
		if _, exists := outdatedSet[currentItem]; !exists && cost < minimumCost {
			minimumCost = cost
			inputNumber = i + 1
		}
	}

	fmt.Println(inputNumber)
}

