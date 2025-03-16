package main
import (
	"fmt"
	"os"
)
func bfs(v, N int, G [][]int, E map[int]int) int {
	visited := make([]bool, N)
	queue := make([]int, 0)
	K := -1
	node2color := make([]int, N)
	queue = append(queue, v)
	visited[v] = true
	for len(queue) > 0 {
		q := queue[0]
		queue = queue[1:]
		color := 0
		for _, nex := range G[q] {
			if visited[nex] {
				continue
			}
			visited[nex] = true
			color++
			if color == node2color[q] {
				color++
			}
			node2color[nex] = color
			E[min(q, nex)] = color
			queue = append(queue, nex)
		}
		K = max(K, color)
	}
	return K
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func main() {
	N := nextInt()
	G := make([][]int, N)
	E := make(map[int]int)
	for i := 0; i < N-1; i++ {
		a, b := nextInt(), nextInt()
		G[a-1] = append(G[a-1], b-1)
		G[b-1] = append(G[b-1], a-1)
		E[a-1] = 0
		E[b-1] = 0
	}
	K := bfs(0, N, G, E)
	fmt.Println(K)
	for _, value := range E {
		fmt.Println(value)
	}
}
func nextInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return int(readInt64(scanner.Bytes()))
}
func readInt64(bytes []byte) int64 {
	i, _ := strconv.ParseInt(string(bytes), 10, 64)
	return i
}
