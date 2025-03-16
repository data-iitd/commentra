package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	INF = 1e18
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N, M int
	fmt.Fscan(reader, &N, &M)

	edge := make([][]int, N)
	for i := 0; i < M; i++ {
		var X, Y int
		fmt.Fscan(reader, &X, &Y)
		X-- // Convert to 0-based index
		Y-- // Convert to 0-based index
		edge[X] = append(edge[X], Y)
		edge[Y] = append(edge[Y], X)
	}

	used := make([]bool, N)
	ans := 0

	for i := 0; i < N; i++ {
		if !used[i] {
			ans++
			queue := []int{i}
			used[i] = true

			for len(queue) > 0 {
				node := queue[0]
				queue = queue[1:]

				for _, nextnode := range edge[node] {
					if !used[nextnode] {
						used[nextnode] = true
						queue = append(queue, nextnode)
					}
				}
			}
		}
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
