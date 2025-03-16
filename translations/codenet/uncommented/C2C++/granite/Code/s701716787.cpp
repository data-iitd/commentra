
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define COMMAND_LENGTH     (10)   /* コ맨드의 문자수 */

struct ST_NODE
{
    ST_NODE* st_parent;
    ST_NODE* st_left;
    ST_NODE* st_right;
    int s4_key;
};

void vd_d_insert(ST_NODE**, int);
void vd_d_print(ST_NODE*);
static void vd_s_printPreOrder(ST_NODE*);
static void vd_s_printInOrder(ST_NODE*);
ST_NODE* st_dp_newST_NODE(int);

int main()
{
    ST_NODE* st_tp_root;
    int s4_t_numCommand;
    int s4_t_iCommand;
    char s1_tp_command[COMMAND_LENGTH];
    int s4_t_insertKey;
    int s4_t_RtnStrcmp;

    st_tp_root = (ST_NODE*)NULL;

    //명령수
    cin >> s4_t_numCommand;

    //명령 수행
    for (s4_t_iCommand = 0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++)
    {
        //TODO commands other than insert and print are not supported
        //명령(insert or print)
        cin >> s1_tp_command;

        //명령의 실행
        //isert와printf와는 다르게 insert, print만 있다고 가정
        //명령의 유형에 따라 else if문을 추가할 수 있다.
        s4_t_RtnStrcmp = strcmp(s1_tp_command, "insert");
        if (s4_t_RtnStrcmp == 0)
        {
            //insert라면 키의 값을 가져온다.
            cin >> s4_t_insertKey;
            vd_d_insert(&st_tp_root, s4_t_insertKey);
        }
        else
        {
            vd_d_print(st_tp_root);
        }
    }

    return 0;
}

void vd_d_insert(ST_NODE** st_ap2_root, int s4_a_key)
{
    ST_NODE* st_tp_parentNode;
    ST_NODE* st_tp_indexNode;
    ST_NODE* st_tp_insertNode;

    st_tp_insertNode = st_dp_newST_NODE(s4_a_key);

    st_tp_parentNode = (ST_NODE*)NULL;
    st_tp_indexNode = *st_ap2_root;

    while (st_tp_indexNode!= (ST_NODE*)NULL)
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

    if (st_tp_parentNode == (ST_NODE*)NULL)
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

void vd_d_print(ST_NODE* st_ap_root)
{
    vd_s_printInOrder(st_ap_root);
    cout << endl;
    vd_s_printPreOrder(st_ap_root);
    cout << endl;
}

//st_ap_node… exploration start node
static void vd_s_printPreOrder(ST_NODE* st_ap_node)
{
    if (st_ap_node == (ST_NODE*)NULL)
    {
        return;
    }

    cout << " " << st_ap_node->s4_key;
    vd_s_printPreOrder(st_ap_node->st_left);
    vd_s_printPreOrder(st_ap_node->st_right);
}

//st_ap_node… exploration start node
static void vd_s_printInOrder(ST_NODE* st_ap_node)
{
    static int s4_s_printedNumNode = 0;

    if (st_ap_node == (ST_NODE*)NULL)
    {
        return;
    }

    vd_s_printInOrder(st_ap_node->st_left);
    cout << " " << st_ap_node->s4_key;
    vd_s_printInOrder(st_ap_node->st_right);
}

//ST_NODEのコンストラクタもどき
ST_NODE* st_dp_newST_NODE(int s4_a_key)
{
    ST_NODE* st_tp_node;
    st_tp_node = (ST_NODE*)malloc(sizeof(ST_NODE));
    st_tp_node->st_parent = (ST_NODE*)NULL;
    st_tp_node->st_left = (ST_NODE*)NULL;
    st_tp_node->st_right = (ST_NODE*)NULL;
    st_tp_node->s4_key = s4_a_key;

    return st_tp_node;
}

//