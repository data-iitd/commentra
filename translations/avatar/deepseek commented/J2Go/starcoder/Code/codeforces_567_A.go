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
	fmt.Println("Enter the size of the array: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	n, _ := strconv.Atoi(input)
	ar := make([]int, n)
	fmt.Println("Enter the elements of the array: ")
	for i := 0; i < n; i++ {
		input, _ := reader.ReadString('\n')
		input = strings.Replace(input, "\n", "", -1)
		ar[i], _ = strconv.Atoi(input)
	}
	max, min := 0, 0
	for i := 0; i < n; i++ {
		max = max(max, ar[i]-ar[0])
		if i == 0 {
			min = ar[i+1] - ar[i]
		} else if i == n-1 {
			min = ar[i] - ar[i-1]
		} else {
			min = min(min, ar[i]-ar[i-1])
			min = min(min, ar[i+1]-ar[i])
		}
		fmt.Println(min, max)
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

