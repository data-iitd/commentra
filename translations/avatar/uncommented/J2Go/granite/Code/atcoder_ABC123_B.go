
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var a [5]int
	var r [5]int
	for i := 0; i < 5; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
		r[i] = a[i] % 10
	}
	type pair struct {
		key   int
		value int
	}
	pairs := make([]pair, 0)
	for i := 0; i < 5; i++ {
		if r[i]!= 0 {
			pairs = append(pairs, pair{10 - r[i], a[i]})
		}
	}
	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i].key < pairs[j].key
	})
	if len(pairs) == 0 {
		var ans int
		for i := 0; i < 5; i++ {
			ans += a[i]
		}
		fmt.Println(ans)
		return
	}
	last := pairs[len(pairs)-1].value
	idx := 0
	for i := 0; i < 5; i++ {
		if a[i] == last {
			idx = i
		}
	}
	var ans int
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
	fmt.Println(ans)
}

