package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	var s string
	fmt.Fscan(reader, &s)

	cnt := 0

	for i := 0; i < n; i++ {
		cnt++
		j := i + 1

		for ; j < n; j++ {
			if s[i] != s[j] {
				break
			}
		}
		i = j - 1
	}

	fmt.Fprintln(writer, cnt)
}

