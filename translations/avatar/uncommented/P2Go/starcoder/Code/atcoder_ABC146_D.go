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
	var N int
	fmt.Fscanln(reader, &N)
	G := make([][]int, N)
	E := make(map[int]int)
	for i := 0; i < N-1; i++ {
		a, b := readIntSlice(reader)
		a--
		b--
		G[a] = append(G[a], b)
		G[b] = append(G[b], a)
		E[(a, b)] = 0
	}
	K := bfs(0, N, G, E)
	fmt.Println(K)
	for _, value := range E {
		fmt.Println(value)
	}
}

func bfs(v int, N int, G [][]int, E map[int]int) int {
	visited := make([]int, N)
	queue := make([]int, 0)
	K := -1
	node2color := make([]int, N)
	queue = append(queue, v)
	visited[v] = 1
	for len(queue) > 0 {
		q := queue[0]
		queue = queue[1:]
		color := 0
		for _, nex := range G[q] {
			if visited[nex] {
				continue
			}
			visited[nex] = 1
			color += 1
			if color == node2color[q] {
				color += 1
			}
			node2color[nex] = color
			E[(min(q, nex), max(q, nex))] = color
			queue = append(queue, nex)
		}
		K = max(K, color)
	}
	return K
}

func readIntSlice(reader *bufio.Reader) []int {
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	slice := strings.Split(line, " ")
	var ret []int
	for _, s := range slice {
		if s!= "" {
			ret = append(ret, strconv.Atoi(s))
		}
	}
	return ret
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

