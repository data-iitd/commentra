package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var train [2]int
	var bus [2]int

	fmt.Scanf("%d %d", &train[0], &train[1])
	fmt.Scanf("%d %d", &bus[0], &bus[1])

	fmt.Printf("%d\n", max(train[0], train[1])+max(bus[0], bus[1]))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

