package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	a := parseInts(readLine(reader))
	sort.Slice(a, func(i, j int) bool { return a[i] > a[j] })
	pre := int(^uint(0) >> 1)
	ans := 0
	for j := 0; j < n; j++ {
		ans += max(0, min(pre-1, a[j]))
		pre = max(0, min(pre-1, a[j]))
	}
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1]
}

func parseInts(line string) []int {
	strs := strings.Split(line, " ")
	ints := make([]int, len(strs))
	for i, str := range strs {
		val, _ := strconv.Atoi(str)
		ints[i] = val
	}
	return ints
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
