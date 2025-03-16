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
	n := readInt(reader)
	id := 0
	l, r := readPair(reader)
	for i := 1; i < n; i++ {
		li, ri := readPair(reader)
		if li <= l && r <= ri {
			id = i
		} else if li < l || r < ri {
			id = n
		}
		l = min(l, li)
		r = max(r, ri)
	}
	if id == n {
		fmt.Println(-1)
	} else {
		fmt.Println(id + 1)
	}
}

func readInt(reader *bufio.Reader) int {
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	num, _ := strconv.Atoi(line)
	return num
}

func readPair(reader *bufio.Reader) (int, int) {
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	li, _ := strconv.Atoi(parts[0])
	ri, _ := strconv.Atoi(parts[1])
	return li, ri
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
