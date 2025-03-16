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
			break
		}
	}
	n = int(c - '0')
	for {
		c, _ = reader.ReadByte()
		if c < '0' {
			break
		}
		n = n*10 + int(c-'0')
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
	f1[10*k+n]++
	f2[n*10+k]++
}

func main() {
	N := in()
	for N > 0 {
		calc(N)
		N--
	}
	ans := 0
	for i := 0; i < 100; i++ {
		ans += f1[i] * f2[i]
	}
	fmt.Println(ans)
}

