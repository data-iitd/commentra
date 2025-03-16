package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	main := Main{}
	main.run()
}

type Main struct {
}

func (this *Main) run() {
	sc := bufio.NewScanner(os.Stdin)
	N, _ := strconv.Atoi(sc.Text())
	M, _ := strconv.Atoi(sc.Text())
	a := make([]int, N)
	for i := 0; i < N; i++ {
		a[i] = 0
	}
	for i := 0; i < M; i++ {
		k, _ := strconv.Atoi(sc.Text())
		for j := 0; j < k; j++ {
			s, _ := strconv.Atoi(sc.Text())
			s--
			a[s] = a[s] | (1 << i)
		}
	}
	p, _ := strconv.Atoi(sc.Text())
	ans := 0
	for s := 0; s < (1 << N); s++ {
		t := 0
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

