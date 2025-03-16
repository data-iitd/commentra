package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	main := new(Main)
	main.run()
}

type Main struct{}

func (m *Main) run() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	M, _ := strconv.Atoi(scanner.Text())

	a := make([]int, N)

	for i := 0; i < N; i++ {
		a[i] = 0
	}

	for i := 0; i < M; i++ {
		scanner.Scan()
		k, _ := strconv.Atoi(scanner.Text())

		for j := 0; j < k; j++ {
			scanner.Scan()
			s, _ := strconv.Atoi(scanner.Text())
			s--
			a[s] |= 1 << i
		}
	}

	var p int

	for i := 0; i < M; i++ {
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
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
