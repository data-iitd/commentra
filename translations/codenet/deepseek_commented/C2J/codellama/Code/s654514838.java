#include <stdio.h>
#include <stdlib.h>
#define NIL null

class Node{
	int key;
	int priority;
	Node left;
	Node right;
	
	public Node(int x, int y){
		key = x;
		priority = y;
		left = NIL;
		right = NIL;
	}
}

Node Delete(Node t, int key){
	if(t == NIL)
	return NIL;
	
	if(key < t.key) // Search for the node to delete
	t.left = Delete(t.left,key);
	
	else if(key > t.key)
	t.right = Delete(t.right,key);
	
	else return delete(t,key);
	return t;
}

Node delete(Node t, int key){
	if(t.left == NIL && t.right == NIL)  // Case for leaf node
	{
		return NIL;
	}
	else if(t.left == NIL) // Case for node with only right child
	{
		t = leftRotate(t);
	}
	else if(t.right ==NIL) // Case for node with only left child
	{
		t = rightRotate(t);
	}
	else{ // Case for node with both left and right children
		if(t.left.priority > t.right.priority) // Rotate based on higher priority child
		t = rightRotate(t);
		else
		t = leftRotate(t);
	}
	return Delete(t,key);
}

Node leftRotate(Node t){
	Node q = t.left;
	t.left = q.right;
	q.right = t;
	return q;
}

Node rightRotate(Node t){
	Node q = t.right;
	t.right = q.left;
	q.left = t;
	return q;
}

Node insert(Node t, int key, int priority){
	Node new;
	if(t == NIL)
	return new = new Node(key,priority); // Create new node if leaf is reached
	if(t.key == key)
	return t;  // Ignore duplicate keys
	
	if(key < t.key) // Move to left child
	{
		t.left = insert(t.left,key,priority); // Update left child pointer
		if(t.priority < t.left.priority) // Right rotate if left child has higher priority
		t = rightRotate(t);
	}
	else{ // Move to right child
		t.right = insert(t.right,key,priority); // Update right child pointer
		if(t.priority < t.right.priority) // Left rotate if right child has higher priority
		t = leftRotate(t);
	}
	return t;
}

boolean find(Node t, int x){
	while(t != NIL)
	{
		if(t.key == x)return true;
		else if(t.key > x)t = t.left;
		else t = t.right;
	}
	return false;
}

void inorder(Node t){
	if(t.left != NIL) inorder(t.left);
	System.out.print(" " + t.key);
	if(t.right != NIL) inorder(t.right);
	return;
}

void preorder(Node t){
	System.out.print(" " + t.key);
	if(t.left != NIL) preorder(t.left);
	if(t.right != NIL) preorder(t.right);
	return;
}

void print(Node t){
	inorder(t);
	System.out.println();
	preorder(t);
	System.out.println();
	return;
}

public class Main{
	public static void main(String[] args){
		int num ,  x, y;
		String com;
		Node root = NIL;
		scanf("%d",&num);
		
		for(int i = 0; i < num; i++)
		{
			scanf("%s",com);
			switch(com[0])
			{
			  case 'i':scanf("%d %d",&x,&y);
				root = insert(root,x,y);
				break;
			  case 'd':scanf("%d",&x);
				root = Delete(root,x);
				break;
			  case 'f':scanf("%d",&x);
				if(find(root,x))System.out.println("yes");
				else System.out.println("no");
				break;
			  case 'p':print(root);
				break;
			}
		}
		return;
	}
}

