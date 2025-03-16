
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func canTake(xNeeded, xAvailable, yNeeded, yAvailable int) bool {
	if xNeeded > xAvailable {
		return false
	}
	if yNeeded > yAvailable {
		return false
	}
	return true
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	inputValues := strings.Split(input, " ")
	x, _ := strconv.Atoi(inputValues[0])
	y, _ := strconv.Atoi(inputValues[1])
	turn := 0
	for {
		if turn%2 == 0 {
			if canTake(2, x, 2, y) {
				x -= 2
				y -= 2
			} else if canTake(1, x, 12, y) {
				x -= 1
				y -= 12
			} else if canTake(0, x, 22, y) {
				y -= 22
			} else {
				fmt.Println("Hanako")
				return
			}
		} else {
			if canTake(0, x, 22, y) {
				y -= 22
			} else if canTake(1, x, 12, y) {
				x -= 1
				y -= 12
			} else if canTake(2, x, 2, y) {
				x -= 2
				y -= 2
			} else {
				fmt.Println("Ciel")
				return
			}
		}
		turn++
	}
}

