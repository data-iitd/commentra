
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
	var a, b int
	fmt.Fscanf(r, "%d %d\n", &a, &b)

	if a > 0 {
		fmt.Fprintln(w, "Positive")
	} else if a <= 0 && b >= 0 {
		fmt.Fprintln(w, "Zero")
	} else {
		if (a+b)%2 == 0 {
			fmt.Fprintln(w, "Negative")
		} else {
			fmt.Fprintln(w, "Positive")
		}
	}

	w.Flush()
}

