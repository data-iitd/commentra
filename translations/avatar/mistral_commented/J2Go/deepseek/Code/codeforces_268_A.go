package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	result := 0

	h := make([]int, n)
	g := make([]int, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		h[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		g[i], _ = strconv.Atoi(scanner.Text())
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if h[i] == g[j] {
				result++
			}
		}
	}

	fmt.Println(result)
}

