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

func init() {
	sc.Buffer([]byte{}, INF)
	sc.Split(bufio.ScanWords)
}

func readInt() int {
	sc.Scan()
	ret, _ := strconv.Atoi(sc.Text())
	return ret
}

func main() {
	N, M := readInt(), readInt()
	edge := make([][]int, N)
	for i := 0; i < M; i++ {
		X, Y := readInt()-1, readInt()-1
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
	fmt.Fprintln(out, ans)
	out.Flush()
}
