
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n int64
	scanner.Scan()
	n, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	min := digit(n)
	for i := 1; int64(i)*i <= n; i++ {
		if n%i!= 0 {
			continue
		}
		a := int64(i)
		b := n / i
		min = int(Min(int64(min), Max(digit(a), digit(b))))
	}
	fmt.Println(min)
}

func digit(n int64) int {
	res := 0
	for n > 0 {
		res++
		n /= 10
	}
	return res
}

func Max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func Min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

