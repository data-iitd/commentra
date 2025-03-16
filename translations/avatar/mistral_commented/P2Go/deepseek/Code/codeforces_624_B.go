package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	input, _ = reader.ReadString('\n')
	parts := strings.Fields(input)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(parts[i])
	}

	pre := int(^uint(0) >> 1)
	ans := 0

	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})

	for j := 0; j < n; j++ {
		ans += max(0, min(pre-1, a[j]))
		pre = min(pre-1, a[j])
	}

	fmt.Println(ans)
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

