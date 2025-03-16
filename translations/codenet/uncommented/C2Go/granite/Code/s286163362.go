
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	bufr = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	const N = 111111
	const M = 2222222
	var n, k int
	var data [N]int
	var seq [M]int
	for {
		fmt.Fscanf(bufr, "%d%d", &n, &k)
		if n == 0 && k == 0 {
			break
		}
		for i := 0; i < k; i++ {
			fmt.Fscanf(bufr, "%d", &n)
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
		fmt.Fprintf(w, "%d\n", ret)
	}
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

