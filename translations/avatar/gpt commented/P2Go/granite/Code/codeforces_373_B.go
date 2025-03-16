
package main

import (
	"bufio"
	"fmt"
	"os"
)

func sum(k int) int {
	ret := 0
	pw := 10
	length := 1
	for {
		cur := min(pw-1, k)
		prev := pw / 10
		ret += (cur - prev + 1) * length
		if pw-1 >= k {
			break
		}
		length++
		pw *= 10
	}
	return ret
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var w, m, k int
	scanner.Scan()
	w = atoi(scanner.Text())
	scanner.Scan()
	m = atoi(scanner.Text())
	scanner.Scan()
	k = atoi(scanner.Text())
	lo, hi := 0, int(1e18)
	for hi-lo > 1 {
		md := (lo + hi) / 2
		c := sum(m+md-1) - sum(m-1)
		if c*k <= w {
			lo = md
		} else {
			hi = md
		}
	}
	fmt.Println(lo)
}

func atoi(s string) int {
	result := 0
	for _, c := range s {
		result = result*10 + int(c-'0')
	}
	return result
}

