package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Read the number of nodes N and the number of edges M
func readInput() (int, int) {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &N, &M)
	return
}

// Initialize adjacency lists for each node
var edges [100001]map[int]bool

// Initialize degrees for each node
var degs [100001]int

// Initialize parity for each node
var parity [100001]int

// Initialize flag to mark visited nodes
var flag [100001]bool

// Read each edge and update adjacency lists and degree lists
func readEdges() {
	for i := 0; i < M; i++ {
		a, b := readInts()
		if _, ok := edges[a];!ok {
			edges[a] = make(map[int]bool)
		}
		if _, ok := edges[b];!ok {
			edges[b] = make(map[int]bool)
		}
		edges[a][b] = true
		edges[b][a] = true
		degs[a] += 1
		degs[b] += 1
	}
}

// Initialize a heap Q with nodes based on their degrees
var Q []int

// Process nodes from the heap
func processNodes() {
	for i := 0; i < N; i++ {
		u := processNode()
		for v := range edges[u] {
			delete(edges[v], u)
			if parity[u]!= 0 {
				fmt.Println(u, v)
				parity[u] = 1 - parity[u]
			} else {
				fmt.Println(v, u)
				parity[v] = 1 - parity[v]
			}
			degs[v] -= 1
			heapPush(v)
		}
	}
}

// Process a node from the heap
func processNode() int {
	d, u := heapPop()
	flag[u] = true
	return u
}

// Initialize a heap Q with nodes based on their degrees
func heapInit() {
	for i := 0; i < N; i++ {
		heapPush(i)
	}
}

// Push a node into the heap
func heapPush(u int) {
	heapq.Push(Q, degs[u])
}

// Pop a node from the heap
func heapPop() (int, int) {
	d := heapq.Pop(Q).(int)
	for i, v := range Q {
		if v == d {
			return d, i
		}
	}
	return -1, -1
}

// Read a line of input as a space-separated integer array
func readInts() []int {
	reader := bufio.NewReader(os.Stdin)
	line, _, _ := reader.ReadLine()
	fields := strings.Fields(string(line))
	ints := make([]int, len(fields))
	for i, field := range fields {
		ints[i], _ = strconv.Atoi(field)
	}
	return ints
}

func main() {
	N, M := readInput()
	readEdges()
	heapInit()
	processNodes()
}

