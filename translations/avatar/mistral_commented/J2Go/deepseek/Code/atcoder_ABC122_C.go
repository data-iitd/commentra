package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = 1000000007

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := toInt(scanner.Text())
	scanner.Scan()
	q := toInt(scanner.Text())

	scanner.Scan()
	c := scanner.Text()

	rangeQueries := make([][2]int, q)
	for i := 0; i < q; i++ {
		scanner.Scan()
		rangeQueries[i][0] = toInt(scanner.Text())
		scanner.Scan()
		rangeQueries[i][1] = toInt(scanner.Text())
	}

	frag := make([]int, n+1)
	rui := make([]int, n+1)

	for i := 2; i <= n; i++ {
		if c[i-2] == 'A' && c[i-1] == 'C' {
			frag[i]++
		}
		rui[i] = rui[i-1] + frag[i]
	}

	for i := 0; i < q; i++ {
		left := rangeQueries[i][0]
		right := rangeQueries[i][1]
		fmt.Println(rui[right] - rui[left])
	}
}

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

