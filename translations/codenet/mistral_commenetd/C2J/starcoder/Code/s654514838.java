
// Define a structure for a node in the AVL tree
class Node {
	int key;      // The key value of the node
	int priority; // The priority value of the node
	Node left, right; // Pointers to the left and right children
}

// Function to delete a node from the AVL tree
Node Delete(Node t, int key)
{
	// If the tree is empty, do nothing
	if (t == null) return null;
	// Recursively search for the node to delete
	if (key < t.key) t.left = Delete(t.left, key);
	else if (key > t.key) t.right = Delete(t.right, key);
	// If the node to be deleted was found, delete it and update the tree
	else {
		Node q = t;
		t = delete(t, key);
		q = null;
	}
	// If the deleted node was a rotated node, check if the tree needs to be rotated
	if (t.priority < t.left.priority || t.priority < t.right.priority) {
		// Perform a right rotation if the left child has a higher priority
		if (t.left.priority > t.right.priority)
			t = rightRotate(t);
		// Perform a left rotation if the right child has a higher priority
		t = leftRotate(t);
	}
	// Return the updated tree
	return t;
}

// Function to perform a right rotation on an AVL tree
Node rightRotate(Node p)
{
	// Save a reference to the left child
	Node q = p.left;
	// Make the left child's right subtree the new root
	p.left = q.right;
	// Make the old root the new left child of the left child
	q.right = p;
	// Return the new root
	return q;
}

// Function to perform a left rotation on an AVL tree
Node leftRotate(Node p)
{
	// Save a reference to the right child
	Node q = p.right;
	// Make the right child's left subtree the new root
	p.right = q.left;
	// Make the old root the new right child of the right child
	q.left = p;
	// Return the new root
	return q;
}

// Function to insert a new node into the AVL tree
Node insert(Node t, int key, int priority)
{
	// If the tree is empty, create a new node and return it
	if (t == null) return new Node(key, priority);
	// Recursively search for the location to insert the new node
	t = insert(t, key, priority);
	// If the new node becomes the root, check if it needs to be rotated
	if (t.priority < t.left.priority || t.priority < t.right.priority) {
		// Perform a right rotation if the left child has a higher priority
		if (t.left.priority > t.right.priority)
			t = rightRotate(t);
		// Perform a left rotation if the right child has a higher priority
		t = leftRotate(t);
	}
	// Return the updated tree
	return t;
}

// Function to delete a node from the AVL tree
Node delete(Node t, int key)
{
	// If the tree is empty, do nothing
	if (t == null) return null;
	// Recursively search for the node to delete
	if (key < t.key) t.left = delete(t.left, key);
	else if (key > t.key) t.right = delete(t.right, key);
	// If the node to be deleted has no children, delete it
	else if (t.left == null && t.right == null) {
		t = null;
	}
	// If the node to be deleted has only one child, make the child the new node
	else if (t.left == null) {
		t = t.right;
	}
	else if (t.right == null) {
		t = t.left;
	}
	// If the node to be deleted has two children, replace it with its successor
	else {
		Node q = t.right;
		while (q.left!= null) q = q.left;
		t.key = q.key;
		t.priority = q.priority;
		t.right = delete(t.right, q.key);
	}
	// Return the updated tree
	return t;
}

// Main function to read commands and perform the corresponding operations on the AVL tree
public static void main(String[] args)
{
	// Initialize the AVL tree to be empty
	int num, x, y;
	String com;
	Node root = null;
	// Read the number of commands
	num = Integer.parseInt(args[0]);
	// Process each command
	for (int i = 0; i < num; i++) {
		com = args[i * 2 + 1];
		// Based on the command, perform the corresponding operation on the AVL tree
		switch (com.charAt(0)) {
			case 'i': // Insert a new node
				x = Integer.parseInt(args[i * 2 + 2]);
				y = Integer.parseInt(args[i * 2 + 3]);
				root = insert(root, x, y);
				break;
			case 'd': // Delete a node
				x = Integer.parseInt(args[i * 2 + 2]);
				root = Delete(root, x);
				break;
			case 'f': // Find a node
				x = Integer.parseInt(args[i * 2 + 2]);
				if (find(root, x)) System.out.println("yes");
				else System.out.println("no");
				break;
			case 'p': // Print the AVL tree
				print(root);
				break;
		}
	}
}

