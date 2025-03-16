
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	readWriter = bufio.NewReadWriter(bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout))
	reader      = bufio.NewReader(os.Stdin)
	writer      = bufio.NewWriter(os.Stdout)
)

func main() {
	var n, k int64
	fmt.Fscanf(reader, "%d %d\n", &n, &k)
	s := make([]byte, n)
	fmt.Fscanf(reader, "%s\n", s)
	L := s[0]
	cnt := int64(0)
	for i := int64(1); i < n; i++ {
		if L == s[i] {
			cnt++
		} else {
			L = s[i]
			ans += cnt
			ans2++
			cnt = 0
		}
	}
	ans += cnt
	ans2++
	fmt.Fprintf(writer, "%d\n", ans+min(2*k, ans2-1))
	writer.Flush()
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

