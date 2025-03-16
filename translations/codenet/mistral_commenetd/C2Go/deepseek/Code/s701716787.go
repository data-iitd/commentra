```go
package main

import (
	"fmt"
	"strings"
)

type ST_NODE struct {
	st_parent *ST_NODE
	st_left   *ST_NODE
	st_right  *ST_NODE
	s4_key    int
}

func vd_d_insert(st_ap2_root **ST_NODE, s4_a_key int) {
	var st_tp_parentNode *ST_NODE
	var st_tp_indexNode *ST_NODE
	var st_tp_insertNode *ST_NODE

	st_tp_insertNode = st_dp_newST_NODE(s4_a_key)

	st_tp_parentNode = nil
	st_tp_indexNode = *st_ap2_root

	for st_tp_indexNode != nil {
		st_tp_parentNode = st_tp_indexNode

		if st_tp_insertNode.s4_key < st_tp_indexNode.s4_key {
			st_tp_indexNode = st_tp_indexNode.st_left
		} else {
			st_tp_indexNode = st_tp_indexNode.st_right
		}
	}

	st_tp_insertNode.st_parent = st_tp_parentNode

	if st_tp_parentNode == nil {
		*st_ap2_root = st_tp_insertNode
	} else if s4_a_key < st_tp_parentNode.s4_key {
		st_tp_parentNode.st_left = st_tp_insertNode
	} else {
		st_tp_parentNode.st_right = st_tp_insertNode
	}
}

func vd_d_print(st_ap_root *ST_NODE) {
	vd_s_printInOrder(st_ap_root)
	fmt.Print("\n")
	vd_s_printPreOrder(st_ap_root)
	fmt.Print("\n")
}

func vd_s_printPreOrder(st_ap_node *ST_NODE) {
	if st_ap_node == nil {
		return
	}

	fmt.Printf(" %d", st_ap_node.s4_key)
	vd_s_printPreOrder(st_ap_node.st_left)
	vd_s_printPreOrder(st_ap_node.st_right)
}

func vd_s_printInOrder(st_ap_node *ST_NODE) {
	if st_ap_node == nil {
		return
	}

	vd_s_printInOrder(st_ap_node.st_left)
	fmt.Printf(" %d", st_ap_node.s4_key)
	vd_s_printInOrder(st_ap_node.st_right)
}

func st_dp_newST_NODE(s4_a_key int) *ST_NODE {
	var st_tp_node *ST_NODE
	st_tp_node = &ST_NODE{
		st_parent: nil,
		st_left:   nil,
		st_right:  nil,
		s4_key:    s4_a_key,
	}
	return st_tp_node
}

func main() {
	var st_tp_root *ST_NODE
	var s4_t_numCommand int
	var s4_t_iCommand int
	var s1_tp_command string
	var s4_t_insertKey int
	var s4_t_RtnStrcmp int

	st_tp_root = nil

	fmt.Print("Enter the number of commands: ")
	fmt.Scan(&s4_t_numCommand)

	for s4_t_iCommand = 0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++ {
		fmt.Print("Enter the command (insert or print): ")
		fmt.Scan(&s1_tp_command)

		s4_t_RtnStrcmp = strings.Compare(s1_tp_command, "insert")
		if s4_t_RtnStrcmp == 0 {
			fmt.Print("Enter the key to be inserted: ")
			fmt.Scan(&s4_t_insertKey)
			vd_d_insert(&st_tp_root, s4_t_insertKey)
		} else {
			vd_d_print(st_tp_root)
		}
	}
}

