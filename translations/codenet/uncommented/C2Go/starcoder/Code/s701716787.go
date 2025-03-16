package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// #define _CRT_SECURE_NO_WARNINGS

const COMMAND_LENGTH = 10

type st_node struct {
	st_parent *st_node
	st_left   *st_node
	st_right  *st_node
	s4_key    int
}

func main() {
	var st_tp_root *st_node
	var s4_t_numCommand int
	var s4_t_iCommand int
	var s1_tp_command [COMMAND_LENGTH]byte
	var s4_t_insertKey int
	var s4_t_RtnStrcmp int

	st_tp_root = nil

	//命令数
	s4_t_numCommand, _ = strconv.Atoi(os.Args[1])

	//コマンド実行
	for s4_t_iCommand = 0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++ {
		//TODO コマンドにより引数が異なる問題
		//コマンド(insert or print)
		fmt.Scanf("%s", &s1_tp_command)

		//コマンドの実行
		//isertとprintfしか入力されない前提で作成
		//コマンドの種類を増やす場合、print用のelse if文を追加すること。
		s4_t_RtnStrcmp = strings.Compare(string(s1_tp_command), "insert")
		if s4_t_RtnStrcmp == 0 {
			//insertならキーの値を取得
			fmt.Scanf("%d", &s4_t_insertKey)
			d_insert(&st_tp_root, s4_t_insertKey)
		} else {
			d_print(st_tp_root)
		}
	}
}

func d_insert(st_ap2_root **st_ap2_root, s4_a_key int) {
	var st_tp_parentNode *st_node
	var st_tp_indexNode *st_node
	var st_tp_insertNode *st_node

	st_tp_insertNode = newST_NODE(s4_a_key)

	st_tp_parentNode = nil
	st_tp_indexNode = *st_ap2_root

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
	} else if s4_a_key < st_tp_parentNode.s4_key {
		st_tp_parentNode.st_left = st_tp_insertNode
	} else {
		st_tp_parentNode.st_right = st_tp_insertNode
	}
}

func d_print(st_ap_root *st_node) {
	s_printInOrder(st_ap_root)
	fmt.Println()
	s_printPreOrder(st_ap_root)
	fmt.Println()
}

//st_ap_node…探索開始ノード
func s_printPreOrder(st_ap_node *st_node) {
	if st_ap_node == nil {
		return
	}

	fmt.Printf(" %d", st_ap_node.s4_key)
	s_printPreOrder(st_ap_node.st_left)
	s_printPreOrder(st_ap_node.st_right)
}

//st_ap_node…探索開始ノード
func s_printInOrder(st_ap_node *st_node) {
	var s4_s_printedNumNode int

	if st_ap_node == nil {
		return
	}

	s_printInOrder(st_ap_node.st_left)
	fmt.Printf(" %d", st_ap_node.s4_key)
	s_printInOrder(st_ap_node.st_right)
}

//ST_NODEのコンストラクタもどき
func newST_NODE(s4_a_key int) *st_node {
	var st_tp_node *st_node
	st_tp_node = new(st_node)
	st_tp_node.st_parent = nil
	st_tp_node.st_left = nil
	st_tp_node.st_right = nil
	st_tp_node.s4_key = s4_a_key

	return(st_tp_node)
}

