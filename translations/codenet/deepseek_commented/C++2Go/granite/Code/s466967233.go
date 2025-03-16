
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
	a := make([]int64, n+1)
	for i := int64(1); i <= n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}
	b := make([]int64, n+1)
	for i := int64(1); i <= n; i++ {
		b[i] = -1
	}
	now := int64(1)
	cnt := int64(0)
	b[1] = 0
	for j := int64(1); j <= k; j++ {
		now = a[now]
		if b[now] == -1 {
			b[now] = j
		} else {
			cnt = j
			break
		}
	}
	if j < k {
		tmp := (k - b[now]) % (cnt - b[now])
		for j = 0; j < tmp; j++ {
			now = a[now]
		}
	}
	fmt.Println(now)
}

