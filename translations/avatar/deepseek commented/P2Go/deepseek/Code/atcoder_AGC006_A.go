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

	s := make([]byte, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &s[i])
	}

	t := make([]byte, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &t[i])
	}

	if string(s) == string(t) {
		fmt.Fprintln(writer, n)
	} else {
		cnt := 0
		for i := 0; i < n; i++ {
			for j := 0; j < n-i; j++ {
				if s[i+j] != t[j] {
					break
				}
				if j == n-i-1 {
					cnt = n - i
				}
			}
		}
		fmt.Fprintln(writer, 2*n-cnt)
	}
}

