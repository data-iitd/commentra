#include <stdio.h>
#include <stdlib.h>
#define NIL nil

type Node struct{
	key int
	priority int
	right *Node
	left *Node
}

func Delete(t **Node,x int) *Node
func delete(t **Node,x int) *Node

// This function searches for a key in the tree. Returns 1 if found, otherwise 0.
func find(p *Node,x int) int
{
	for p!=NIL
	{
		if p.key==x return 1
		else if p.key > x p = p.left
		else p = p.right
	}
	return 0
}

// This function performs an inorder traversal of the tree and prints the keys.
func inorder(a *Node)
{
	if a.left!=NIL inorder(a.left)
	fmt.Printf(" %d",a.key)
	if a.right!=NIL inorder(a.right)
	return
}

// This function performs a preorder traversal of the tree and prints the keys.
func preorder(p *Node)
{
	fmt.Printf(" %d",p.key)
	if p.left!=NIL preorder(p.left)
	if p.right!=NIL preorder(p.right)
	return
}

// This function prints the tree in both inorder and preorder traversal formats.
func print(p *Node)
{
	inorder(p)
	fmt.Println()
	preorder(p)
	fmt.Println()
	return
}

// This function creates a new node with given key and priority.
func makenode(x int,y int) *Node
{
	new := &Node{key:x,priority:y,left:NIL,right:NIL}
	return new
}

// This function performs a right rotation on the given node.
func rightRotate(p *Node) *Node
{
	q := p.left
	p.left = q.right
	q.right = p
	return q
}

// This function performs a left rotation on the given node.
func leftRotate(p *Node) *Node
{
	q := p.right
	p.right = q.left
	q.left = p
	return q
}

// This function inserts a new node into the tree while maintaining the heap property using rotations.
func insert(t **Node,key int,priority int) *Node  // Recursive search
{
	var new *Node
	if(*t)==NIL
	return new = makenode(key,priority) // Create new node if leaf is reached
	if(*t).key == key
	return *t // Ignore duplicate keys
	
	if key < (*t).key // Move to left child
	{
		(*t).left = insert(&(*t).left,key,priority) // Update left child pointer
		if(*t).priority < (*t).left.priority // Right rotate if left child has higher priority
		(*t) = rightRotate(*t)
	}
	else{ // Move to right child
		(*t).right = insert(&(*t).right,key,priority) // Update right child pointer
		if(*t).priority < (*t).right.priority // Left rotate if right child has higher priority
		(*t) = leftRotate((*t))
	}
	return *t
}

// This function initiates the deletion process and calls `delete` for actual deletion.
func Delete(t **Node,x int) *Node
{
	if(*t)==NIL
	return NIL
	
	if x < (*t).key // Search for the node to delete
	(*t).left = Delete(&((*t).left),x)
	
	else if x > (*t).key
	(*t).right = Delete(&((*t).right),x)
	
	else return delete(t,x)
	return *t
}

// This function handles the actual deletion of nodes, including cases where the node has one or two children.
func delete(t **Node,x int) *Node
{
	if(*t).left == NIL && (*t).right == NIL  // Case for leaf node
	{
		return NIL
	}
	else if(*t).left == NIL // Case for node with only right child
	{
		(*t) = leftRotate(*t)
	}
	else if(*t).right ==NIL // Case for node with only left child
	{
		(*t) = rightRotate(*t)
	}
	else{ // Case for node with both left and right children
		if(*t).left.priority > (*t).right.priority // Rotate based on higher priority child
		(*t) = rightRotate(*t)
		else
		(*t) = leftRotate(*t)
	}
	return Delete(t,x)
}

// Entry point of the program. Reads commands to insert, delete, find, or print the tree.
func main()
{
	var num ,  x, y int
	var com string
	root := NIL
	fmt.Scanf("%d",&num)
	
	for i := 0; i < num; i++
	{
		fmt.Scanf("%s",&com)
		switch com[0]
		{
		  case 'i':fmt.Scanf("%d %d",&x,&y)
			root = insert(&root,x,y)
			break
		  case 'd':fmt.Scanf("%d",&x)
			root = Delete(&root,x)
			break
		  case 'f':fmt.Scanf("%d",&x)
			if find(root,x)==1 fmt.Println("yes")
			else fmt.Println("no")
			break
		  case 'p':print(root)
			break
		}
	}
	return
}

