#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define nil None

class Node:
	def __init__(self, key):
		self.key = key
		self.next = nil
		self.prev = nil

def listSearch(key):
	cur = nil.next
	while cur != nil:
		if cur.key == key:
			break
		cur = cur.next
	return cur

def init():
	nil = Node(0)
	nil.next = nil
	nil.prev = nil

def printList():
	cur = nil.next
	isf = 1
	while 1:
		if cur == nil:
			break
		if isf == 0:
			print(" ", end="")
		print(cur.key, end="")
		cur = cur.next
		isf = 0
	print()

def deleteNode(t):
	if t == nil:
		return
	t.prev.next = t.next
	t.next.prev = t.prev
	del t

def deleteFirst():
	t = nil.next
	if t == nil:
		return
	deleteNode(t)

def deleteLast():
	t = nil.prev
	if t == nil:
		return
	deleteNode(t)

def deleteKey(key):
	t = listSearch(key)
	if t != nil:
		deleteNode(t)

def insert(key):
	x = Node(key)
	x.prev = nil
	x.next = nil.next
	x.next.prev = x
	nil.next = x

def main():
	n = int(input())
	init()
	for i in range(n):
		com = input().split()
		if com[0] == 'i':
			insert(int(com[1]))
		elif com[0] == 'd':
			if len(com) > 6:
				if com[6] == 'F':
					deleteFirst()
				elif com[6] == 'L':
					deleteLast()
			else:
				deleteKey(int(com[1]))
	printList()

if __name__ == "__main__":
	main()

