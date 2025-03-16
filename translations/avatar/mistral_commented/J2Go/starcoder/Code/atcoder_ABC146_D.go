
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Declaring the number of vertices in the graph
var n int

// Declaring a 2D ArrayList to represent the graph
var g [][]Edge

// Declaring an array to store the answer
var ans []int

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())

	// Creating an empty 2D ArrayList to store the graph
	g = make([][]Edge, n)
	for i := 0; i < n; i++ {
		g[i] = make([]Edge, 0)
	}

	for i := 0; i < n-1; i++ {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		b, _ := strconv.Atoi(sc.Text())
		g[a-1] = append(g[a-1], Edge{i, b - 1})
		g[b-1] = append(g[b-1], Edge{i, a - 1})
	}

	ans = make([]int, n-1)
	dfs(0, -1, -1)

	max := 0
	for _, temp := range ans {
		max = max + temp
	}

	fmt.Println(max)
	for _, c := range ans {
		fmt.Println(c)
	}
}

// Function to perform Depth First Search
func dfs(to, color, parents int) {
	k := 1
	for _, e := range g[to] {
		if e.to == parents {
			continue
		}
		if k == color {
			k++
		}
		ans[e.id] = k
		dfs(e.to, k, to)
		k++
	}
}

// Class to represent an edge
type Edge struct {
	id  int
	to  int
	wgt int
}

