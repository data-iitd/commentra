
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type ST_NODE struct {
	st_parent *ST_NODE
	st_left   *ST_NODE
	st_right  *ST_NODE
	s4_key    int
}

func main() {
	st_tp_root := new(ST_NODE)
	var s4_t_numCommand int
	var s4_t_iCommand int
	var s1_tp_command string
	var s4_t_insertKey int
	var s4_t_RtnStrcmp int

	st_tp_root = nil

	//COMMAND数
	fmt.Scan(&s4_t_numCommand)

	//コマンド実行
	for s4_t_iCommand = 0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++ {
		//TODO コマンドにより引数が異なる問題
		//コマンド(insert or print)
		fmt.Scan(&s1_tp_command)

		//コマンドの実行
		//isertとprintfしか入力されない前提で作成
		//コマンドの種類を増やす場合、print用のelse if文を追加すること。
		s4_t_RtnStrcmp = strings.Compare(s1_tp_command, "insert")
		if s4_t_RtnStrcmp == 0 {
			//insertならキーの値を取得
			fmt.Scan(&s4_t_insertKey)
			d_d_insert(&st_tp_root, s4_t_insertKey)
		} else {
			d_d_print(st_tp_root)
		}
	}
}

func d_d_insert(st_ap2_root **ST_NODE, s4_a_key int) {
	st_tp_parentNode := new(ST_NODE)
	st_tp_indexNode := *st_ap2_root
	st_tp_insertNode := new(ST_NODE)

	st_tp_insertNode.s4_key = s4_a_key
	st_tp_parentNode = nil
	st_tp_indexNode = nil

	for st_tp_indexNode!= nil {
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
	} else if st_tp_insertNode.s4_key < st_tp_parentNode.s4_key {
		st_tp_parentNode.st_left = st_tp_insertNode
	} else {
		st_tp_parentNode.st_right = st_tp_insertNode
	}
}

func d_d_print(st_ap_root *ST_NODE) {
	s_s_printInOrder(st_ap_root)
	fmt.Println()
	s_s_printPreOrder(st_ap_root)
	fmt.Println()
}

//st_ap_node…探索開始ノード
func s_s_printPreOrder(st_ap_node *ST_NODE) {
	if st_ap_node == nil {
		return
	}

	fmt.Printf(" %d", st_ap_node.s4_key)
	s_s_printPreOrder(st_ap_node.st_left)
	s_s_printPreOrder(st_ap_node.st_right)
}

//st_ap_node…探索開始ノード
func s_s_printInOrder(st_ap_node *ST_NODE) {
	static s4_s_printedNumNode int = 0

	if st_ap_node == nil {
		return
	}

	s_s_printInOrder(st_ap_node.st_left)
	fmt.Printf(" %d", st_ap_node.s4_key)
	s_s_printInOrder(st_ap_node.st_right)
}

//ST_NODEのコンストラクタもどき
func st_dp_newST_NODE(s4_a_key int) *ST_NODE {
	st_tp_node := new(ST_NODE)
	st_tp_node.st_parent = nil
	st_tp_node.st_left = nil
	st_tp_node.st_right = nil
	st_tp_node.s4_key = s4_a_key

	return st_tp_node
}

