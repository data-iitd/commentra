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

	var n, m int
	fmt.Fscan(reader, &n, &m)

	x := make([]int, 31)
	for i := 0; i < n; i++ {
		var k, a int
		fmt.Fscan(reader, &k)
		for j := 0; j < k; j++ {
			fmt.Fscan(reader, &a)
			x[a]++
		}
	}

	ans := 0
	for i := 1; i <= m; i++ {
		if x[i] == n {
			ans++
		}
	}

	fmt.Fprintln(writer, ans)
}

