
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
	if len(s) >= 2 && (s[0] == 'A' || s[len(s)-1] == 'B') {
		fmt.Fprintln(w, "Yes")
	} else {
		fmt.Fprintln(w, "No")
	}
	w.Flush()
}

