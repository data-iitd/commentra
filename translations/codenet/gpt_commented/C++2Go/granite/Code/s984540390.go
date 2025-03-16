
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var h int64
	fmt.Fscanf(reader, "%d\n", &h)
	ans, mx, sum, mn, cnt := int64(0), int64(0), int64(0), int64(1e8), int64(1)
	for h!= 1 {
		if h%2!= 0 {
			h--
		}
		h /= 2
		cnt *= 2
		ans += cnt
	}
	fmt.Println(ans + 1)
}

