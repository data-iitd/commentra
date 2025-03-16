
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Edge struct {
	P int
	I int
	S string
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	edges := make([]*Edge, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		s := scanner.Text()
		scanner.Scan()
		p, _ := strconv.Atoi(scanner.Text())
		edges[i] = &Edge{P: p, I: i, S: s}
	}
	sort.Slice(edges, func(i, j int) bool {
		if edges[i].S!= edges[j].S {
			return edges[i].S < edges[j].S
		}
		return edges[i].P < edges[j].P
	})
	for _, e := range edges {
		fmt.Println(e.I + 1)
	}
}

