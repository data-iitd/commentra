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
	line, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(line), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	out := make([]int, n)
	comp := make([]int, n)
	for i := 0; i < n; i++ {
		comp[i] = i + 2
	}

	for i := 0; i < m; i++ {
		line, _ := reader.ReadString('\n')
		parts := strings.Split(strings.TrimSpace(line), " ")
		l, _ := strconv.Atoi(parts[0])
		r, _ := strconv.Atoi(parts[1])
		x, _ := strconv.Atoi(parts[2])

		t := l
		for t <= r {
			nextVal := comp[t-1]
			if out[t-1] == 0 && t != x {
				out[t-1] = x
			}
			comp[t-1] = r + 1
			if t >= x {
				comp[t-1] = x
			}
			t = nextVal
		}
	}

	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(out[i])
	}
	fmt.Println()
}

