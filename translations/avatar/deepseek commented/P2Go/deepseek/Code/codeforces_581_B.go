package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	arrStr := scanner.Text()
	arr := []int{}
	for _, numStr := range strings.Split(arrStr, " ") {
		num, _ := strconv.Atoi(numStr)
		arr = append(arr, num)
	}
	arr = arr[:n]

	ans := make([]int, n)
	mx := arr[len(arr)-1]

	for i := n - 2; i >= 0; i-- {
		ans[i] = max(0, mx-arr[i]+1)
		if arr[i] > mx {
			mx = arr[i]
		}
	}

	for _, val := range ans {
		fmt.Print(val, " ")
	}
	fmt.Println()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

