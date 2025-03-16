
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
	n int
	a []int
)

func merge(left, mid, right int) int64 {
	var (
		i, j, k int
		cnt       int64
		n1        = mid - left
		n2        = right - mid
	)
	for i = 0; i < n1; i++ {
		a[i] = a[left+i]
	}
	for j = 0; j < n2; j++ {
		a[n1+j] = a[mid+j]
	}
	a[n1] = a[n2] = INF
	i, j = 0, 0
	for k = left; k < right; k++ {
		if a[i] <= a[j] {
			a[k] = a[i]
			i++
		} else {
			a[k] = a[j]
			j++
			cnt += int64(n1 - i)
		}
	}
	return cnt
}

func mergesort(left, right int) int64 {
	var (
		mid int
		v1, v2, v3 int64
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
	a = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}
	cnt := mergesort(0, n)
	fmt.Println(cnt)
}

