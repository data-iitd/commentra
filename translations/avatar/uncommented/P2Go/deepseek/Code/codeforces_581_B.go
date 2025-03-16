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
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	arrInput, _ := reader.ReadString('\n')
	arrStr := strings.Split(strings.TrimSpace(arrInput), " ")
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(arrStr[i])
	}

	ans := make([]int, n)
	mx := arr[n-1]
	for i := n - 2; i >= 0; i-- {
		ans[i] = max(0, mx-arr[i]+1)
		if arr[i] > mx {
			mx = arr[i]
		}
	}

	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(ans[i])
	}
	fmt.Println()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

