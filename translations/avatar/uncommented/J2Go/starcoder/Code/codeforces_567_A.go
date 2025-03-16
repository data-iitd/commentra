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
	fmt.Println("Enter the number of elements in the array")
	a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	ar := make([]int, a)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < a; i++ {
		ar[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	max := 0
	min := 0
	for i := 0; i < a; i++ {
		max = max(max, ar[i]-ar[0])
		if i == 0 {
			min = ar[i+1] - ar[i]
		} else if i == a-1 {
			min = ar[i] - ar[i-1]
		} else {
			min = min(min, ar[i]-ar[i-1])
			min = min(min, ar[i+1]-ar[i])
		}
		fmt.Println(min, " ", max)
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

