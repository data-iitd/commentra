
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var n, k int
	var s string
	fmt.Fscanf(r, "%d\n%d\n%s\n", &n, &k, &s)

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

