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
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	req := make([]int, n)
	pre := make([]int, m)

	for i := 0; i < n; i++ {
		scanner.Scan()
		req[i], _ = strconv.Atoi(scanner.Text())
	}
	for i := 0; i < m; i++ {
		scanner.Scan()
		pre[i], _ = strconv.Atoi(scanner.Text())
	}

	i := n - 1
	j := m - 1
	ans := 0

	for i >= 0 && j >= 0 {
		if req[i] > pre[j] {
			ans++
		} else {
			j--
		}
		i--
	}

	fmt.Println(ans + i + 1)
}

