package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n string
	var a = []string{"10", "100", "1000", "10000", "100000"}

	fmt.Scan(&n)

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

func contains(s []string, e string) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

