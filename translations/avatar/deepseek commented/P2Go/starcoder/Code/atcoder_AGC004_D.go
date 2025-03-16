
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// <START-OF-CODE>

func dfs(links [][]int, n, k, v, p int) (int, int) {
	heightFromLeaf := 0
	cutCount := 0
	for _, u := range links[v] {
		if u == 0 {
			continue
		}
		hgt, cut := dfs(links, n, k, u, v)
		heightFromLeaf = max(heightFromLeaf, hgt)
		cutCount += cut
	}
	heightFromLeaf += 1
	if p!= 0 && heightFromLeaf == k {
		heightFromLeaf = 0
		cutCount += 1
	}
	return heightFromLeaf, cutCount
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, k, _ := readThreeNums(reader)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		links[i] = make([]int, 0, 10)
	}
	for i := 0; i < n-1; i++ {
		u, v := readTwoNums(reader)
		u--
		v--
		links[u] = append(links[u], v)
		links[v] = append(links[v], u)
	}
	heightFromLeaf, cutCount := dfs(links, n, k, 0, 0)
	if links[0][0]!= 1 {
		cutCount += 1
	}
	fmt.Println(cutCount)
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	res := readNNums(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-'; x++ {
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

// 