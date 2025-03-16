package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = 1000000007

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	var n, q int
	sc.Scan()
	n = toInt(sc.Bytes())
	sc.Scan()
	q = toInt(sc.Bytes())
	sc.Scan()
	c := sc.Bytes()

	range_ := make([][2]int, q)
	for i := 0; i < q; i++ {
		sc.Scan()
		range_[i][0] = toInt(sc.Bytes())
		sc.Scan()
		range_[i][1] = toInt(sc.Bytes())
	}

	frag := make([]int, n+1)
	rui := make([]int, n+1)
	for i := 2; i <= n; i++ {
		if c[i-2] == 'A' && c[i-1] == 'C' {
			frag[i]++
		}
		rui[i] = rui[i-1] + frag[i]
	}

	for i := 0; i < q; i++ {
		left := range_[i][0]
		right := range_[i][1]
		fmt.Println(rui[right] - rui[left])
	}
}

func toInt(b []byte) int {
	var num int
	for _, v := range b {
		num = num*10 + int(v-'0')
	}
	return num
}

