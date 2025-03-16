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
	x, _ := strconv.Atoi(parts[1])

	scanner.Scan()
	a := []int{}
	for _, num := range strings.Split(scanner.Text(), " ") {
		numInt, _ := strconv.Atoi(num)
		a = append(a, numInt)
	}

	b := make([][]int, n)
	for i := range b {
		b[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		m := a[i]
		for j := 0; j < n; j++ {
			k := i - j
			if k < 0 {
				k += n
			}
			m = min(m, a[k])
			b[j][i] = m
		}
	}

	m := 1000000000000000
	for i, j := range b {
		sumRow := 0
		for _, v := range j {
			sumRow += v
		}
		sumRow += x * i
		m = min(m, sumRow)
	}

	fmt.Println(m)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
