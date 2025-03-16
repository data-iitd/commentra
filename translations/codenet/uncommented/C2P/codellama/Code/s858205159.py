#include<stdio.h>
#include<stdlib.h>
#include<string.h>

class Node:
	def __init__(self, key):
		self.key = key
		self.next = None
		self.prev = None

class List:
	def __init__(self):
		self.nil = Node(0)
		self.nil.next = self.nil
		self.nil.prev = self.nil

	def listSearch(self, key):
		cur = self.nil.next
		while cur != self.nil:
			if cur.key == key: break
			cur = cur.next
		return cur

	def printList(self):
		cur = self.nil.next
		isf = 1
		while 1:
			if cur == self.nil: break
			if isf == 0: print(" ", end="")
			print(cur.key, end="")
			cur = cur.next
			isf = 0
		print()

	def deleteNode(self, t):
		if t == self.nil: return
		t.prev.next = t.next
		t.next.prev = t.prev
		del t

	def deleteFirst(self):
		t = self.nil.next
		if t == self.nil: return
		self.deleteNode(t)

	def deleteLast(self):
		t = self.nil.prev
		if t == self.nil: return
		self.deleteNode(t)

	def deleteKey(self, key):
		t = self.listSearch(key)
		if t != self.nil: self.deleteNode(t)

	def insert(self, key):
		x = Node(key)
		x.prev = self.nil
		x.next = self.nil.next
		x.next.prev = x
		self.nil.next = x

	def main(self):
		n = int(input())
		self.init()
		for i in range(n):
			com = input()
			key = int(input())
			if com[0] == 'i': self.insert(key); np++; size++;
			else if com[0] == 'd':
				if len(com) > 6:
					if com[6] == 'F': self.deleteFirst()
					else if com[6] == 'L': self.deleteLast()
				else:
					self.deleteKey(key); nd++;
				size--;
		self.printList()

if __name__ == "__main__":
	np = 0
	nd = 0
	size = 0
	list = List()
	list.main()
	print("