
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N, M, Q int
	var a, b, c, d []int
	var res int

	reader := bufio.NewReader(os.Stdin)
	N, _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	M, _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	Q, _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	a = make([]int, Q)
	b = make([]int, Q)
	c = make([]int, Q)
	d = make([]int, Q)
	for i := 0; i < Q; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		b[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		c[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		d[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	res = 0
	rec(a, b, c, d, res, 0, 0, N, M)
	fmt.Println(res)
}

func rec(a, b, c, d []int, res, i, last_max, N, M int) {
	if i == N {
		ans := 0
		for j := 0; j < len(a); j++ {
			if a[j] <= i && b[j] > i && c[j] == d[j] {
				ans += d[j]
			}
		}
		res = max(res, ans)
		return
	}
	if i == 0 {
		last_max = 1
	}
	for j := last_max; j <= M; j++ {
		rec(a, b, c, d, res, i+1, j, N, M)
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

