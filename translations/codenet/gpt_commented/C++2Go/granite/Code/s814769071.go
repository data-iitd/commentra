
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n, k int64
	fmt.Fscanf(reader, "%d %d\n", &n, &k)

	MOD := int64(1e9 + 7)

	mx := n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2
	mn := k * (k - 1) / 2

	res := int64(0)
	for i := k; i <= n+1; i++ {
		res += mx - mn + 1
		mx += n - i
		mn += i
		res %= MOD
	}

	fmt.Println(res)
}

