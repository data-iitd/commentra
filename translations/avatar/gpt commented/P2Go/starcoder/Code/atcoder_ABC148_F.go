package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single integer from input
func readInt(reader *bufio.Reader) int {
	var n int
	_, err := fmt.Fscan(reader, &n)
	if err!= nil {
		panic(err)
	}
	return n
}

// Function to read a list of integers from input
func readInts(reader *bufio.Reader) []int {
	var ns []int
	line, err := reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	for _, n := range strings.Split(line[:len(line)-1], " ") {
		ns = append(ns, int(n))
	}
	return ns
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n := readInt(reader)
	ta, ao := readInts(reader)
	g := make([][]int, n)
	for i := 0; i < n-1; i++ {
		a, b := readInts(reader)
		g[a-1] = append(g[a-1], b-1)
		g[b-1] = append(g[b-1], a-1)
	}
	ta--
	ao--
	ta_dist := make([]int, n)
	ta_dist[ta] = 0
	ao_dist := make([]int, n)
	ao_dist[ao] = 0
	ta_dfs(g, ta, ta_dist)
	ao_dfs(g, ao, ao_dist)
	res := 0
	for i := 0; i < n; i++ {
		if ta_dist[i] > ao_dist[i] {
			continue
		}
		res = max(res, ao_dist[i])
	}
	fmt.Println(res - 1)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func ta_dfs(g [][]int, node, ta_dist []int) {
	for _, v := range g[node] {
		if ta_dist[v]!= 0 {
			continue
		}
		ta_dist[v] = ta_dist[node] + 1
		ta_dfs(g, v, ta_dist)
	}
}

func ao_dfs(g [][]int, node, ao_dist []int) {
	for _, v := range g[node] {
		if ao_dist[v]!= 0 {
			continue
		}
		ao_dist[v] = ao_dist[node] + 1
		ao_dfs(g, v, ao_dist)
	}
}

