package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N, M int
	fmt.Fscan(reader, &N, &M)
	edge := make([][]int, N)
	for i := 0; i < M; i++ {
		var X, Y, Z int
		fmt.Fscan(reader, &X, &Y, &Z)
		X--
		Y--
		edge[X] = append(edge[X], Y)
		edge[Y] = append(edge[Y], X)
	}

	used := make([]bool, N)
	ans := 0
	for i := 0; i < N; i++ {
		if !used[i] {
			ans++
			queue := []int{i}
			for len(queue) > 0 {
				node := queue[0]
				queue = queue[1:]
				used[node] = true
				for _, nextnode := range edge[node] {
					if !used[nextnode] {
						queue = append(queue, nextnode)
					}
				}
			}
		}
	}

	fmt.Fprintln(writer, ans)
}
