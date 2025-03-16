
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, k, x, y int
	fmt.Fscanf(reader, "%d %d %d %d\n", &n, &k, &x, &y)
	sum := 0
	for i := 1; i <= n; i++ {
		if i > k {
			sum += y
		} else {
			sum += x
		}
	}
	fmt.Println(sum)
}

