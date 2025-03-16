
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, k, cnt int
	fmt.Fscanf(reader, "%d %d\n", &n, &k)
	for i := 0; i < n; i++ {
		var h int
		fmt.Fscanf(reader, "%d\n", &h)
		if h >= k {
			cnt++
		}
	}
	fmt.Println(cnt)
}

