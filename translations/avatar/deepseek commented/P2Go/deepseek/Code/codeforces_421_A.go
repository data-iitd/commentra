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
	line1, _ := reader.ReadString('\n')
	parts1 := strings.Split(strings.TrimSpace(line1), " ")
	n, _ := strconv.Atoi(parts1[0])
	a, _ := strconv.Atoi(parts1[1])
	b, _ := strconv.Atoi(parts1[2])

	line2, _ := reader.ReadString('\n')
	parts2 := strings.Split(strings.TrimSpace(line2), " ")
	listA := make([]int, len(parts2))
	for i, part := range parts2 {
		listA[i], _ = strconv.Atoi(part)
	}

	line3, _ := reader.ReadString('\n')
	parts3 := strings.Split(strings.TrimSpace(line3), " ")
	listB := make([]int, len(parts3))
	for i, part := range parts3 {
		listB[i], _ = strconv.Atoi(part)
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

func contains(list []int, item int) bool {
	for _, v := range list {
		if v == item {
			return true
		}
	}
	return false
}
