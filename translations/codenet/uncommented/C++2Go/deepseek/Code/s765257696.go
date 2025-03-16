package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	p := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &p[i])
	}

	ans := 0
	for i := 0; i < n-2; i++ {
		if p[i] > p[i+1] && p[i+1] > p[i+2] {
			ans++
		}
		if p[i] < p[i+1] && p[i+1] < p[i+2] {
			ans++
		}
	}

	fmt.Fprintln(writer, ans)
}

