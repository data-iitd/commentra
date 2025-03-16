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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n, &m)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &Q)

	for i := 1; i <= Q; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i])
	}

	k := 0
	for j := Q; j > 0; j-- {
		if !vis[a[j]] {
			b[k+1] = a[j]
			vis[a[j]] = true
			k++
		}
	}

	for i := m; i > 0; i-- {
		if !vis[i] {
			b[m-i+1] = i
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

