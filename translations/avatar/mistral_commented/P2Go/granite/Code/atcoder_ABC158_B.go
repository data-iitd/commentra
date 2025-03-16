
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

func I() int {
	c, _ := r.ReadBytes('\n')
	x := 0
	for _, b := range c {
		x = x*10 + int(b-'0')
	}
	return x
}

func main() {
	const mod = 1e9 + 7
	N, A, B := I(), I(), I()
	ans := N / (A + B) * A
	res := N % (A + B)
	if res > A {
		res = A
	}
	ans += res
	fmt.Fprintln(w, ans)
	w.Flush()
}

