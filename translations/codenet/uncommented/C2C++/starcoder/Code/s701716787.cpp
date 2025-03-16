#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define COMMAND_LENGTH     (10)   /* 命令の文字数 */

using namespace std;

struct st_node
{
	st_node* st_parent;
	st_node* st_left;
	st_node* st_right;
	int s4_key;
};

void vd_d_insert(st_node** st_ap2_root, int s4_a_key);
void vd_d_print(st_node* st_ap_root);
void vd_s_printPreOrder(st_node* st_ap_node);
void vd_s_printInOrder(st_node* st_ap_node);
st_node* st_dp_newST_NODE(int s4_a_key);

int main()
{
	st_node* st_tp_root;
	int s4_t_numCommand;
	int s4_t_iCommand;
	char s1_tp_command[COMMAND_LENGTH];
	int s4_t_insertKey;
	int s4_t_RtnStrcmp;

	st_tp_root = (st_node*)NULL;

	//命令数
	cin >> s4_t_numCommand;

	//コマンド実行
	for (s4_t_iCommand = (int)0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++)
	{
		//TODO コマンドにより引数が異なる問題
		//コマンド(insert or print)
		cin >> s1_tp_command;

		//コマンドの実行
		//isertとprintfしか入力されない前提で作成
		//コマンドの種類を増やす場合、print用のelse if文を追加すること。
		s4_t_RtnStrcmp = (int)strcmp(s1_tp_command, "insert");
		if (s4_t_RtnStrcmp == (int)0)
		{
			//insertならキーの値を取得
			cin >> s4_t_insertKey;
			vd_d_insert(&st_tp_root, s4_t_insertKey);
		}
		else
		{
			vd_d_print(st_tp_root);
		}
	}

	return((int)0);
}


void vd_d_insert(st_node** st_ap2_root, int s4_a_key)
{
	st_node* st_tp_parentNode;
	st_node* st_tp_indexNode;
	st_node* st_tp_insertNode;

	st_tp_insertNode = st_dp_newST_NODE(s4_a_key);

	st_tp_parentNode = (st_node*)NULL;
	st_tp_indexNode = *st_ap2_root;

	while (st_tp_indexNode!= (st_node*)NULL)
	{
		st_tp_parentNode = st_tp_indexNode;
		if (st_tp_insertNode->s4_key < st_tp_indexNode->s4_key)
		{
			st_tp_indexNode = st_tp_indexNode->st_left;
		}
		else
		{
			st_tp_indexNode = st_tp_indexNode->st_right;
		}
	}
	st_tp_insertNode->st_parent = st_tp_parentNode;

	if (st_tp_parentNode == (st_node*)NULL)
	{
		*st_ap2_root = st_tp_insertNode;
	}
	else if (s4_a_key < st_tp_parentNode->s4_key)
	{
		st_tp_parentNode->st_left = st_tp_insertNode;
	}
	else
	{
		st_tp_parentNode->st_right = st_tp_insertNode;
	}
}

void vd_d_print(st_node* st_ap_root)
{
	vd_s_printInOrder(st_ap_root);
	cout << endl;
	vd_s_printPreOrder(st_ap_root);
	cout << endl;
}

//st_ap_node…探索開始ノード
void vd_s_printPreOrder(st_node* st_ap_node)
{
	if (st_ap_node == (st_node*)NULL)
	{
		return;
	}

	cout << " " << st_ap_node->s4_key;
	vd_s_printPreOrder(st_ap_node->st_left);
	vd_s_printPreOrder(st_ap_node->st_right);
}

//st_ap_node…探索開始ノード
void vd_s_printInOrder(st_node* st_ap_node)
{
	static int s4_s_printedNumNode = (int)0;

	if (st_ap_node == (st_node*)NULL)
	{
		return;
	}

	vd_s_printInOrder(st_ap_node->st_left);
	cout << " " << st_ap_node->s4_key;
	vd_s_printInOrder(st_ap_node->st_right);
}

//ST_NODEのコンストラクタもどき
st_node* st_dp_newST_NODE(int s4_a_key)
{
	st_node* st_tp_node;
	st_tp_node = (st_node*)malloc(sizeof(st_node));
	st_tp_node->st_parent = (st_node*)NULL;
	st_tp_node->st_left = (st_node*)NULL;
	st_tp_node->st_right = (st_node*)NULL;
	st_tp_node->s4_key = s4_a_key;

	return(st_tp_node);
}

