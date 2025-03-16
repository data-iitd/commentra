
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
	weight int
	index  int
	name   string
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of edges:")
	n, _ := strconv.Atoi(reader.ReadLine()[0:1])
	edges := make([]*Edge, n)
	for i := 0; i < n; i++ {
		input := strings.Split(reader.ReadLine()[0:10], " ")
		edges[i] = &Edge{weight: 0, index: i + 1, name: input[0]}
	}
	sort.Slice(edges, func(i, j int) bool {
		if edges[i].name < edges[j].name {
			return true
		} else if edges[i].name == edges[j].name {
			return edges[i].weight > edges[j].weight
		}
		return false
	})
	for _, edge := range edges {
		fmt.Println(edge.index)
	}
}

