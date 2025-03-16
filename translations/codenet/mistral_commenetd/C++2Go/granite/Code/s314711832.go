

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Edge struct {
	Source   int
	Target   int
	Distance int
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	var V, E, r int
	fmt.Fscanf(reader, "%d %d %d\n", &V, &E, &r)

	edges := make([]Edge, E)
	for i := 0; i < E; i++ {
		fields := strings.Split(readLine(reader), " ")
		source, _ := strconv.Atoi(fields[0])
		target, _ := strconv.Atoi(fields[1])
		distance, _ := strconv.Atoi(fields[2])
		edges[i] = Edge{Source: source, Target: target, Distance: distance}
	}

	distances := make([]int, V)
	for i := 0; i < V; i++ {
		distances[i] = 1000000001
	}
	distances[r] = 0

	for i := 1; i < V; i++ {
		prevDistances := make([]int, V)
		copy(prevDistances, distances)
		for j := 0; j < E; j++ {
			edge := edges[j]
			if distances[edge.Source]+edge.Distance < distances[edge.Target] {
				distances[edge.Target] = distances[edge.Source] + edge.Distance
			}
		}
		if same(distances, prevDistances) {
			break
		}
	}

	for i := 0; i < V; i++ {
		if distances[i] == 1000000001 {
			fmt.Println("INF")
		} else {
			fmt.Println(distances[i])
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	return ""
}

func same(a, b []int) bool {
	for i := 0; i < len(a); i++ {
		if a[i]!= b[i] {
			return false
		}
	}

	return true
}

