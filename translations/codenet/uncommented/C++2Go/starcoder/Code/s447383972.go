package main
import (
	"fmt"
	"sort"
)

func main() {
	var n, tot int
	fmt.Scanf("%d", &n)
	a := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	sort.Ints(a[1:])
	for i := 1; i <= n; i++ {
		if a[i] == a[i+1] {
			q[tot] = a[i]
			i++
			tot++
		}
	}
	fmt.Printf("%d\n", q[tot]*q[tot-1])
}

