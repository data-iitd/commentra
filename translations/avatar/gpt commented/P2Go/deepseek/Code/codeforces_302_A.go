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
	parts := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	scanner.Scan()
	sa := strings.Count(scanner.Text(), "-")
	sa = min(n-sa, sa)

	var ss []string

	for i := 0; i < m; i++ {
		scanner.Scan()
		parts := strings.Split(scanner.Text(), " ")
		a, _ := strconv.Atoi(parts[0])
		b, _ := strconv.Atoi(parts[1])
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

