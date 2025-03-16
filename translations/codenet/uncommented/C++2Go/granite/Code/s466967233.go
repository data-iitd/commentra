
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
	var n, k int
	fmt.Fscanf(r, "%d %d\n", &n, &k)
	a := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscanf(r, "%d", &a[i])
	}
	b := make([]int, n+1)
	for i := 1; i <= n; i++ {
		b[i] = -1
	}
	now := 1
	cnt := 0
	b[1] = 0
	for j := 1; j <= k; j++ {
		//fmt.Printf("%d -> %d\n", now, a[now])
		now = a[now]
		if b[now] == -1 {
			//fmt.Printf("未到達だった\n")
			b[now] = j
		} else {
			//fmt.Printf("到達済みだった\n")
			//fmt.Printf("B[%d] = %d\n", now, b[now])
			cnt = j
			//fmt.Printf("cnt = %d\n", cnt)
			break
		}
	}
	if j < k {
		tmp := (k - b[now]) % (cnt - b[now])
		//fmt.Printf("あと %d 回移動すればいい\n", tmp)
		//B[now] から tmp 回ワープしたところが終着点
		for i := 0; i < tmp; i++ {
			now = a[now]
		}
	}
	fmt.Fprintf(w, "%d\n", now)
	w.Flush()
}

