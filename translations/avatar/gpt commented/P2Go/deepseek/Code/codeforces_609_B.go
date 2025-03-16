package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readInput() []int {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	parts := strings.Fields(input)
	intParts := make([]int, len(parts))
	for i, part := range parts {
		intPart, _ := strconv.Atoi(part)
		intParts[i] = intPart
	}
	return intParts
}

func main() {
	parts := readInput()
	n := parts[0]
	m := parts[1]

	lst := readInput()

	l := make(map[int]int)

	for i := 0; i < n; i++ {
		if _, exists := l[lst[i]]; !exists {
			l[lst[i]] = 1
		} else {
			l[lst[i]] += 1
		}
	}

	res := 0

	for i := 0; i < n; i++ {
		if l[lst[i]] > 1 {
			res += n - i - l[lst[i]]
			l[lst[i]] -= 1
		} else {
			res += n - i - 1
		}
	}

	fmt.Println(res)
}

