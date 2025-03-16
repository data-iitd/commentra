
package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	INF = 0x3f3f3f3f
)

var (
	a  [200000]int
	L  [100000]int
	R  [100000]int
	n  int
)

func merge(left, mid, right int) int {
	var (
		i, j, k int
		cnt      int
	)
	n1 := mid - left
	n2 := right - mid
	for i = 0; i < n1; i++ {
		L[i] = a[left+i]
	}
	for i = 0; i < n2; i++ {
		R[i] = a[mid+i]
	}
	L[n1] = R[n2] = INF
	i, j = 0, 0
	for k = left; k < right; k++ {
		if L[i] <= R[j] {
			a[k] = L[i]
			i++
		} else {
			a[k] = R[j]
			j++
			cnt += n1 - i
		}
	}
	return cnt
}

func mergesort(left, right int) int {
	var (
		mid int
		v1, v2, v3 int
	)
	if left+1 < right {
		mid = (left + right) / 2
		v1 = mergesort(left, mid)
		v2 = mergesort(mid, right)
		v3 = merge(left, mid, right)
		return v1 + v2 + v3
	}
	return 0
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}
	ans := mergesort(0, n)
	fmt.Println(ans)
}

