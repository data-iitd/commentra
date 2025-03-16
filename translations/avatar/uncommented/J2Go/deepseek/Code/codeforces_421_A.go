package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var n, a, b int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	a, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	b, _ = strconv.Atoi(scanner.Text())

	list1 := make([]int, a)
	list2 := make([]int, b)

	for i := 0; i < a; i++ {
		scanner.Scan()
		list1[i], _ = strconv.Atoi(scanner.Text())
	}
	for i := 0; i < b; i++ {
		scanner.Scan()
		list2[i], _ = strconv.Atoi(scanner.Text())
	}

	for i := 1; i <= n; i++ {
		if contains(list1, i) {
			fmt.Print(1, " ")
		} else {
			fmt.Print(2, " ")
		}
	}
}

func contains(slice []int, item int) bool {
	for _, value := range slice {
		if value == item {
			return true
		}
	}
	return false
}

