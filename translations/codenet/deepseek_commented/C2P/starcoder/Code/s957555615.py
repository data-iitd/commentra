
#include<stdio.h>
#include<stdlib.h>

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.parent = None

def treeMinimum(x):
    while(x.left!=None):
        x = x.left
    return x

def treeMaximum(x):
    while(x.right!=None):
        x = x.right
    return x

def treeSearch(u, k):
    if(u==None or k==u.key):
        return u
    if(k<u.key):
        return treeSearch(u.left, k)
    else:
        return treeSearch(u.right, k)

def treeSuccessor(x):
    y = None
    if(x.right!=None):
        return treeMinimum(x.right)
    y = x.parent
    while(y!=None and x==y.right):
        x = y
        y = y.parent
    return y

def treeDelete(z):
    y = None
    x = None
    if(z.left==None or z.right==None):
        y = z
    else:
        y = treeSuccessor(z)
    if(y.left!=None):
        x = y.left
    else:
        x = y.right
    if(x!=None):
        x.parent = y.parent
    if(y.parent==None):
        root = x
    else:
        if(y==y.parent.left):
            y.parent.left = x
        else:
            y.parent.right = x
    if(y!=z):
        z.key = y.key

def insert(k):
    y = None
    x = root
    z = Node(k)
    while(x!=None):
        y = x
        if(z.key<x.key):
            x = x.left
        else:
            x = x.right
    z.parent = y
    if(y==None):
        root = z
    else:
        if(z.key<y.key):
            y.left = z
        else:
            y.right = z

def inorder(u):
    if(u==None):
        return
    inorder(u.left)
    print(" %d" % u.key, end="")
    inorder(u.right)

def preorder(u):
    if(u==None):
        return
    print(" %d" % u.key, end="")
    preorder(u.left)
    preorder(u.right)

n = int(input())
for i in range(n):
    com = input()
    if(com[0]=='f'):
        x = int(input())
        t = treeSearch(root, x)
        if(t!=None):
            print("yes\n")
        else:
            print("no\n")
    elif(com[0]=='i'):
        x = int(input())
        insert(x)
    elif(com[0]=='p'):
        inorder(root)
        print("\n")
        preorder(root)
        print("\n")
    elif(com[0]=='d'):
        x = int(input())
        treeDelete(treeSearch(root, x))

#