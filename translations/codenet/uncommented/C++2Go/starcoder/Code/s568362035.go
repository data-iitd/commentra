package main

import (
	"fmt"
	"os"
)

const MAXN = 1e5 + 10

func main() {
	var n, m, Q int
	fmt.Fscan(os.Stdin, &n, &m, &Q)
	a := make([]int, Q + 1)
	b := make([]int, m + 1)
	id := make([]int, m + 1)
	vis := make([]bool, m + 1)
	cnt := make([]int, m + 1)
	for i := 1; i <= Q; i++ {
		fmt.Fscan(os.Stdin, &a[i])
	}
	k := 0
	for j := Q; j > 0; j-- {
		if!vis[a[j]] {
			b[k+1] = a[j]
			vis[a[j]] = true
			k++
		}
	}
	for j := m; j > 0; j-- {
		if!vis[j] {
			b[j] = j
			vis[j] = true
		}
	}
	for i := 1; i <= m; i++ {
		id[b[i]] = i
	}

	flag := true
	cnt[0] = n
	for i := Q; i > 0; i-- {
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
	for l = 0; cnt[l] == 0; l++ {
	}
	for i := l + 1; i <= m; i++ {
		flag &= b[i] < b[i+1]
	}
	fmt.Println(flag)
}

