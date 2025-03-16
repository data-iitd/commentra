
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
	var s string
	var k int
	fmt.Fscanf(r, "%s\n", &s)
	fmt.Fscanf(r, "%d\n", &k)
	l := 0
	for ; l < len(s) && s[l] == '1'; l++ {
	}
	if l >= k {
		fmt.Fprintf(w, "1\n")
	} else {
		fmt.Fprintf(w, "%c\n", s[l])
	}
	w.Flush()
}

