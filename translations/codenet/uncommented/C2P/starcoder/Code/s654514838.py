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
	while p!= NIL:
		if p.key == x:
			return 1
		elif p.key > x:
			p = p.left
		else:
			p = p.right
	return 0

def inorder(a):
	if a.left!= NIL:
		inorder(a.left)
	print(" %d" % a.key)
	if a.right!= NIL:
		inorder(a.right)
	return

def preorder(p):
	print(" %d" % p.key)
	if p.left!= NIL:
		preorder(p.left)
	if p.right!= NIL:
		preorder(p.right)
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
	if t == NIL:
		return new
	if t.key == key:
		return t
	if key < t.key:
		t.left = insert(t.left,key,priority)
		if t.priority < t.left.priority:
			t = rightRotate(t)
	else:
		t.right = insert(t.right,key,priority)
		if t.priority < t.right.priority:
			t = leftRotate(t)
	return t

def Delete(t,key):
	if t == NIL:
		return NIL
	if key < t.key:
		t.left = Delete(t.left,key)
	elif key > t.key:
		t.right = Delete(t.right,key)
	else:
		return delete(t,key)
	return t

def delete(t,key):
	if t.left == NIL and t.right == NIL:
		return NIL
	elif t.left == NIL:
		t = leftRotate(t)
	elif t.right == NIL:
		t = rightRotate(t)
	else:
		if t.left.priority > t.right.priority:
			t = rightRotate(t)
		else:
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
		  case 'i':scanf("%d %d",&x,&y);
			root = insert(root,x,y);
			break;
		  case 'd':scanf("%d",&x);
			root = Delete(root,x);
			break;
		  case 'f':scanf("%d",&x);
			if(find(root,x))printf("yes\n");
			else printf("no\n");
			break;
		  case 'p':print(root);
			break;
		}
	return 0;
}

