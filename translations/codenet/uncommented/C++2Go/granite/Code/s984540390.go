
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	h, _ := strconv.Atoi(reader.ReadLine())
	ans, mx, sum, mn, cnt := 0, 0, 0, 1e8, 1
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

