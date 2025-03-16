package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func count(total int, i int, s string) int {
	if s[i-1:i+1] == "AC" {
		return total + 1
	}
	return total
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	line, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(line), " ")
	n, _ := strconv.Atoi(parts[0])
	q, _ := strconv.Atoi(parts[1])

	line, _ = reader.ReadString('\n')
	s := strings.TrimSpace(line)

	problems := make([][]int, q)
	for i := 0; i < q; i++ {
		line, _ = reader.ReadString('\n')
		parts := strings.Split(strings.TrimSpace(line), " ")
		l, _ := strconv.Atoi(parts[0])
		r, _ := strconv.Atoi(parts[1])
		problems[i] = []int{l, r}
	}

	cumsum := make([]int, n+1)
	for i := 1; i <= n; i++ {
		cumsum[i] = count(cumsum[i-1], i-1, s)
	}

	for _, pair := range problems {
		l, r := pair[0], pair[1]
		fmt.Fprintln(writer, cumsum[r-1]-cumsum[l-1])
	}
}

