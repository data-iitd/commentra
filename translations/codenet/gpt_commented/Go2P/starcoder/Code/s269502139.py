# Define a doubly linked list node structure
class node:
	def __init__(self, key):
		self.key = key
		self.prev = None
		self.next = None

# Method to recursively print the keys of the linked list starting from the current node
def rPrint(n, buf):
	buf.write(str(n.key)) # Append the current node's key to the buffer
	if n.next!= None:
		buf.write(" ") # Add a space if there is a next node
		rPrint(n.next, buf)   # Recursively print the next node
	return

# Method to delete the current node from the linked list
def delete(n, first, last):
	if n.prev!= None and n.next!= None:
		# Node is in the middle; update pointers of adjacent nodes
		n.prev.next = n.next
		n.next.prev = n.prev
		return first, last # Return unchanged first and last pointers
	if n.next == None and n.prev == None:
		# Node is the only node in the list
		return None, None # Return nil for both first and last
	if n.prev == None:
		# Node is the first node
		first = n.next # Update first to the next node
		n.next.prev = None # Set the previous pointer of the new first node to nil
	if n.next == None:
		# Node is the last node
		last = n.prev # Update last to the previous node
		n.prev.next = None # Set the next pointer of the new last node to nil
	return first, last # Return updated first and last pointers

# Function to initialize a new node with a given key
def initNode(key):
	return node(key) # Set the key of the new node

# Main function to execute the program
def main():
	stdin = sys.stdin # Create a scanner to read input from standard input
	first = None      # Initialize pointers for the first and last nodes of the list
	last = None
	stdin.readline() # Read the first line of input (not used)

	# Loop to process each command from the input
	for line in stdin:
		cmd = line.strip() # Get the current command
		if cmd == "deleteFirst":
			# Command to delete the first node
			first, last = delete(first, first, last)
		elif cmd == "deleteLast":
			# Command to delete the last node
			first, last = delete(last, first, last)
		else:
			# Handle commands that involve inserting or deleting specific keys
			xcmd = cmd.split(" ") # Split the command into parts
			k = int(xcmd[1])      # Convert the second part to an integer
			if xcmd[0] == "delete":
				# Command to delete a node with a specific key
				for a in first:
					if a.key == k:
						first, last = delete(a, first, last) # Delete the node and update first and last
						break
			elif xcmd[0] == "insert":
				# Command to insert a new node at the beginning of the list
				n = initNode(k) # Initialize a new node
				n.next = first  # Set the new node's next pointer to the current first node
				if first!= None:
					first.prev = n # Update the previous pointer of the current first node
				first = n # Update first to the new node
				if last == None:
					last = n # If the list was empty, set last to the new node
	buf = ""
	rPrint(first, buf) # Print the keys of the linked list starting from the first node
	print(buf) # Output the result

