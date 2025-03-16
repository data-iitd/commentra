
package main

import (
	"bufio"
	"fmt"
	"os"
)

const N = 1e5 + 10

var (
	n, m, q int
	a, b, id [N]int
	vis, cnt [N]bool
	in        = bufio.NewReader(os.Stdin)
	out       = bufio.NewWriter(os.Stdout)
)

func main() {
	fmt.Fscanf(in, "%d%d\n", &n, &m)
	fmt.Fscanf(in, "%d\n", &q)
	for i := 1; i <= q; i++ {
		fmt.Fscanf(in, "%d", &a[i])
	}
	for j, k := q, m; j > 0; j-- {
		if!vis[a[j]] {
			b[k] = a[j]
			vis[a[j]] = true
			k--
		}
	}
	for j, k := m, 1; k <= m; k++ {
		if!vis[k] {
			b[j] = k
			j--
		}
	}
	for i := 1; i <= m; i++ {
		id[b[i]] = i
	}

	flag := true
	cnt[0] = n
	for i := q; i > 0; i-- {
		t := id[a[i]]
		if cnt[t-1] > 0 {
			cnt[t-1]--
			cnt[t]++
			vis[t] = true
		} else if!vis[t] {
			flag = false
			break
		}
	}

	l := 0
	for ; cnt[l] == 0; l++ {
	}
	for i := l + 1; i < m; i++ {
		flag = flag && b[i] < b[i+1]
	}
	if flag {
		fmt.Fprintln(out, "Yes")
	} else {
		fmt.Fprintln(out, "No")
	}
	out.Flush()
}

