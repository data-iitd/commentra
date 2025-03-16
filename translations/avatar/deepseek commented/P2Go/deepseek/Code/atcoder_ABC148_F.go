package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	mod    = int(1e9 + 7)
	INF    = int(1e18)
	reader = bufio.NewReader(os.Stdin)
)

func inp() int {
	num, _ := strconv.Atoi(readLine())
	return num
}

func inpl() []int {
	nums := []int{}
	numStrs := strings.Split(readLine(), " ")
	for _, numStr := range numStrs {
		num, _ := strconv.Atoi(numStr)
		nums = append(nums, num)
	}
	return nums
}

func main() {
	nums := inpl()
	n := nums[0]
	ta := nums[1] - 1
	ao := nums[2] - 1

	g := make([][]int, n)
	for i := 0; i < n-1; i++ {
		nums := inpl()
		a := nums[0] - 1
		b := nums[1] - 1
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}

	taDist := make([]int, n)
	for i := 0; i < n; i++ {
		taDist[i] = -1
	}
	taDist[ta] = 0

	aoDist := make([]int, n)
	for i := 0; i < n; i++ {
		aoDist[i] = -1
	}
	aoDist[ao] = 0

	var taDFS func(node int)
	taDFS = func(node int) {
		for _, v := range g[node] {
			if taDist[v] != -1 {
				continue
			}
			taDist[v] = taDist[node] + 1
			taDFS(v)
		}
	}

	var aoDFS func(node int)
	aoDFS = func(node int) {
		for _, v := range g[node] {
			if aoDist[v] != -1 {
				continue
			}
			aoDist[v] = aoDist[node] + 1
			aoDFS(v)
		}
	}

	aoDFS(ao)
	taDFS(ta)

	res := 0
	for i := 0; i < n; i++ {
		if taDist[i] > aoDist[i] {
			continue
		}
		if aoDist[i] > res {
			res = aoDist[i]
		}
	}

	fmt.Println(res - 1)
}
