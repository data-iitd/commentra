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
	line := scanner.Text()
	parts := strings.Split(line, " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	b := make([]int, n*2)
	for i := 0; i < n*2; i++ {
		b[i] = 1
	}

	b[0] = 0
	b[n-1] = 0
	b[n] = 0
	b[2*n-1] = 0

	for i := 0; i < m; i++ {
		scanner.Scan()
		line := scanner.Text()
		parts := strings.Split(line, " ")
		r, _ := strconv.Atoi(parts[0])
		c, _ := strconv.Atoi(parts[1])
		b[r-1] = 0
		b[n+c-1] = 0
	}

	if n%2 == 1 && b[n/2] == 1 && b[n+n/2] == 1 {
		b[n/2] = 0
	}

	sum := 0
	for _, v := range b {
		sum += v
	}

	fmt.Println(sum)
}

