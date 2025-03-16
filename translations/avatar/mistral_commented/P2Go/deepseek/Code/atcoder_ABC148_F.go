package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	mod  = int(1e9 + 7)
	INF  = int(1e18)
	sc   = bufio.NewScanner(os.Stdin)
	wr   = bufio.NewWriter(os.Stdin)
)

func init() {
	sc.Split(bufio.ScanWords)
}

func readInt() int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func readInts() []int {
	sc.Scan()
	words := bufio.ScanWords
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func main() {
	n := readInt()
	ta := readInt() - 1
	ao := readInt() - 1
	ta -= 1
	ao -= 1

	g := make([][]int, n)

	for i := 0; i < n-1; i++ {
		a := readInt() - 1
		b := readInt() - 1
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}

	ta_dist := make([]int, n)
	ao_dist := make([]int, n)

	for i := 0; i < n; i++ {
		ta_dist[i] = -1
		ao_dist[i] = -1
	}

	ta_dist[ta] = 0
	ao_dist[ao] = 0

	var ta_dfs func(node int)
	var ao_dfs func(node int)

	ta_dfs = func(node int) {
		for _, v := range g[node] {
			if ta_dist[v] != -1 {
				continue
			}
			ta_dist[v] = ta_dist[node] + 1
			ta_dfs(v)
		}
	}

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
		if ta_dist[i] == -1 || ao_dist[i] == -1 || ta_dist[i] > ao_dist[i] {
			continue
		}
		if res < ao_dist[i] {
			res = ao_dist[i]
		}
	}

	fmt.Println(res - 1)
}

