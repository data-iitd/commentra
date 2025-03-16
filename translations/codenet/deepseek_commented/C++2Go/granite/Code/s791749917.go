
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
	H_int, _ := strconv.Atoi(H)
	W_int, _ := strconv.Atoi(W)
	var ans int64
	if H_int == 1 || W_int == 1 {
		ans = 1
	} else {
		m := int64(H_int) * int64(W_int)
		if m%2 == 0 {
			ans = m / 2
		} else {
			ans = m/2 + 1
		}
	}
	fmt.Println(ans)
}

