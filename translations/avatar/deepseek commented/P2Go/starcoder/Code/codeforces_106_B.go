
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
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	inputArray := make([][]int, n)
	for i := 0; i < n; i++ {
		S, R, H, C := strings.Split(readLine(reader), " ")
		S, R, H, C = strconv.Atoi(S), strconv.Atoi(R), strconv.Atoi(H), strconv.Atoi(C)
		inputArray[i] = []int{S, R, H, C}
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
		if currentItem!= nil && cost < minimumCost && currentItem!= outdated {
			minimumCost = cost
			inputNumber = i + 1
	}
	fmt.Println(inputNumber)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func removeDuplicates(inputArray [][]int) [][]int {
	outputArray := make([][]int, 0)
	for i := 0; i < len(inputArray); i++ {
		if inputArray[i]!= nil {
			outputArray = append(outputArray, inputArray[i])
	}
	return outputArray
}

