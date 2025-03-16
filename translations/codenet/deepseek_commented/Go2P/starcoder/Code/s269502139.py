
# Define the `node` structure
# This structure represents a node in a doubly linked list.
# It contains an integer key, and pointers to the previous and next nodes.
class node:
	def __init__(self, key):
		self.key = key
		self.prev = None
		self.next = None

# Recursive Print Function
# The `rPrint` method prints the keys of the nodes in the list from the current node to the last node.
	def rPrint(self, buf):
		buf.write(str(self.key))
		if self.next!= None:
			buf.write(" ")
			self.next.rPrint(buf)
		return

# Delete Method
# The `Delete` method removes the current node from the list and adjusts the pointers of the surrounding nodes.
	def Delete(self, first, last):
		if self.prev!= None and self.next!= None:
			#swap
			self.prev.next = self.next
			self.next.prev = self.prev
			return first, last
		if self.next == None and self.prev == None:
			return None, None
		if self.prev == None:
			first = self.next
			self.next.prev = None
		if self.next == None:
			last = self.prev
			self.prev.next = None
		return first, last

# Node Initialization
# The `initNode` function creates a new node with the given key.
def initNode(key):
	return node(key)

# Main Function
# The main function reads commands from standard input, performs operations on the doubly linked list, and prints the final list.
def main():
	stdin = bufio.NewScanner(os.Stdin)
	first = None
	last = None
	stdin.Scan()

	for stdin.Scan():
		cmd = stdin.Text()
		if cmd == "deleteFirst":
			first, last = first.Delete(first, last)
		elif cmd == "deleteLast":
			first, last = last.Delete(first, last)
		else:
			xcmd = cmd.split(" ")
			k = int(xcmd[1])
			if xcmd[0] == "delete":
				for a in first:
					if a.key == k:
						first, last = a.Delete(first, last)
						break
			elif xcmd[0] == "insert":
				n = initNode(k)
				n.next = first
				if first!= None:
					first.prev = n
				first = n
				if last == None:
					last = n
	buf = ""
	first.rPrint(buf)
	print(buf)

