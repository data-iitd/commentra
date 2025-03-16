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
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	a, _ := strconv.Atoi(parts[1])
	b, _ := strconv.Atoi(parts[2])

	input, _ = reader.ReadString('\n')
	listA := []int{}
	parts = strings.Split(strings.TrimSpace(input), " ")
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		listA = append(listA, num)
	}

	input, _ = reader.ReadString('\n')
	listB := []int{}
	parts = strings.Split(strings.TrimSpace(input), " ")
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		listB = append(listB, num)
	}

	for k := 0; k < n; k++ {
		if contains(listA, k+1) {
			fmt.Print(1, " ")
		} else {
			fmt.Print(2, " ")
		}
	}
	fmt.Println()
}

func contains(slice []int, item int) bool {
	for _, value := range slice {
		if value == item {
			return true
		}
	}
	return false
}
