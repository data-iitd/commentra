// ABC 152-D
// 2020.1.19 bal4u

package main

import (
	"fmt"
	"os"
)

func in() int {   // 非負整数の入力
	var n int
	for c := ' '; c >= '0'; c = int(os.Stdin.ReadByte()) {
		n = 10 * n + (c & 0xf)
	}
	return n
}

var f1 [100]int
var f2 [100]int

func calc(n int) {
	k := n % 10
	for n >= 10 {
		n /= 10
	}
	f1[10*k + n]++
	f2[n*10 + k]++
}

func main() {
	var i, N, ans int
	
	N = in()
	for N > 0 {
		calc(N)
		N--
	}

	ans = 0
	for i = 0; i < 100; i++ {
		ans += f1[i] * f2[i]
	}
	fmt.Println(ans)
}

