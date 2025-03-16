
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
	fmt.Fscan(r, &s)
	if len(s) < 2 {
		fmt.Fprintln(w, "No")
	} else {
		hasA := false
		hasB := false
		for _, c := range s {
			if c == 'A' {
				hasA = true
			} else if c == 'B' {
				hasB = true
			}
		}
		if hasA && hasB {
			fmt.Fprintln(w, "Yes")
		} else {
			fmt.Fprintln(w, "No")
		}
	}
	w.Flush()
}

