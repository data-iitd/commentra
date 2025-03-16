package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)
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
	fmt.Println(cnt)
}

