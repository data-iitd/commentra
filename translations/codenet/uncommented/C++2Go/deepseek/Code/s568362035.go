package main

import (
	"bufio"
	"fmt"
	"os"
)

const MAXN = 1e5 + 10

var (
	n, m, Q   int
	a         [MAXN]int
	b         [MAXN]int
	id        [MAXN]int
	vis       [MAXN]bool
	cnt       [MAXN]int
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &m)
	fmt.Fscan(reader, &Q)
	for i := 1; i <= Q; i++ {
		fmt.Fscan(reader, &a[i])
	}
	k := 0
	for j := Q; j > 0; j-- {
		if !vis[a[j]] {
			k++
			b[k] = a[j]
			vis[a[j]] = true
		}
	}
	j := m
	for i := m; i > 0; i-- {
		if !vis[i] {
			j--
			b[j] = i
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
		if b[i] >= b[i+1] {
			flag = false
			break
		}
	}
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

