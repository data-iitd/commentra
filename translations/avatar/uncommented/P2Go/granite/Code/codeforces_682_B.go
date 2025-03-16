
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	var l []int
	fmt.Fscanf(in, "%d\n", &n)
	for i := 0; i < n; i++ {
		var tmp int
		fmt.Fscanf(in, "%d", &tmp)
		l = append(l, tmp)
	}
	f := 1
	l = intSlice(l)
	sort(l)
	c := 0
	for i := 0; i < len(l); i++ {
		if l[i] > c {
			c++
		}
	}
	fmt.Fprintf(out, "%d\n", c+1)
	out.Flush()
}

func intSlice(a []int) []int {
	a = a[:len(a):len(a)]
	return a
}

func sort(a []int) {
	n := len(a)
	quickSort(a, 0, n-1)
}

func quickSort(a []int, lo, hi int) {
	if lo >= hi {
		return
	}
	p := partition(a, lo, hi)
	quickSort(a, lo, p-1)
	quickSort(a, p+1, hi)
}

func partition(a []int, lo, hi int) int {
	p := a[hi]
	i := lo - 1
	for j := lo; j < hi; j++ {
		if a[j] <= p {
			i++
			a[i], a[j] = a[j], a[i]
		}
	}
	a[i+1], a[hi] = a[hi], a[i+1]
	return i + 1
}

