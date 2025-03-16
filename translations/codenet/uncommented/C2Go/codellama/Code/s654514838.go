#include <stdio.h>
#include <stdlib.h>
#define NIL nil

type Node struct{
	key int
	priority int
	right *Node
	left *Node
}

func Delete(t **Node,key int) *Node
func delete(t **Node,key int) *Node

func find(p *Node,x int) int
{
	for p != NIL{
		if p.key == x{return 1}
		else if p.key > x{p = p.left}
		else{p = p.right}
	}
	return 0
}

func inorder(a *Node)
{
	if a.left != NIL{inorder(a.left)}
	fmt.Printf(" %d",a.key)
	if a.right != NIL{inorder(a.right)}
	return
}

func preorder(p *Node)
{
	fmt.Printf(" %d",p.key)
	if p.left != NIL{preorder(p.left)}
	if p.right != NIL{preorder(p.right)}
	return
}

func print(p *Node)
{
	inorder(p)
	fmt.Println()
	preorder(p)
	fmt.Println()
	return
}

func makenode(x int,y int) *Node
{
	new := &Node{x,y,NIL,NIL}
	return new
}

func rightRotate(p *Node) *Node
{
	q := p.left
	p.left = q.right
	q.right = p
	return q
}

func leftRotate(p *Node) *Node
{
	q := p.right
	p.right = q.left
	q.left = p
	return q
}

func insert(t **Node,key int,priority int) *Node
{
	var new *Node
	if(*t) == NIL{
		return new = makenode(key,priority)
	}
	if(*t).key == key{
		return *t
	}
	
	if key < (*t).key{ // 左の子へ移動
		(*t).left = insert(&(*t).left,key,priority) // 左の子へのポインタを更新
		if(*t).priority < (*t).left.priority{ // 左の子の方が優先度が高い場合右回転
			(*t) = rightRotate(*t)
		}
	}else{ // 右の子へ移動
		(*t).right = insert(&(*t).right,key,priority) // 右の子へのポインタを更新
		if(*t).priority < (*t).right.priority{ // 右の子の方が優先度が高い場合左回転
			(*t) = leftRotate((*t))
		}
	}
	return *t
}

func Delete(t **Node,key int) *Node
{
	if(*t) == NIL{
		return NIL
	}
	
	if key < (*t).key{ // 削除対象を検索
		(*t).left = Delete(&((*t).left),key)
	}else if key > (*t).key{
		(*t).right = Delete(&((*t).right),key)
	}else{
		return delete(t,key)
	}
	return *t
}

func delete(t **Node,key int) *Node
{
	if(*t).left == NIL && (*t).right == NIL{ // 葉の場合
		return NIL
	}else if(*t).left == NIL{ // 右の子のみを持つ場合左回転
		(*t) = leftRotate(*t)
	}else if(*t).right ==NIL{ // 左の子のみを持つ場合右回転
		(*t) = rightRotate(*t)
	}else{ // 左の子と右の子を両方持つ場合
		if(*t).left.priority > (*t).right.priority{ // 優先度が高い方を持ち上げる
			(*t) = rightRotate(*t)
		}else{
			(*t) = leftRotate(*t)
		}
	}
	return Delete(t,key)
}

func main()
{
	var num int
	var x, y int
	var com [8]byte
	var root *Node = NIL
	fmt.Scanf("%d",&num)
	
	for i := 0; i < num; i++{
		fmt.Scanf("%s",com[:])
		switch com[0]{
		  case 'i':fmt.Scanf("%d %d",&x,&y)
			root = insert(&root,x,y)
			break
		  case 'd':fmt.Scanf("%d",&x)
			root = Delete(&root,x)
			break
		  case 'f':fmt.Scanf("%d",&x)
			if find(root,x){fmt.Println("yes")}else{fmt.Println("no")}
			break
		  case 'p':print(root)
			break
		}
	}
	return
}

