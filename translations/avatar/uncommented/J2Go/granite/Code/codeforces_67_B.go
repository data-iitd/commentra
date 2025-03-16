
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	const MOD = 1e9 + 7
	const IINF = int(1e18)
	const INF = 1e9
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, k int
	fmt.Fscanf(reader, "%d%d\n", &n, &k)
	bb := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &bb[i])
	}
	aa := make([]int, n)
	m := 0
	for a := n - 1; a >= 0; a-- {
		j := 0
		for bb[a] > 0 {
			if aa[j] >= a+k {
				bb[a]--
			}
			j++
		}
		for j_ := m; j_ > j; j_-- {
			aa[j_] = aa[j_-1]
		}
		aa[j] = a
		m++
	}
	for i := 0; i < n; i++ {
		fmt.Fprintf(writer, "%d ", aa[i]+1)
	}
	fmt.Fprint(writer, "\n")
}

