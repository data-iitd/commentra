
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var tc, n, m int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d%d\n", &tc, &n, &m)
	if n > m {
		n, m = m, n
	}
	for i := 1; i <= m; i++ {
		if i*tc >= n && i*tc <= m {
			fmt.Println("OK")
			return
		}
	}
	fmt.Println("NG")
}

