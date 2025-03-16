package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	inputArray := make([][4]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&inputArray[i][0], &inputArray[i][1], &inputArray[i][2], &inputArray[i][3])
	}

	outdated := make(map[[4]int]struct{})
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if inputArray[i][0] < inputArray[j][0] && inputArray[i][1] < inputArray[j][1] && inputArray[i][2] < inputArray[j][2] {
				outdated[inputArray[i]] = struct{}{}
			}
		}
	}

	minimumCost := 100000
	inputNumber := 0
	for i := 0; i < n; i++ {
		currentItem := inputArray[i]
		cost := currentItem[3]
		if _, exists := outdated[currentItem]; !exists && cost < minimumCost {
			minimumCost = cost
			inputNumber = i + 1
		}
	}

	fmt.Println(inputNumber)
}

// <END-OF-CODE>
