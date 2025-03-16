
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var a, b, c, k int64
	fmt.Fscanf(reader, "%d %d %d %d\n", &a, &b, &c, &k)
	if a+b >= k {
		fmt.Println(a)
	} else {
		fmt.Println(a - (k - (a + b)))
	}
}

