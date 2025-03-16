
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	H, _ := reader.ReadString('\n')
	W, _ := reader.ReadString('\n')
	H = H[:len(H)-1]
	W = W[:len(W)-1]

	var ans int64
	if H == "1" || W == "1" {
		ans = 1
	} else {
		m, _ := strconv.ParseInt(H, 10, 64) * strconv.ParseInt(W, 10, 64)
		if m%2 == 0 {
			ans = m / 2
		} else {
			ans = m/2 + 1
		}
	}
	fmt.Println(ans)
}
