
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
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of vertices:")
	n, _ := strconv.Atoi(reader.ReadLine()[0:1])
	edges := make([]*Edge, n)
	for i := 0; i < n; i++ {
		input := strings.Split(reader.ReadLine()[0:10], " ")
		edges[i] = &Edge{P: i + 1, I: i + 1, S: input[0]}
	}
	sort.Slice(edges, func(i, j int) bool {
		if edges[i].S < edges[j].S {
			return true
		} else if edges[i].S == edges[j].S {
			return edges[i].P < edges[j].P
		}
		return false
	})
	for _, edge := range edges {
		fmt.Println(edge.I)
	}
}

