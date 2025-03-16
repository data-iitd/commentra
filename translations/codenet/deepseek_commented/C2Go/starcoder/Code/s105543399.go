<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, a, m, M, c, b, i int64
	c = 0
	m = 100000000
	M = -100000000
	n, _ = strconv.ParseInt(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 10)))), 10, 64)
	for i = 1; i <= n; i++ {
		a, _ = strconv.ParseInt(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 10)))), 10, 64)
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

