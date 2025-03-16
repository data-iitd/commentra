package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n string
	fmt.Scan(&n)

	a := []string{"10", "100", "1000", "10000", "100000"}

	var new int
	for _, digit := range n {
		num, _ := strconv.Atoi(string(digit))
		new += num
	}

	if contains(a, n) {
		fmt.Println(10)
	} else {
		fmt.Println(new)
	}
}

func contains(slice []string, item string) bool {
	for _, value := range slice {
		if value == item {
			return true
		}
	}
	return false
}

