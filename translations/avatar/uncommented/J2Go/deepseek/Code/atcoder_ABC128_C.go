package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	main := &Main{}
	main.run()
}

type Main struct{}

func (m *Main) run() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	var N, M int
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	M, _ = strconv.Atoi(sc.Text())

	a := make([]int, N)
	for i := 0; i < N; i++ {
		a[i] = 0
	}

	for i := 0; i < M; i++ {
		var k int
		sc.Scan()
		k, _ = strconv.Atoi(sc.Text())
		for j := 0; j < k; j++ {
			var s int
			sc.Scan()
			s, _ = strconv.Atoi(sc.Text())
			s--
			a[s] |= 1 << i
		}
	}

	var p int
	for i := 0; i < M; i++ {
		var x int
		sc.Scan()
		x, _ = strconv.Atoi(sc.Text())
		p |= x << i
	}

	ans := 0
	for s := 0; s < (1 << N); s++ {
		var t int
		for i := 0; i < N; i++ {
			if (s>>i)&1 == 1 {
				t ^= a[i]
			}
		}
		if p == t {
			ans++
		}
	}
	fmt.Println(ans)
}
