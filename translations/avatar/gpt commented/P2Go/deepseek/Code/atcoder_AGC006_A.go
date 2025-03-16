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

	s, _ := reader.ReadString('\n')
	t, _ := reader.ReadString('\n')

	s = s[:len(s)-1] // Remove the newline character
	t = t[:len(t)-1] // Remove the newline character

	if s == t {
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

