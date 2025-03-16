package main

import (
	"bufio"
	"fmt"
	"os"
)

func in() int {
	reader := bufio.NewReader(os.Stdin)
	var n int
	var c byte
	for {
		c, _ = reader.ReadByte()
		if c >= '0' {
			n = int(c - '0')
			break
		}
	}
	for {
		c, _ = reader.ReadByte()
		if c < '0' {
			break
		}
		n = n*10 + int(c-'0')
	}
	return n
}

func main() {
	var i, N, ans int
	f1 := make([]int, 100)
	f2 := make([]int, 100)

	N = in()
	for N > 0 {
		calc(N, f1, f2)
		N--
	}

	ans = 0
	for i = 0; i < 100; i++ {
		ans += f1[i] * f2[i]
	}
	fmt.Println(ans)
}

func calc(n int, f1, f2 []int) {
	k := n % 10
	for n >= 10 {
		n /= 10
	}
	f1[10*k+n]++
	f2[n*10+k]++
}

