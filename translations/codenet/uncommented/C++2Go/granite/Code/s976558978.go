
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	fin := bufio.NewReader(os.Stdin)
	fout := bufio.NewWriter(os.Stdout)
	defer fout.Flush()

	var a, b int
	fmt.Fscanf(fin, "%d %d\n", &a, &b)

	if a < b {
		for i := 0; i < b; i++ {
			fmt.Fprintf(fout, "%d ", a)
		}
		fmt.Fprintln(fout)
	} else {
		for i := 0; i < a; i++ {
			fmt.Fprintf(fout, "%d ", b)
		}
		fmt.Fprintln(fout)
	}
}

