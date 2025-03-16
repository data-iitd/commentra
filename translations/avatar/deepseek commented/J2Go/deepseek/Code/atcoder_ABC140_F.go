package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N := 0
	fmt.Sscanf(scanner.Text(), "%d", &N)
	size := 1 << N
	S := make([]int, size)
	spawned := make([]bool, size)
	spawned[size-1] = true

	scanner.Scan()
	for i := 0; i < size; i++ {
		fmt.Sscanf(scanner.Text(), "%d", &S[i])
	}

	sort.Ints(S)
	active := []int{S[size-1]}
	spawned[size-1] = true

	for i := 0; i < N; i++ {
		sort.Sort(sort.Reverse(sort.IntSlice(active)))
		activated := []int{}
		next := size - 1

		for _, slime := range active {
			for next >= 0 && (S[next] >= slime || spawned[next]) {
				next--
			}
			if next < 0 {
				fmt.Println("No")
				return
			}
			spawned[next] = true
			activated = append(activated, S[next])
		}
		active = append(active, activated...)
	}
	fmt.Println("Yes")
}

