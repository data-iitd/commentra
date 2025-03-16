#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define U1 unsigned char
#define S1 char
#define	S4 int
#define DU double
#define VD void

#define COMMAND_LENGTH     (10)   # コマンドの文字数

class ST_NODE:
	def __init__(self, s4_key):
		self.st_parent = None
		self.st_left = None
		self.st_right = None
		self.s4_key = s4_key

def vd_d_insert(st_ap2_root, s4_a_key):
	st_tp_parentNode = None
	st_tp_indexNode = st_ap2_root
	st_tp_insertNode = ST_NODE(s4_a_key)

	while st_tp_indexNode!= None:
		st_tp_parentNode = st_tp_indexNode
		if st_tp_insertNode.s4_key < st_tp_indexNode.s4_key:
			st_tp_indexNode = st_tp_indexNode.st_left
		else:
			st_tp_indexNode = st_tp_indexNode.st_right

	st_tp_insertNode.st_parent = st_tp_parentNode

	if st_tp_parentNode == None:
		st_ap2_root = st_tp_insertNode
	else:
		if s4_a_key < st_tp_parentNode.s4_key:
			st_tp_parentNode.st_left = st_tp_insertNode
		else:
			st_tp_parentNode.st_right = st_tp_insertNode

def vd_d_print(st_ap_root):
	vd_s_printInOrder(st_ap_root)
	print()
	vd_s_printPreOrder(st_ap_root)
	print()

#st_ap_node…探索開始ノード
def vd_s_printPreOrder(st_ap_node):
	if st_ap_node == None:
		return

	print(" %d" % st_ap_node.s4_key, end="")
	vd_s_printPreOrder(st_ap_node.st_left)
	vd_s_printPreOrder(st_ap_node.st_right)

#st_ap_node…探索開始ノード
def vd_s_printInOrder(st_ap_node):
	global s4_s_printedNumNode

	if st_ap_node == None:
		return

	vd_s_printInOrder(st_ap_node.st_left)
	print(" %d" % st_ap_node.s4_key, end="")
	vd_s_printInOrder(st_ap_node.st_right)

#ST_NODEのコンストラクタもどき
def st_dp_newST_NODE(s4_a_key):
	st_tp_node = ST_NODE(s4_a_key)
	st_tp_node.st_parent = None
	st_tp_node.st_left = None
	st_tp_node.st_right = None
	return(st_tp_node)

if __name__ == "__main__":
	st_tp_root = None
	s4_t_numCommand = 0
	s4_t_iCommand = 0
	s1_tp_command = [0] * COMMAND_LENGTH
	s4_t_insertKey = 0
	s4_t_RtnStrcmp = 0

	#命令数
	s4_t_numCommand = int(input())

	#コマンド実行
	for s4_t_iCommand in range(s4_t_numCommand):
		#TODO コマンドにより引数が異なる問題
		#コマンド(insert or print)
		s1_tp_command = input().split()

		#コマンドの実行
		#isertとprintfしか入力されない前提で作成
		#コマンドの種類を増やす場合、print用のelse if文を追加すること。
		s4_t_RtnStrcmp = strcmp(s1_tp_command[0], "insert")
		if s4_t_RtnStrcmp == 0:
			#insertならキーの値を取得
			s4_t_insertKey = int(input())
			vd_d_insert(st_tp_root, s4_t_insertKey)
		else:
			vd_d_print(st_tp_root)

