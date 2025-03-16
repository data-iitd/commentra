
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var n, k int
	fmt.Fscanf(r, "%d\n%d\n", &n, &k)
	s := make([]byte, n)
	fmt.Fscanf(r, "%s\n", s)
	segCnt := 0
	for i := 0; i < n-1; i++ {
		if s[i]!= s[i+1] {
			segCnt++
		}
	}
	curHappy := n - 1 - segCnt
	if 2*k >= segCnt {
		fmt.Fprintf(w, "%d\n", n-1)
	} else {
		fmt.Fprintf(w, "%d\n", curHappy+2*k)
	}
	w.Flush()
}

