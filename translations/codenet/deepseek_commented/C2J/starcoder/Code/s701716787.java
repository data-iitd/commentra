
import java.util.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int numCommand = sc.nextInt();
		ST_NODE root = null;
		for (int iCommand = 0; iCommand < numCommand; iCommand++)
		{
			String command = sc.next();
			if (command.equals("insert"))
			{
				int insertKey = sc.nextInt();
				insert(root, insertKey);
			}
			else
			{
				print(root);
			}
		}
	}

	// Insert a new node into the binary search tree
	public static void insert(ST_NODE root, int key)
	{
		ST_NODE parent = null;
		ST_NODE index = root;
		ST_NODE insertNode = new ST_NODE();
		insertNode.key = key;

		while (index!= null)
		{
			parent = index;
			if (insertNode.key < index.key)
			{
				index = index.left;
			}
			else
			{
				index = index.right;
			}
		}
		insertNode.parent = parent; // Set the parent of the new node

		if (parent == null)
		{
			root = insertNode; // If the tree was empty, set the root to the new node
		}
		else if (key < parent.key)
		{
			parent.left = insertNode; // Insert the new node as the left child if the key is less than the parent's key
		}
		else
		{
			parent.right = insertNode; // Insert the new node as the right child if the key is greater than or equal to the parent's key
		}
	}

	// Print the tree in both pre-order and in-order traversal
	public static void print(ST_NODE root)
	{
		printInOrder(root); // Print the tree in in-order traversal
		System.out.println();
		printPreOrder(root); // Print the tree in pre-order traversal
		System.out.println();
	}

	// Pre-order traversal of the tree
	public static void printPreOrder(ST_NODE node)
	{
		if (node == null)
		{
			return;
		}

		System.out.print(" " + node.key); // Print the current node's key
		printPreOrder(node.left); // Recursively print the left subtree
		printPreOrder(node.right); // Recursively print the right subtree
	}

	// In-order traversal of the tree
	public static void printInOrder(ST_NODE node)
	{
		static int printedNumNode = 0; // Static variable to keep track of the number of nodes printed

		if (node == null)
		{
			return;
		}

		printInOrder(node.left); // Recursively print the left subtree
		System.out.print(" " + node.key); // Print the current node's key
		printInOrder(node.right); // Recursively print the right subtree
	}
}

// Structure to store a node of the binary search tree
class ST_NODE
{
	ST_NODE parent;
	ST_NODE left;
	ST_NODE right;
	int key;
}

