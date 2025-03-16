#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define U1 unsigned char
#define S1 char
#define	S4 int
#define DU double
#define VD void

#define COMMAND_LENGTH     (10)   /* 命令の文字数 */

type ST_NODE struct {
	st_parent *ST_NODE
	st_left *ST_NODE
	st_right *ST_NODE
	s4_key S4
}

func vd_d_insert(st_ap2_root *ST_NODE, s4_a_key S4) {
	st_tp_parentNode := (ST_NODE)(nil)
	st_tp_indexNode := *st_ap2_root
	st_tp_insertNode := st_dp_newST_NODE(s4_a_key)

	for st_tp_indexNode != (ST_NODE)(nil) {
		st_tp_parentNode = st_tp_indexNode
		if st_tp_insertNode.s4_key < st_tp_indexNode.s4_key {
			st_tp_indexNode = st_tp_indexNode.st_left
		} else {
			st_tp_indexNode = st_tp_indexNode.st_right
		}
	}
	st_tp_insertNode.st_parent = st_tp_parentNode

	if st_tp_parentNode == (ST_NODE)(nil) {
		*st_ap2_root = st_tp_insertNode
	} else if s4_a_key < st_tp_parentNode.s4_key {
		st_tp_parentNode.st_left = st_tp_insertNode
	} else {
		st_tp_parentNode.st_right = st_tp_insertNode
	}
}

func vd_d_print(st_ap_root ST_NODE) {
	vd_s_printInOrder(st_ap_root)
	fmt.Println()
	vd_s_printPreOrder(st_ap_root)
	fmt.Println()
}

//st_ap_node…探索開始ノード
func vd_s_printPreOrder(st_ap_node ST_NODE) {
	if st_ap_node == (ST_NODE)(nil) {
		return
	}

	fmt.Printf(" %d", st_ap_node.s4_key)
	vd_s_printPreOrder(st_ap_node.st_left)
	vd_s_printPreOrder(st_ap_node.st_right)
}

//st_ap_node…探索開始ノード
func vd_s_printInOrder(st_ap_node ST_NODE) {
	s4_s_printedNumNode := (S4)(0)

	if st_ap_node == (ST_NODE)(nil) {
		return
	}

	vd_s_printInOrder(st_ap_node.st_left)
	fmt.Printf(" %d", st_ap_node.s4_key)
	vd_s_printInOrder(st_ap_node.st_right)
}

//ST_NODEのコンストラクタもどき
func st_dp_newST_NODE(s4_a_key S4) ST_NODE {
	st_tp_node := (ST_NODE)(nil)
	st_tp_node = (ST_NODE)(malloc(sizeof(ST_NODE)))
	st_tp_node.st_parent = (ST_NODE)(nil)
	st_tp_node.st_left = (ST_NODE)(nil)
	st_tp_node.st_right = (ST_NODE)(nil)
	st_tp_node.s4_key = s4_a_key

	return(st_tp_node)
}



Translate the above C code to Java and end with comment "