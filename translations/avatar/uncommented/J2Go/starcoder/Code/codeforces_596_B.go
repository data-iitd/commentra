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
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	arr := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	answer := 0
	for i := 0; i < n; i++ {
		answer += abs(arr[i] - arr[i-1])
	}
	fmt.Println(answer)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

