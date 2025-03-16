#include <iostream>
#include <cstdlib>
#define NIL NULL

using namespace std;

struct node{
	int key;
	int priority;
	node *right , *left;
};

node * Delete(node **,int);
node * delete(node **,int);

int find(node *p,int x)
{
	while(p!=NIL)
	{
		if(p->key==x)return 1;
		else if(p->key > x)p = p->left;
		else p = p->right;
	}
	return 0;
}

void inorder(node *a)
{
	if(a->left!=NIL) inorder(a->left);
	cout << " " << a->key;
	if(a->right!=NIL) inorder(a->right);
	return;
}

void preorder(node *p)
{
	cout << " " << p->key;
	if(p->left!=NIL) preorder(p->left);
	if(p->right!=NIL) preorder(p->right);
	return;
}

void print(node *p)
{
	inorder(p);
	cout << endl;
	preorder(p);
	cout << endl;
	return;
}

node * makenode(int x , int y)
{
	node *new = new node;
	new->key = x;
	new->priority = y;
	new->left = NIL;
	new->right = NIL;
	return new;
}

node *rightRotate(node *p)
{
	node *q = p->left;
	p->left = q->right;
	q->right = p;
	return q;
}

node *leftRotate(node *p)
{
	node *q = p->right;
	p->right = q->left;
	q->left = p;
	return q;
}

node* insert(node **t , int key, int priority)  // 再帰的に探索
{
	node *new;
	if((*t)==NIL)
	return new = makenode(key,priority); // 葉に到達したら新しい節点を生成して返す
	if((*t)->key == key)
	return *t;  // 重複したkeyは無視
	
	if(key < (*t)->key) // 左の子へ移動
	{
		(*t)->left = insert(&(*t)->left,key,priority); // 左の子へのポインタを更新
		if((*t)->priority < (*t)->left->priority) // 左の子の方が優先度が高い場合右回転
		(*t) = rightRotate(*t);
	}
	else{ // 右の子へ移動
		(*t)->right = insert(&(*t)->right,key,priority); // 右の子へのポインタを更新
		if((*t)->priority < (*t)->right->priority) // 右の子の方が優先度が高い場合左回転
		(*t) = leftRotate((*t));
	}
	return *t;
}

node * Delete(node **t , int key)
{
	if((*t)==NIL)
	return NIL;
	
	if(key < (*t)->key) // 削除対象を検索
	(*t)->left = Delete(&((*t)->left),key);
	
	else if(key > (*t)->key)
	(*t)->right = Delete(&((*t)->right),key);
	
	else return delete(t,key);
	return *t;
}

node * delete(node **t , int key)
{
	if((*t)->left == NIL && (*t)->right == NIL)  // 葉の場合
	{
		return NIL;
	}
	else if((*t)->left == NIL) // 右の子のみを持つ場合左回転
	{
		(*t) = leftRotate(*t);
	}
	else if((*t)->right ==NIL) // 左の子のみを持つ場合右回転
	{
		(*t) = rightRotate(*t);
	}
	else{ // 左の子と右の子を両方持つ場合
		if((*t)->left->priority > (*t)->right->priority) // 優先度が高い方を持ち上げる
		(*t) = rightRotate(*t);
		else
		(*t) = leftRotate(*t);
	}
	return Delete(t,key);
}

int main(void)
{
	int num ,  x, y;
	char com[8];
	node *root = NIL;
	cin >> num;
	
	for(int i = 0; i < num; i++)
	{
		cin >> com;
		switch(com[0])
		{
		  case 'i':cin >> x >> y;
			root = insert(&root,x,y);
			break;
		  case 'd':cin >> x;
			root = Delete(&root,x);
			break;
		  case 'f':cin >> x;
			if(find(root,x))cout << "yes" << endl;
			else cout << "no" << endl;
			break;
		  case 'p':print(root);
			break;
		}
	}
	return 0;
}

