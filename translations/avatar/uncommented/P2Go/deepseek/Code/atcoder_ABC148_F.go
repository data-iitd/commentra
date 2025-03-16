package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func inp() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}

func inpl() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	ta, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	ao, _ := strconv.Atoi(scanner.Text())
	ta -= 1
	ao -= 1
	g := make([][]int, n)
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())
		a -= 1
		b -= 1
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ta_dist := make([]int, n)
	for i := 0; i < n; i++ {
		ta_dist[i] = -1
	}
	ta_dist[ta] = 0
	ao_dist := make([]int, n)
	for i := 0; i < n; i++ {
		ao_dist[i] = -1
	}
	ao_dist[ao] = 0
	var ta_dfs func(node int)
	ta_dfs = func(node int) {
		for _, v := range g[node] {
			if ta_dist[v] != -1 {
				continue
			}
			ta_dist[v] = ta_dist[node] + 1
			ta_dfs(v)
		}
	}
	var ao_dfs func(node int)
	ao_dfs = func(node int) {
		for _, v := range g[node] {
			if ao_dist[v] != -1 {
				continue
			}
			ao_dist[v] = ao_dist[node] + 1
			ao_dfs(v)
		}
	}
	ao_dfs(ao)
	ta_dfs(ta)
	res := 0
	for i := 0; i < n; i++ {
		if ta_dist[i] > ao_dist[i] {
			continue
		}
		if res < ao_dist[i] {
			res = ao_dist[i]
		}
	}
	fmt.Println(res - 1)
}
