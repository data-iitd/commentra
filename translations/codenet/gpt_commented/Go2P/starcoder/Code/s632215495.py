# Define a structure for a node in the binary tree
class node:
	def __init__(self, key):
		self.key = key
		self.parent = None
		self.left = None
		self.right = None

# Define a structure for the binary tree
class tree:
	def __init__(self):
		self.root = None

	# Insert a new key into the binary tree
	def insert(self, key):
		# If the tree is empty, create a new root node
		if self.root == None:
			self.root = node(key)
			return

		currentNode = self.root
		# Traverse the tree to find the correct position for the new key
		while currentNode!= None:
			if currentNode.key < key:
				currentNode = currentNode.right # Move to the right child
			else:
				currentNode = currentNode.left # Move to the left child

		# Create a new node for the key and set its parent
		newNode = node(key)
		newNode.parent = currentNode.parent
		# Attach the new node to the correct position in the tree
		if currentNode.parent == None:
			self.root = newNode # Insert as root node
		elif currentNode.parent.key < key:
			currentNode.parent.right = newNode # Insert as right child
		else:
			currentNode.parent.left = newNode # Insert as left child

	# Print the keys in the tree in both inorder and preorder traversal
	def print(self):
		# Check if the tree is empty
		if self.root == None:
			print("")
			print("")
		else:
			# Print inorder traversal
			print(" " + " ".join(map(str, self.visitInorder(self.root))))
			# Print preorder traversal
			print(" " + " ".join(map(str, self.visitPreorder(self.root))))

	# Perform a preorder traversal of the tree
	def visitPreorder(self, node):
		if node == None:
			return [] # Return an empty list if node is nil
		acc = [node.key] # Add the current node's key
		if node.left!= None:
			acc = acc + self.visitPreorder(node.left) # Traverse left subtree
		if node.right!= None:
			acc = acc + self.visitPreorder(node.right) # Traverse right subtree
		return acc

	# Perform an inorder traversal of the tree
	def visitInorder(self, node):
		if node == None:
			return [] # Return an empty list if node is nil
		if node.left!= None:
			acc = self.visitInorder(node.left) # Traverse left subtree
		acc = acc + [node.key] # Add the current node's key
		if node.right!= None:
			acc = acc + self.visitInorder(node.right) # Traverse right subtree
		return acc

# Main function to read commands and manipulate the binary tree
def main():
	sc = bufio.NewScanner(sys.stdin) # Create a new scanner for standard input
	sc.Split(bufio.ScanWords)          # Split input into words

	n, err = nextInt(sc) # Read the number of commands
	if err!= None:
		raise(err) # Handle error if reading fails

	tree = tree() # Initialize a new binary tree
	# Process each command
	for i in range(n):
		command = nextText(sc) # Read the command
		if command == "insert":
			key, err = nextInt(sc) # Read the key to insert
			if err!= None:
				raise(err) # Handle error if reading fails
			tree.insert(key) # Insert the key into the tree
		elif command == "print":
			tree.print() # Print the tree's keys
		else:
			raise("unknown command: " + command) # Handle unknown commands

# Read the next text input from the scanner
def nextText(sc):
	sc.Scan() # Scan the next token
	return sc.Text() # Return the scanned text

# Read the next integer input from the scanner
def nextInt(sc):
	return int(nextText(sc)) # Convert the scanned text to an integer

