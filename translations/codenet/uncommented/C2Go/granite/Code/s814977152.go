
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	const N = 114514
	var n int
	if _, err := fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n); err!= nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		if _, err := fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &a[i]); err!= nil {
			panic(err)
		}
	}
	b := make([]int, n)
	copy(b, a)
	sort.Ints(b)
	m := 0
	for _, v := range b {
		if m == 0 || v!= b[m-1] {
			b[m] = v
			m++
		}
	}
	c := make([]int, m)
	for i := 0; i < n; i++ {
		j := sort.SearchInts(b, a[i])
		c[j]++
	}
	r := 0
	for _, v := range c {
		if v%2 == 1 {
			r++
		}
	}
	fmt.Fprintln(os.Stdout, r)
}

