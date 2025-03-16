package main

import "fmt"

const MAXN = 100010

var n, m, Q int
var a [MAXN]int
var b [MAXN]int
var id [MAXN]int
var vis [MAXN]bool
var cnt [MAXN]int

func main() {
	fmt.Scanf("%d%d", &n, &m)
	fmt.Scanf("%d", &Q)
	for i := 1; i <= Q; i++ {
		fmt.Scanf("%d", &a[i])
	}
	for k, j := 0, Q; j > 0; j-- {
		if !vis[a[j]] {
			b[k+1] = a[j]
			vis[a[j]] = true
		}
	}
	for j, i := m, m; i > 0; i-- {
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

	for l := 0; cnt[l] == 0; l++ {
	}
	for i := l + 1; i < m; i++ {
		flag = flag && b[i] < b[i+1]
	}
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

