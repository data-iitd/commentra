
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// <START-OF-CODE>

// Node represents a node in the tree
type Node struct {
	value int
	child []*Node
}

// NewNode creates a new node
func NewNode(value int) *Node {
	return &Node{value: value, child: make([]*Node, 0)}
}

// DFS traverses the tree using DFS
func DFS(root *Node, k int) int {
	if root == nil {
		return 0
	}
	max := 0
	for _, child := range root.child {
		h := DFS(child, k)
		if h > max {
			max = h
		}
	}
	if max == k-1 {
		return 0
	}
	return max + 1
}

// Calculate calculates the answer
func Calculate(n int, k int, as []int) int {
	root := NewNode(0)
	for i := 0; i < n; i++ {
		root.child = append(root.child, NewNode(as[i]))
	}
	return DFS(root, k)
}

// 