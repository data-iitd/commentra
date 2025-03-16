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

	ans := make([]int, n)
	for i := 0; i < n-1; i++ {
		var a int
		fmt.Fscan(reader, &a)
		a--
		ans[a]++
	}

	for i := 0; i < n; i++ {
		fmt.Fprintln(writer, ans[i])
	}
}

