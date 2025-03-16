
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscanf(reader, "%d\n", &n)
	size := 1 << n
	s := make([]int, size)
	spawned := make([]bool, size)
	spawned[size-1] = true
	for i := 0; i < size; i++ {
		fmt.Fscanf(reader, "%d", &s[i])
	}
	sort.Ints(s)
	active := []int{s[size-1]}
	spawned[size-1] = true
	for i := 0; i < n; i++ {
		sort.Slice(active, func(j, k int) bool {
			return active[j] > active[k]
		})
		activated := []int{}
		next := size - 1
		for _, slime := range active {
			for next >= 0 && (s[next] >= slime || spawned[next]) {
				next--
			}
			if next < 0 {
				fmt.Println("No")
				return
			}
			spawned[next] = true
			activated = append(activated, s[next])
		}
		active = append(active, activated...)
	}
	fmt.Println("Yes")
}

