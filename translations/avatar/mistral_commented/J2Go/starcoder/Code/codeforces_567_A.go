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
	fmt.Println("Enter the size of the array")
	size, _ := strconv.Atoi(reader.ReadString('\n'))
	arr := make([]int, size)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < size; i++ {
		arr[i], _ = strconv.Atoi(reader.ReadString('\n'))
	}
	max, min := 0, 0
	for i := 0; i < size; i++ {
		if i == 0 {
			max = arr[i+1] - arr[i]
			min = arr[i] - arr[i]
		} else if i == size-1 {
			max = arr[i] - arr[i-1]
			min = arr[i] - arr[i-1]
		} else {
			max = max(arr[i] - arr[i-1], arr[i+1] - arr[i])
			min = min(arr[i] - arr[i-1], arr[i+1] - arr[i])
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

