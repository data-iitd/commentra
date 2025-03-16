#include <stdio.h>
#include <stdlib.h>
#define NIL None

class Node:
	def __init__(self,key,priority):
		self.key = key
		self.priority = priority
		self.left = NIL
		self.right = NIL

def find(p,x):
	while(p!=NIL):
		if(p.key==x):return 1
		elif(p.key > x):p = p.left
		else p = p.right
	return 0

def inorder(a):
	if(a.left!=NIL) inorder(a.left)
	print(" %d",a.key)
	if(a.right!=NIL) inorder(a.right)
	return

def preorder(p):
	print(" %d",p.key)
	if(p.left!=NIL) preorder(p.left)
	if(p.right!=NIL) preorder(p.right)
	return

def print(p):
	inorder(p)
	print("\n")
	preorder(p)
	print("\n")
	return

def makenode(x,y):
	new = Node(x,y)
	new.left = NIL
	new.right = NIL
	return new

def rightRotate(p):
	q = p.left
	p.left = q.right
	q.right = p
	return q

def leftRotate(p):
	q = p.right
	p.right = q.left
	q.left = p
	return q

def insert(t,key,priority):
	new = makenode(key,priority)
	if(t==NIL):return new
	if(t.key == key):return t  # Ignore duplicate keys
	
	if(key < t.key): # Move to left child
		t.left = insert(t.left,key,priority) # Update left child pointer
		if(t.priority < t.left.priority): # Right rotate if left child has higher priority
			t = rightRotate(t)
	else: # Move to right child
		t.right = insert(t.right,key,priority) # Update right child pointer
		if(t.priority < t.right.priority): # Left rotate if right child has higher priority
			t = leftRotate(t)
	return t

def Delete(t,key):
	if(t==NIL):return NIL
	if(key < t.key): # Search for the node to delete
		t.left = Delete(t.left,key)
	elif(key > t.key):
		t.right = Delete(t.right,key)
	else return delete(t,key)
	return t

def delete(t,key):
	if(t.left == NIL and t.right == NIL):  # Case for leaf node
		return NIL
	elif(t.left == NIL): # Case for node with only right child
		t = leftRotate(t)
	elif(t.right ==NIL): # Case for node with only left child
		t = rightRotate(t)
	else: # Case for node with both left and right children
		if(t.left.priority > t.right.priority): # Rotate based on higher priority child
			t = rightRotate(t)
		else
			t = leftRotate(t)
	return Delete(t,key)

def main():
	num,  x, y
	com = [0] * 8
	root = NIL
	scanf("%d",&num)
	
	for i in range(num):
		scanf("%s",com)
		switch(com[0])
		{
		  case 'i':scanf("%d %d",&x,&y)
			root = insert(root,x,y)
			break
		  case 'd':scanf("%d",&x)
			root = Delete(root,x)
			break
		  case 'f':scanf("%d",&x)
			if(find(root,x))printf("yes\n")
			else printf("no\n")
			break
		  case 'p':print(root)
			break
		}
	return 0

main()
#