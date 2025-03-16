<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"sort"
)

func main() {
	var a, b []int
	var i, N int

	fmt.Scanf("%d", &N)
	a = make([]int, N)
	b = make([]int, N)

	for i = 0; i < N; i++ {
		fmt.Scanf("%d", &a[i])
		b[i] = a[i]
	}

	sort.Ints(b)

	frontHalf := b[N/2-1]
	backHalf := b[N/2]

	for i = 0; i < N; i++ {
		if a[i] < backHalf {
			fmt.Println(backHalf)
		} else {
			fmt.Println(frontHalf)
		}
	}
}

