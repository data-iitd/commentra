
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
	s string
	p int64
	i int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of edges:")
	n, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
	edges := make([]*Edge, n)
	for i := int64(0); i < n; i++ {
		fmt.Printf("Enter edge %d (string and long long value separated by a space): ", i+1)
		input := readLine(reader)
		parts := strings.Split(input, " ")
		edges[i] = &Edge{s: parts[0], p: mustParseInt(parts[1]), i: int(i + 1)}
	}
	sort.Slice(edges, func(i, j int) bool {
		if edges[i].s!= edges[j].s {
			return edges[i].s < edges[j].s
		}
		return edges[i].p < edges[j].p
	})
	for _, edge := range edges {
		fmt.Println(edge.i)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	panic(err)
}

func mustParseInt(s string) int64 {
	n, err := strconv.ParseInt(s, 10, 64)
	if err!= nil {
		panic(err)
	}
	return n
}

