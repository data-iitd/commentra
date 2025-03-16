
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	// 入力
	var n, k int
	fmt.Fscanf(r, "%d %d\n", &n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(r, "%d", &a[i])
	}

	// 解法
	ans1 := int64(0)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i >= j {
				continue
			}
			if a[i] > a[j] {
				ans1++
			}
			ans1 %= 100000007
		}
	}

	count := make([]int, 2005)
	for i := 0; i < n; i++ {
		count[a[i]-1]++
	}
	ans2 := int64(0)
	remain := int64(n)
	for i := 0; i < 2005; i++ {
		remain -= int64(count[i])
		ans2 += int64(count[i]) * remain
	}

	// cout << ans1 << endl;
	// cout << ans2 << endl;
	k %= 100000007
	tmp := int64(k) * (k - 1) / 2
	tmp %= 100000007
	tmp *= ans2
	tmp %= 100000007
	ans := ans1 * int64(k)
	ans %= 100000007
	ans += tmp
	ans %= 100000007

	// 出力
	fmt.Fprintf(w, "%d\n", ans)
	w.Flush()
}

