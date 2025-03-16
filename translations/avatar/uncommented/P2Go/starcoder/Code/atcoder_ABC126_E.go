package main
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N, M int
	fmt.Fscanln(reader, &N, &M)
	edge := make([][]int, N)
	for i := 0; i < N; i++ {
		edge[i] = make([]int, 0)
	}
	for i := 0; i < M; i++ {
		var X, Y, Z int
		fmt.Fscanln(reader, &X, &Y, &Z)
		edge[X-1] = append(edge[X-1], Y-1)
		edge[Y-1] = append(edge[Y-1], X-1)
	}
	used := make([]bool, N)
	ans := 0
	for i := 0; i < N; i++ {
		if!used[i] {
			ans++
			queue := make([]int, 0)
			queue = append(queue, i)
			for len(queue) > 0 {
				node := queue[0]
				queue = queue[1:]
				used[node] = true
				for _, nextnode := range edge[node] {
					if!used[nextnode] {
						queue = append(queue, nextnode)
					}
				}
			}
		}
	}
	fmt.Println(ans)
}
