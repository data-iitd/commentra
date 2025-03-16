

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n, m int
	fmt.Fscanf(reader, "%d %d\n", &n, &m)

	x := make([]int, 31)

	for i := 0; i < n; i++ {
		var k int
		fmt.Fscanf(reader, "%d\n", &k)

		for j := 0; j < k; j++ {
			var a int
			fmt.Fscanf(reader, "%d", &a)
			x[a]++
		}
	}

	ans := 0

	for i := 1; i <= m; i++ {
		if x[i] == n {
			ans++
		}
	}

	fmt.Println(ans)
}

