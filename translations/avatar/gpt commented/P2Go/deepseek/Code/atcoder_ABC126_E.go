package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const INF = 1000000000000000000

var sc = bufio.NewScanner(os.Stdin)

func nextInt() int {
	sc.Scan()
	i, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}
	return i
}

func main() {
	sc.Split(bufio.ScanWords)

	N := nextInt()
	M := nextInt()

	edge := make([][]int, N)

	for i := 0; i < M; i++ {
		X := nextInt() - 1
		Y := nextInt() - 1
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

	fmt.Println(ans)
}

