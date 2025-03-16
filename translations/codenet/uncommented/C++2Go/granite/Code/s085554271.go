
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	rw  = bufio.NewReadWriter(bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout))
	r   = bufio.NewReader(os.Stdin)
	w   = bufio.NewWriter(os.Stdout)
	rf  = bufio.NewReaderSize(os.Stdin, 1024*1024)
	wf  = bufio.NewWriterSize(os.Stdout, 1024*1024)
	s   = bufio.NewScanReader(rf)
	max = func(x, y int) int {
		if x > y {
			return x
		}
		return y
	}
	min = func(x, y int) int {
		if x < y {
			return x
		}
		return y
	}
)

func main() {
	//COMinit();
	IOS;
	prec;
	var (
		k, a, b int
	)
	for s.Scan() {
		fmt.Sscanf(s.Text(), "%d %d %d", &k, &a, &b)
		for i := a; i <= b; i++ {
			if i%k == 0 {
				fmt.Fprintln(w, "OK")
				w.Flush()
				return
			}
		}
		fmt.Fprintln(w, "NG")
		w.Flush()
	}
}

