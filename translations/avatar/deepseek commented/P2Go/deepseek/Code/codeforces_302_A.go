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
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	input, _ = reader.ReadString('\n')
	sa := strings.Count(input, "-")
	sa = min(n - sa, sa)

	var ss []string

	for i := 0; i < m; i++ {
		input, _ = reader.ReadString('\n')
		parts := strings.Split(strings.TrimSpace(input), " ")
		a, _ := strconv.Atoi(parts[0])
		b, _ := strconv.Atoi(parts[1])
		b -= a
		if b%2 != 0 && b <= sa*2 {
			ss = append(ss, "1\n")
		} else {
			ss = append(ss, "0\n")
		}
	}

	fmt.Print(strings.Join(ss, ""))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

