package main

import (
	"fmt"
	"os"
	"bufio"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Fscanln(reader, &n, &m)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanln(reader, &a[i])
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
	for i := 0; i < m; i++ {
		pop := a[0]
		a[0] = pop / 2
		push(a, 0)
	}
	ans := 0
	for i := 0; i < n; i++ {
		ans += a[i]
	}
	fmt.Println(ans)
}

func push(a []int, i int) {
	for i > 0 && a[i] < a[(i-1)/2] {
		a[i], a[(i-1)/2] = a[(i-1)/2], a[i]
		i = (i - 1) / 2
	}
}

func pop(a []int) int {
	ret := a[0]
	a[0] = a[len(a)-1]
	a = a[:len(a)-1]
	push(a, 0)
	return ret
}

