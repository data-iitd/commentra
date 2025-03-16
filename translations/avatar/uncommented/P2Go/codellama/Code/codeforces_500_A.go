package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	n, t := getInput()
	s := getSlice(n)
	currentCell := 0
	for currentCell <= t {
		currentCell += s[currentCell-1]
		if currentCell == t {
			fmt.Println("YES")
			os.Exit(0)
		}
	}
	fmt.Println("NO")
}

func getInput() (int, int) {
	var n, t int
	fmt.Scan(&n, &t)
	return n, t
}

func getSlice(n int) []int {
	var s []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		s = append(s, x)
	}
	return s
}

// 