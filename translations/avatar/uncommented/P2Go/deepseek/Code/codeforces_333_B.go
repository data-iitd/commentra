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

	b := make([]int, n*2)
	b[0] = b[n-1] = b[n] = b[2*n-1] = 0

	for i := 0; i < m; i++ {
		input, _ := reader.ReadString('\n')
		parts := strings.Split(strings.TrimSpace(input), " ")
		r, _ := strconv.Atoi(parts[0])
		c, _ := strconv.Atoi(parts[1])
		b[r-1] = 0
		b[n+c-1] = 0
	}

	if n%2 == 1 && b[n/2] == 1 && b[n+n/2] == 1 {
		b[n/2] = 0
	}

	sum := 0
	for _, value := range b {
		sum += value
	}

	fmt.Println(sum)
}
