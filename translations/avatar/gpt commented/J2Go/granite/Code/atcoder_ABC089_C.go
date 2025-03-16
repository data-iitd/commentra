
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	fmt.Fscanf(in, "%d\n", &n)
	cnt := make([]int64, 5)
	for i := 0; i < n; i++ {
		var s string
		fmt.Fscanf(in, "%s\n", &s)
		switch s[0] {
		case 'M':
			cnt[0]++
		case 'A':
			cnt[1]++
		case 'R':
			cnt[2]++
		case 'C':
			cnt[3]++
		case 'H':
			cnt[4]++
		}
	}
	res := cnt[0]*cnt[1]*cnt[2] +
		cnt[0]*cnt[1]*cnt[3] +
		cnt[0]*cnt[1]*cnt[4] +
		cnt[0]*cnt[2]*cnt[3] +
		cnt[0]*cnt[2]*cnt[4] +
		cnt[0]*cnt[3]*cnt[4] +
		cnt[1]*cnt[2]*cnt[3] +
		cnt[1]*cnt[2]*cnt[4] +
		cnt[1]*cnt[3]*cnt[4] +
		cnt[2]*cnt[3]*cnt[4]
	fmt.Fprintf(out, "%d\n", res)
	out.Flush()
}

