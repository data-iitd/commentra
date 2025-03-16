package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, t int
	var st [7]bool
	for {
		if _, err := fmt.Scanf("%d", &n); err!= nil {
			break
		}
		for i := 0; i < n; i++ {
			fmt.Scanf("%d", &t)
			ans := make([]byte, 8)
			for j := 0; j < 7; j++ {
				ans[j] = byte(st[j] ^ seg[t][j])
				st[j] = seg[t][j]
			}
			fmt.Println(string(ans))
		}
	}
}

const (
	N = 7
	M = 1 << N
)

var seg [M][N]bool

func init() {
	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			seg[i][j] = (i>>j)&1 == 1
		}
	}
}

