

package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	const N = 111111
	const M = 2222222
	reader := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	var n, k int
	for {
		if _, err := fmt.Fscanf(reader, "%d%d\n", &n, &k); err!= nil {
			break
		}
		if n == 0 && k == 0 {
			break
		}
		data := make([]int, N)
		seq := make([]int, M)
		for i := 0; i < k; i++ {
			if _, err := fmt.Fscanf(reader, "%d\n", &n); err!= nil {
				break
			}
			data[n-1]++
		}
		p := 0
		for i := 0; i < N; i++ {
			if data[i] > 0 {
				seq[p]++
			} else {
				p += 2
			}
		}
		p++
		ret := 0
		if data[0] > 0 {
			for i := 0; i < p; i++ {
				ret = max(ret, seq[i]+seq[i+2]+1)
			}
		} else {
			for i := 0; i < p; i++ {
				ret = max(ret, seq[i])
			}
		}
		fmt.Fprintf(&buf, "%d\n", ret)
	}
	fmt.Print(buf.String())
}

// 