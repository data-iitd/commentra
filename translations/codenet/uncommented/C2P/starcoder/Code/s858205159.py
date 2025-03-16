
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
		self.size = 0

	def search(self, key):
		cur = self.nil.next
		while (cur!= self.nil):
			if (cur.key == key):
				return cur
			cur = cur.next
		return None

	def printList(self):
		cur = self.nil.next
		isf = 1
		while (1):
			if (cur == self.nil):
				break
			if (isf == 0):
				print(" ", end="")
			print(cur.key, end="")
			cur = cur.next
			isf = 0
		print("\n")

	def deleteNode(self, t):
		if (t == self.nil):
			return
		t.prev.next = t.next
		t.next.prev = t.prev
		del t

	def deleteFirst(self):
		t = self.nil.next
		if (t == self.nil):
			return
		self.deleteNode(t)

	def deleteLast(self):
		t = self.nil.prev
		if (t == self.nil):
			return
		self.deleteNode(t)

	def deleteKey(self, key):
		t = self.search(key)
		if (t!= None):
			self.deleteNode(t)

	def insert(self, key):
		x = Node(key)
		x.prev = self.nil
		x.next = self.nil.next
		x.next.prev = x
		self.nil.next = x
		self.size += 1

	def run(self):
		n, key, i
		com = [0] * 20
		np = 0
		nd = 0
		scanf("%d", &n)
		for (i = 0; i < n; i++){
			scanf("%s%d", com, &key)
			if (com[0] == 'i'):
				self.insert(key)
				np += 1
				self.size += 1
			else if (com[0] == 'd'):
				if (strlen(com) > 6):
					if (com[6] == 'F'):
						self.deleteFirst()
					else if (com[6] == 'L'):
						self.deleteLast()
				else:
					self.deleteKey(key)
					nd += 1
				self.size -= 1
		}
		self.printList()
		return 0

if __name__ == "__main__":
	l = List()
	l.run()

