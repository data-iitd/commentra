#include <stdio.h>
#include <stdlib.h>
#define NIL None

# Definition of the node structure for the treap
class Node:
    def __init__(self, key, priority):
        self.key = key
        self.priority = priority
        self.right = NIL
        self.left = NIL

# Function prototypes for delete operations
def Delete(t, x):
    if t is NIL:
        return NIL
    if x < t.key:
        t.left = Delete(t.left, x)
        if t.priority < t.left.priority:
            t = rightRotate(t)
    elif x > t.key:
        t.right = Delete(t.right, x)
        if t.priority < t.right.priority:
            t = leftRotate(t)
    else:
        return delete(t, x)
    return t

def delete(t, x):
    if t.left is NIL and t.right is NIL:
        return NIL
    elif t.left is NIL:
        t = leftRotate(t)
    elif t.right is NIL:
        t = rightRotate(t)
    else:
        if t.left.priority > t.right.priority:
            t = rightRotate(t)
        else:
            t = leftRotate(t)
    return Delete(t, x)

# Function to find a key in the treap
def find(p, x):
    while p is not NIL:
        if p.key == x:
            return 1
        elif p.key > x:
            p = p.left
        else:
            p = p.right
    return 0

# Function for inorder traversal of the treap
def inorder(a):
    if a.left is not NIL:
        inorder(a.left)
    print(a.key, end=" ")
    if a.right is not NIL:
        inorder(a.right)

# Function for preorder traversal of the treap
def preorder(p):
    print(p.key, end=" ")
    if p.left is not NIL:
        preorder(p.left)
    if p.right is not NIL:
        preorder(p.right)

# Function to print the treap in both inorder and preorder
def print(p):
    inorder(p)
    print()
    preorder(p)
    print()

# Function to create a new node with given key and priority
def makenode(x, y):
    new = Node(x, y)
    new.left = NIL
    new.right = NIL
    return new

# Function to perform a right rotation on the treap
def rightRotate(p):
    q = p.left
    p.left = q.right
    q.right = p
    return q

# Function to perform a left rotation on the treap
def leftRotate(p):
    q = p.right
    p.right = q.left
    q.left = p
    return q

# Function to insert a new node into the treap
def insert(t, key, priority):
    if t is NIL:
        return makenode(key, priority)
    if key == t.key:
        return t
    if key < t.key:
        t.left = insert(t.left, key, priority)
        if t.priority < t.left.priority:
            t = rightRotate(t)
    else:
        t.right = insert(t.right, key, priority)
        if t.priority < t.right.priority:
            t = leftRotate(t)
    return t

# Main function to execute the program
def main():
    num = int(input())
    for i in range(num):
        com = input()
        if com[0] == 'i':
            x, y = map(int, input().split())
            root = insert(root, x, y)
        elif com[0] == 'd':
            x = int(input())
            root = Delete(root, x)
        elif com[0] == 'f':
            x = int(input())
            if find(root, x):
                print("yes")
            else:
                print("no")
        elif com[0] == 'p':
            print(root)

if __name__ == "__main__":
    main()

