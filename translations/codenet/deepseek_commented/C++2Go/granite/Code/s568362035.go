
package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAXN = 100000
)

var (
	n, m, Q int
	a        [MAXN + 1]int
	b        [MAXN + 1]int
	id       [MAXN + 1]int
	vis      [MAXN + 1]bool
	cnt      [MAXN + 1]int
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d%d\n", &n, &m)
	fmt.Fscanf(reader, "%d\n", &Q)
	for i := 1; i <= Q; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}
	k, j := 0, Q
	for j > 0 {
		if!vis[a[j]] {
			b[k+1] = a[j]
			vis[a[j]] = true
			k++
		}
		j--
	}
	for j = m, i = m; i > 0; i-- {
		if!vis[i] {
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
		} else if!vis[t] {
			flag = false
			break
		}
	}
	l := 0
	for cnt[l] == 0 {
		l++
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

