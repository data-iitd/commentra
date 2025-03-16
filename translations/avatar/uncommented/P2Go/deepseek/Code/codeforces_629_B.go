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
	N := 368
	m := make([]int, N)
	f := make([]int, N)

	count, _ := strconv.Atoi(readLine(reader))
	for i := 0; i < count; i++ {
		input := readLine(reader)
		parts := strings.Split(input[:len(input)-1], " ")
		a, _ := strconv.Atoi(parts[1])
		b, _ := strconv.Atoi(parts[2])
		b++
		if parts[0] == "M" {
			m[a] += 2
			m[b] -= 2
		} else {
			f[a] += 2
			f[b] -= 2
		}
	}

	var a, b, c int
	for i := 0; i < N; i++ {
		a += m[i]
		b += f[i]
		if min(a, b) > c {
			c = min(a, b)
		}
	}
	fmt.Println(c)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
