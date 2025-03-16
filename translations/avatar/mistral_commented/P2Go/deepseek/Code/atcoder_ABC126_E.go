package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const INF = 10e18

var sc = bufio.NewScanner(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func main() {
	sc.Split(bufio.ScanWords)
	sc.Buffer(make([]byte, 1024), int(10e8))

	N, M := nextInt(), nextInt()
	edge := make([][]int, N)

	for i := 0; i < M; i++ {
		X, Y := nextInt()-1, nextInt()-1
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
	out.Flush()
}

