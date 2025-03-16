package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	var n, m int
	fmt.Sscanf(line, "%d %d", &n, &m)

	b := make([]int, n*2)
	for i := 0; i < len(b); i++ {
		b[i] = 1
	}

	b[0] = b[n-1] = b[n] = b[2*n-1] = 0

	for i := 0; i < m; i++ {
		line, _ := reader.ReadString('\n')
		var r, c int
		fmt.Sscanf(line, "%d %d", &r, &c)
		b[r-1] = 0
		b[n+c-1] = 0
	}

	if n%2 == 1 && b[n/2] == 1 && b[n+n/2] == 1 {
		b[n/2] = 0
	}

	sum := 0
	for i := 0; i < len(b); i++ {
		sum += b[i]
	}

	fmt.Println(sum)
}

