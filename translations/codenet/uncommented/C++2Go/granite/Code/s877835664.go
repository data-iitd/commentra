
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

	cur := int64(1)
	dic := make([]int64, n+1)
	flg := false
	for i := int64(1); i <= k; i++ {
		if dic[cur] < 0 || flg {
			dic[cur] = i
			cur = a[cur]
		} else if!flg {
			tmp := k - (dic[cur] - 1)
			tmp %= i - dic[cur]
			i = k - tmp
			flg = true
		}
	}

	fmt.Println(cur)
}

