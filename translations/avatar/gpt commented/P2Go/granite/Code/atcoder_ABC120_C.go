
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	s := readString(reader)

	if len(s) == 1 {
		fmt.Println(0)
		return
	}

	cnt := make(map[byte]int)

	for i := 0; i < len(s); i++ {
		cnt[s[i]]++
	}

	var res int

	for _, v := range cnt {
		res = max(res, v)
	}

	res *= 2

	fmt.Println(res)
}

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

// Translate the above Go code to Rust and end with comment "