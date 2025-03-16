
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	rw  = bufio.NewReadWriter(bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout))
	N   int
	S   []string
	march = map[string]int{
		"M": 0,
		"A": 0,
		"R": 0,
		"C": 0,
		"H": 0,
	}
	ans int
)

func main() {
	fmt.Fscanf(rw, "%d\n", &N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(rw, "%s\n", &S[i])
		if _, ok := march[S[i][0:1]]; ok {
			march[S[i][0:1]]++
		}
	}
	for _, v := range march {
		ans += v
	}
	fmt.Fprintf(rw, "%d\n", ans)
	rw.Flush()
}

