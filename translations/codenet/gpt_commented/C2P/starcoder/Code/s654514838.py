#include <stdio.h>
#include <stdlib.h>
#define NIL None

# Node structure for the treap
class Node:
	def __init__(self,key,priority):
		self.key = key
		self.priority = priority
		self.left = NIL
		self.right = NIL

# Function prototypes for delete operations
def Delete(t,key):
	if(t == NIL):
		return NIL;
	if(key < t.key):
		t.left = Delete(t.left,key);
	elif(key > t.key):
		t.right = Delete(t.right,key);
	else:
		return delete(t,key);
	return t;

# Helper function to handle the actual deletion of a node
def delete(t,key):
	if(t.left == NIL and t.right == NIL):
		return NIL;
	elif(t.left == NIL):
		t = leftRotate(t);
	elif(t.right == NIL):
		t = rightRotate(t);
	else:
		if(t.left.priority > t.right.priority):
			t = rightRotate(t);
		else:
			t = leftRotate(t);
	return Delete(t,key);

# Function to perform a right rotation on the treap
def rightRotate(t):
	q = t.left;
	t.left = q.right;
	q.right = t;
	return q;

# Function to perform a left rotation on the treap
def leftRotate(t):
	q = t.right;
	t.right = q.left;
	q.left = t;
	return q;

# Function to insert a new node into the treap
def insert(t,key,priority):
	if(t == NIL):
		return Node(key,priority);
	if(t.key == key):
		return t;
	if(key < t.key):
		t.left = insert(t.left,key,priority);
		if(t.priority < t.left.priority):
			t = rightRotate(t);
	else:
		t.right = insert(t.right,key,priority);
		if(t.priority < t.right.priority):
			t = leftRotate(t);
	return t;

# Function to find a key in the treap
def find(t,x):
	while(t!= NIL):
		if(t.key == x):
			return 1;
		elif(t.key > x):
			t = t.left;
		else:
			t = t.right;
	return 0;

# Function for inorder traversal of the treap
def inorder(t):
	if(t.left!= NIL):
		inorder(t.left);
	print(" %d",t.key);
	if(t.right!= NIL):
		inorder(t.right);
	return;

# Function for preorder traversal of the treap
def preorder(t):
	print(" %d",t.key);
	if(t.left!= NIL):
		preorder(t.left);
	if(t.right!= NIL):
		preorder(t.right);
	return;

# Function to print the treap in both inorder and preorder
def print(t):
	inorder(t);
	print("\n");
	preorder(t);
	print("\n");
	return;

# Main function to execute the program
def main():
	num,  x, y;
	com = [0] * 8;
	scanf("%d",&num);
	for(int i = 0; i < num; i++)
	{
		scanf("%s",com);
		switch(com[0])
		{
		  case 'i':
			scanf("%d %d",&x,&y);
			root = insert(root,x,y);
			break;
		  case 'd':
			scanf("%d",&x);
			root = Delete(root,x);
			break;
		  case 'f':
			scanf("%d",&x);
			if(find(root,x)) printf("yes\n");
			else printf("no\n");
			break;
		  case 'p':
			print(root);
			break;
		}
	}
	return 0;
}

