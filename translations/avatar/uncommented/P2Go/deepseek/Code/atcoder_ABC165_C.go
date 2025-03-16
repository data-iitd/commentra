package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(N int, M int, Q int, a []int, b []int, c []int, d []int) {
	var res int
	var rec func([]int)
	rec = func(A []int) {
		if len(A) == N {
			ans := 0
			for i := 0; i < Q; i++ {
				if A[b[i]-1]-A[a[i]-1] == c[i] {
					ans += d[i]
				}
			}
			if ans > res {
				res = ans
			}
			return
		}
		lastMax := 1
		if len(A) > 0 {
			lastMax = A[len(A)-1]
		}
		for i := lastMax; i <= M; i++ {
			rec(append(A, i))
		}
	}
	rec([]int{})
	fmt.Println(res)
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	
	var N, M, Q int
	var a, b, c, d []int
	
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	M, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	Q, _ = strconv.Atoi(sc.Text())
	
	a = make([]int, Q)
	b = make([]int, Q)
	c = make([]int, Q)
	d = make([]int, Q)
	
	for i := 0; i < Q; i++ {
		sc.Scan()
		a[i], _ = strconv.Atoi(sc.Text())
		sc.Scan()
		b[i], _ = strconv.Atoi(sc.Text())
		sc.Scan()
		c[i], _ = strconv.Atoi(sc.Text())
		sc.Scan()
		d[i], _ = strconv.Atoi(sc.Text())
	}
	
	solve(N, M, Q, a, b, c, d)
}

