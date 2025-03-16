package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	inputArray := make([][4]int, n)

	for i := 0; i < n; i++ {
		parts := readLine(reader)
		var S, R, H, C int
		fmt.Sscanf(parts, "%d %d %d %d", &S, &R, &H, &C)
		inputArray[i] = [4]int{S, R, H, C}
	}

	outdated := make([][4]int, 0)

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if inputArray[i][0] < inputArray[j][0] &&
				inputArray[i][1] < inputArray[j][1] &&
				inputArray[i][2] < inputArray[j][2] {
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
		if !isOutdated(currentItem, outdated) && cost < minimumCost {
			minimumCost = cost
			inputNumber = i + 1
		}
	}

	fmt.Println(inputNumber)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1]
}

func removeDuplicates(outdated [][4]int) [][4]int {
	uniqueMap := make(map[[4]int]bool)
	uniqueOutdated := make([][4]int, 0)

	for _, item := range outdated {
		if !uniqueMap[item] {
			uniqueMap[item] = true
			uniqueOutdated = append(uniqueOutdated, item)
		}
	}

	return uniqueOutdated
}

func isOutdated(item [4]int, outdated [][4]int) bool {
	for _, outdatedItem := range outdated {
		if item == outdatedItem {
			return true
		}
	}
	return false
}
