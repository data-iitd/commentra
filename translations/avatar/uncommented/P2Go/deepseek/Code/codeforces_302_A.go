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
	line1, _ := reader.ReadString('\n')
	line1 = strings.TrimSpace(line1)
	parts := strings.Split(line1, " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	line2, _ := reader.ReadString('\n')
	line2 = strings.TrimSpace(line2)
	sa := strings.Count(line2, "-")
	sa = min(n - sa, sa)

	var ss []string
	for i := 0; i < m; i++ {
		line3, _ := reader.ReadString('\n')
		line3 = strings.TrimSpace(line3)
		parts2 := strings.Split(line3, " ")
		a, _ := strconv.Atoi(parts2[0])
		b, _ := strconv.Atoi(parts2[1])
		b -= a
		if b%2 == 1 && b <= sa*2 {
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
