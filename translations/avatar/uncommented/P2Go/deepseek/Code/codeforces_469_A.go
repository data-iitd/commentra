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
	input, _ := reader.ReadString('\n')
	maxLevel, _ := strconv.Atoi(strings.TrimSpace(input))

	input, _ = reader.ReadString('\n')
	xInput := strings.Split(input, " ")
	x := make([]int, len(xInput))
	for i := 0; i < len(xInput); i++ {
		x[i], _ = strconv.Atoi(xInput[i])
	}
	x = x[1:]

	input, _ = reader.ReadString('\n')
	yInput := strings.Split(input, " ")
	y := make([]int, len(yInput))
	for i := 0; i < len(yInput); i++ {
		y[i], _ = strconv.Atoi(yInput[i])
	}
	y = y[1:]

	xSet := make(map[int]bool)
	ySet := make(map[int]bool)

	for _, val := range x {
		xSet[val] = true
	}
	for _, val := range y {
		ySet[val] = true
	}

	if _, exists := xSet[0]; exists {
		delete(xSet, 0)
	} else if _, exists := ySet[0]; exists {
		delete(ySet, 0)
	}

	unionSet := make(map[int]bool)
	for val := range xSet {
		unionSet[val] = true
	}
	for val := range ySet {
		unionSet[val] = true
	}

	if len(unionSet) != maxLevel {
		fmt.Println("Oh, my keyboard!")
	} else {
		fmt.Println("I become the guy.")
	}
}

