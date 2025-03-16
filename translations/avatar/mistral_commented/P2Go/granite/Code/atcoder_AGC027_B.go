
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
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	var x int
	scanner.Scan()
	x, _ = strconv.Atoi(scanner.Text())
	a := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}
	s := make([]int, n)
	s[0] = a[0]
	for i := 1; i < n; i++ {
		s[i] = s[i-1] + a[i]
	}
	ans := 1<<63 - 1
	for k := 1; k <= n; k++ {
		e := int64(k) * int64(x)
		for i := 0; i < n-2*k; i++ {
			e += 2 * int64(s[i+k-1]-s[i])
		}
		if e < ans {
			ans = e
		}
	}
	fmt.Println(ans + int64(n)*int64(x) + 5*int64(s[n-1]))
}

