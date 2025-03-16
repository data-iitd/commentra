package main

import (
	"fmt"
)

const MAXN = 1e5 + 10

var (
	n, m, Q int
	a       [MAXN]int
	b       [MAXN]int
	id      [MAXN]int
	vis     [MAXN]bool
	cnt     [MAXN]int
)

func main() {
	fmt.Scan(&n, &m)
	fmt.Scan(&Q)
	for i := 1; i <= Q; i++ {
		fmt.Scan(&a[i])
	}

	k := 0
	for j := Q; j > 0; j-- {
		if !vis[a[j]] {
			k++
			b[k] = a[j]
			vis[a[j]] = true
		}
	}

	for j := m; j > 0; i-- {
		if !vis[i] {
			b[j] = i
			j--
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
		} else if !vis[t] {
			flag = false
			break
		}
	}

	l := 0
	for cnt[l] == 0 {
		l++
	}
	for i := l + 1; i < m; i++ {
		flag = flag && (b[i] < b[i+1])
	}

	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
