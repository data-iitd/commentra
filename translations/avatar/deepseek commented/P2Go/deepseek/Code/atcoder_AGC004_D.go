package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func dfs(links [][]int, n, k int, v, p int) (int, int) {
	heightFromLeaf := 0
	cutCount := 0
	for _, u := range links[v] {
		if u == 0 {
			continue
		}
		hgt, cut := dfs(links, n, k, u, v)
		if hgt > heightFromLeaf {
			heightFromLeaf = hgt
		}
		cutCount += cut
	}
	heightFromLeaf++
	if p != 0 && heightFromLeaf == k {
		heightFromLeaf = 0
		cutCount++
	}
	return heightFromLeaf, cutCount
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	k, _ := strconv.Atoi(readLine(reader))
	input, _ := reader.ReadString('\n')
	aaa := make([]int, n)
	for i, a := range strings.Fields(input) {
		aaa[i], _ = strconv.Atoi(a)
		aaa[i]--
	}
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		links[i] = []int{}
	}
	for i := 1; i < n; i++ {
		a, _ := strconv.Atoi(readLine(reader))
		links[a-1] = append(links[a-1], i)
	}
	_, ans := dfs(links, n, k, 0, 0)
	if aaa[0] != 1 {
		ans++
	}
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	line = line[:len(line)-1]
	return line
}
