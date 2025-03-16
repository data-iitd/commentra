
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
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
		sc.Scan()
		k, _ := strconv.Atoi(sc.Text())
		for j := 0; j < k; j++ {
			sc.Scan()
			s, _ := strconv.Atoi(sc.Text())
			s--
			a[s] |= (1 << i)
		}
	}
	p := 0
	for i := 0; i < M; i++ {
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text())
		p |= (x << i)
	}
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

