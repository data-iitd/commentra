
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int64
	var a int64
	var m int64 = 100000000
	var M int64 = -100000000
	var c int64 = 0
	var i int64

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &n)

	for i = 1; i <= n; i++ {
		fmt.Fscanf(reader, "%d\n", &a)

		if a > M {
			M = a
		}

		if a < m {
			m = a
		}

		c = c + a
	}

	fmt.Printf("%d %d %d\n", m, M, c)
}

