
package main

import (
	"fmt"
	"strconv"
)

type stNode struct {
	stParent *stNode
	stLeft   *stNode
	stRight  *stNode
	s4Key    int
}

func main() {
	stRoot := &stNode{}
	s4NumCommand := 0
	s4iCommand := 0
	s1Command := ""
	s4InsertKey := 0
	s4RtnStrcmp := 0

	fmt.Scan(&s4NumCommand)

	for s4iCommand < s4NumCommand {
		fmt.Scan(&s1Command)

		if s1Command == "insert" {
			fmt.Scan(&s4InsertKey)
			dInsert(stRoot, s4InsertKey)
		} else {
			dPrint(stRoot)
		}
		s4iCommand++
	}
}

func dInsert(stRoot *stNode, s4InsertKey int) {
	stParentNode := &stNode{}
	stIndexNode := stRoot
	stInsertNode := &stNode{s4Key: s4InsertKey}

	for stIndexNode != nil {
		stParentNode = stIndexNode
		if stInsertNode.s4Key < stIndexNode.s4Key {
			stIndexNode = stIndexNode.stLeft
		} else {
			stIndexNode = stIndexNode.stRight
		}
	}
	stInsertNode.stParent = stParentNode

	if stParentNode == nil {
		*stRoot = *stInsertNode
	} else if s4InsertKey < stParentNode.s4Key {
		stParentNode.stLeft = stInsertNode
	} else {
		stParentNode.stRight = stInsertNode
	}
}

func dPrint(stRoot *stNode) {
	sPrintInOrder(stRoot)
	fmt.Println()
	sPrintPreOrder(stRoot)
	fmt.Println()
}

func sPrintPreOrder(stNode *stNode) {
	if stNode == nil {
		return
	}

	fmt.Print(" ", stNode.s4Key)
	sPrintPreOrder(stNode.stLeft)
	sPrintPreOrder(stNode.stRight)
}

func sPrintInOrder(stNode *stNode) {
	sPrintInOrder(stNode.stLeft)
	fmt.Print(" ", stNode.s4Key)
	sPrintInOrder(stNode.stRight)
}

func stNewSTNode(s4Key int) *stNode {
	stNode := &stNode{s4Key: s4Key}
	return stNode
}

