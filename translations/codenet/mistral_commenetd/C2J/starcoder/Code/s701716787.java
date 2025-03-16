
import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		int numCommand; // Number of commands to be executed
		int iCommand; // Index of the current command
		String[] command = new String[10]; // Command string
		int insertKey; // Key to be inserted
		int RtnStrcmp; // Return value of strcmp() function

		ST_NODE root = null; // Initialize the root node to NULL

		// Read the number of commands from the standard input
		System.out.print("Enter the number of commands: ");
		numCommand = new Scanner(System.in).nextInt();

		// Process each command
		for (iCommand = 0; iCommand < numCommand; iCommand++)
		{
			// Read the command string
			System.out.print("Enter the command (insert or print): ");
			command[iCommand] = new Scanner(System.in).next();

			// Determine the type of command based on the command string
			RtnStrcmp = command[iCommand].compareTo("insert");
			if (RtnStrcmp == 0) // If the command is "insert"
			{
				// Read the key to be inserted
				System.out.print("Enter the key to be inserted: ");
				insertKey = new Scanner(System.in).nextInt();

				// Call the insert function to insert the new node
				insert(root, insertKey);
			}
			else // If the command is "print"
			{
				// Call the print function to print the tree
				print(root);
			}
		}
	}

	// st_ap_node…exploration start node
	public static void print(ST_NODE st_ap_node) // Function for printing the AVL tree
	{
		printInOrder(st_ap_node); // Call the in-order traversal function to print the tree in sorted order
		System.out.println();
		printPreOrder(st_ap_node); // Call the pre-order traversal function to print the tree in the recursive order
		System.out.println();
	}

	// st_ap_node…exploration start node
	public static void printPreOrder(ST_NODE st_ap_node) // Function for pre-order traversal of the AVL tree
	{
		if (st_ap_node == null) // If the node is NULL, return
		{
			return;
		}

		System.out.print(" " + st_ap_node.s4_key); // Print the key of the current node
		printPreOrder(st_ap_node.st_left); // Recursively print the left subtree
		printPreOrder(st_ap_node.st_right); // Recursively print the right subtree
	}

	// st_ap_node…exploration start node
	public static void printInOrder(ST_NODE st_ap_node) // Function for in-order traversal of the AVL tree
	{
		static int printedNumNode = 0; // A static variable to keep track of the number of nodes printed

		if (st_ap_node == null) // If the node is NULL, return
		{
			return;
		}

		printInOrder(st_ap_node.st_left); // Recursively print the left subtree
		System.out.print(" " + st_ap_node.s4_key); // Print the key of the current node
		printInOrder(st_ap_node.st_right); // Recursively print the right subtree
	}

	// ST_NODE constructor
	public static ST_NODE newST_NODE(int s4_a_key) // Function for creating a new node
	{
		ST_NODE st_tp_node; // Pointer to the new node
		st_tp_node = new ST_NODE(); // Allocate memory for the new node
		st_tp_node.st_parent = null; // Initialize the parent pointer to NULL
		st_tp_node.st_left = null; // Initialize the left child pointer to NULL
		st_tp_node.st_right = null; // Initialize the right child pointer to NULL
		st_tp_node.s4_key = s4_a_key; // Set the key of the new node

		return(st_tp_node); // Return the new node
	}

	// Function for inserting a new node into the AVL tree
	public static void insert(ST_NODE st_ap2_root, int s4_a_key)
	{
		ST_NODE st_tp_parentNode; // Pointer to the parent node of the new node
		ST_NODE st_tp_indexNode; // Pointer to the node where the new node should be inserted
		ST_NODE st_tp_insertNode; // Pointer to the new node

		st_tp_insertNode = newST_NODE(s4_a_key); // Create a new node with the given key

		st_tp_parentNode = null; // Initialize the parent node pointer to NULL
		st_tp_indexNode = st_ap2_root; // Initialize the index node pointer to the root node

		// Search for the position to insert the new node
		while (st_tp_indexNode!= null)
		{
			st_tp_parentNode = st_tp_indexNode; // Move the parent node pointer one step back

			if (st_tp_insertNode.s4_key < st_tp_indexNode.s4_key) // If the new node's key is smaller than the current node's key
			{
				st_tp_indexNode = st_tp_indexNode.st_left; // Move to the left subtree
			}
			else // If the new node's key is larger than or equal to the current node's key
			{
				st_tp_indexNode = st_tp_indexNode.st_right; // Move to the right subtree
			}
		}

		// Insert the new node at the appropriate position
		st_tp_insertNode.st_parent = st_tp_parentNode;

		if (st_tp_parentNode == null) // If the new node is the root node
		{
			st_ap2_root = st_tp_insertNode; // Set the root node to the new node
		}
		else if (s4_a_key < st_tp_parentNode.s4_key) // If the new node's key is smaller than the parent node's key
		{
			st_tp_parentNode.st_left = st_tp_insertNode; // Set the left child of the parent node to the new node
		}
		else // If the new node's key is larger than or equal to the parent node's key
		{
			st_tp_parentNode.st_right = st_tp_insertNode; // Set the right child of the parent node to the new node
		}
	}
}

