
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	a := make([]int, 5)
	r := make([]int, 5)
	for i := 0; i < 5; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
		r[i] = a[i] % 10
	}

	type pair struct {
		b, a int
	}
	pairs := make([]pair, 0, 5)
	for i := 0; i < 5; i++ {
		if r[i]!= 0 {
			pairs = append(pairs, pair{10 - r[i], a[i]})
		}
	}
	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i].b < pairs[j].b
	})

	ans := 0
	if len(pairs) == 0 {
		for i := 0; i < 5; i++ {
			ans += a[i]
		}
	} else {
		last := pairs[len(pairs)-1].a
		idx := -1
		for i := 0; i < 5; i++ {
			if a[i] == last {
				idx = i
			}
		}
		for i := 0; i < 5; i++ {
			if i!= idx {
				if a[i]%10 == 0 {
					ans += a[i]
				} else {
					ans += a[i] + (10 - r[i])
				}
			}
		}
		ans += last
	}
	fmt.Println(ans)
}

