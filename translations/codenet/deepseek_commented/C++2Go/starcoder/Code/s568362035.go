<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const MAXN = 1e5 + 10

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &m)
	fmt.Fscan(reader, &Q)
	a := make([]int, Q + 1)
	for i := 1; i <= Q; i++ {
		fmt.Fscan(reader, &a[i])
	}
	b := make([]int, m + 1)
	id := make([]int, m + 1)
	vis := make([]bool, m + 1)
	cnt := make([]int, m + 1)
	for k, j := 0, Q; j > 0; j-- {
		if!vis[a[j]] {
			b[k+1] = a[j]
			vis[a[j]] = true
			k++
		}
	}
	for j, i := m, m; i > 0; i-- {
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
	for l = 0; cnt[l] == 0; l++ {
	}
	for i := l + 1; i < m; i++ {
		flag &= b[i] < b[i+1]
	}
	fmt.Println(flag)
}

