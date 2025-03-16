package main

import (
	"bufio"
	"fmt"
	"os"
	"math"
)

const INF = 0x3f3f3f3f

var (
	a = make([]int, 2*1e5+10)
	n int
	L = make([]int, 1e5+5)
	R = make([]int, 1e5+5)
)

func merge(left, mid, right int) int64 {
	var cnt int64 = 0
	n1 := mid - left
	n2 := right - mid

	for i := 0; i < n1; i++ {
		L[i] = a[left+i]
	}

	for i := 0; i < n2; i++ {
		R[i] = a[mid+i]
	}

	L[n1] = INF
	R[n2] = INF

	i, j := 0, 0
	for k := left; k < right; k++ {
		if L[i] <= R[j] {
			a[k] = L[i]
			i++
		} else {
			a[k] = R[j]
			j++
			cnt += int64(n1 - i)
		}
	}

	return cnt
}

func mergesort(left, right int) int64 {
	if left+1 < right {
		mid := (left + right) / 2
		v1 := mergesort(left, mid)
		v2 := mergesort(mid, right)
		v3 := merge(left, mid, right)
		return v1 + v2 + v3
	}
	return 0
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}
	ans := mergesort(0, n)
	fmt.Println(ans)
}

