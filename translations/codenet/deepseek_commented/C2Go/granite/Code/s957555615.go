
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	Right  *Node
	Left   *Node
	Parent *Node
	Key    int
}

var root *Node

func treeMinimum(x *Node) *Node {
	for x.Left!= nil {
		x = x.Left
	}
	return x
}

func treeMaximum(x *Node) *Node {
	for x.Right!= nil {
		x = x.Right
	}
	return x
}

func treeSearch(u *Node, k int) *Node {
	if u == nil || k == u.Key {
		return u
	}
	if k < u.Key {
		return treeSearch(u.Left, k)
	}
	return treeSearch(u.Right, k)
}

func treeSuccessor(x *Node) *Node {
	if x.Right!= nil {
		return treeMinimum(x.Right)
	}
	y := x.Parent
	for y!= nil && x == y.Right {
		x = y
		y = y.Parent
	}
	return y
}

func treeDelete(z *Node) {
	var y *Node
	var x *Node
	if z.Left == nil || z.Right == nil {
		y = z
	} else {
		y = treeSuccessor(z)
	}
	if y.Left!= nil {
		x = y.Left
	} else {
		x = y.Right
	}
	if x!= nil {
		x.Parent = y.Parent
	}
	if y.Parent == nil {
		root = x
	} else if y == y.Parent.Left {
		y.Parent.Left = x
	} else {
		y.Parent.Right = x
	}
	if y!= z {
		z.Key = y.Key
	}
}

func insert(k int) {
	var y *Node
	var x *Node
	z := &Node{Key: k}
	x = root
	y = nil
	for x!= nil {
		y = x
		if z.Key < x.Key {
			x = x.Left
		} else {
			x = x.Right
		}
	}
	z.Parent = y
	if y == nil {
		root = z
	} else if z.Key < y.Key {
		y.Left = z
	} else {
		y.Right = z
	}
}

func inorder(u *Node) {
	if u == nil {
		return
	}
	inorder(u.Left)
	fmt.Printf(" %d", u.Key)
	inorder(u.Right)
}

func preorder(u *Node) {
	if u == nil {
		return
	}
	fmt.Printf(" %d", u.Key)
	preorder(u.Left)
	preorder(u.Right)
}

func main() {
	data, _ := os.Open(os.Args[1])
	defer data.Close()
	scanner := bufio.NewScanner(data)
	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		if fields[0] == "insert" {
			insert(mustParseInt(fields[1]))
		} else if fields[0] == "find" {
			t := treeSearch(root, mustParseInt(fields[1]))
			if t!= nil {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		} else if fields[0] == "print" {
			inorder(root)
			fmt.Println()
			preorder(root)
			fmt.Println()
		} else if fields[0] == "delete" {
			treeDelete(treeSearch(root, mustParseInt(fields[1])))
		}
	}
}

func mustParseInt(s string) int {
	v, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return v
}

