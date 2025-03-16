#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define U1 unsigned char
#define S1 char
#define	S4 int
#define DU double
#define VD void

#define COMMAND_LENGTH     (10)   /* 命令の文字数 */

class Node
{
	public Node st_parent;
	public Node st_left;
	public Node st_right;
	public S4 s4_key;

	public Node(S4 s4_a_key)
	{
		st_parent = (Node)null;
		st_left = (Node)null;
		st_right = (Node)null;
		s4_key = s4_a_key;
	}
}

public class Main
{
	public static void main(String[] args)
	{
		Node st_tp_root;
		S4 s4_t_numCommand;
		S4 s4_t_iCommand;
		S1 s1_tp_command[COMMAND_LENGTH];
		S4 s4_t_insertKey;
		S4 s4_t_RtnStrcmp;

		st_tp_root = (Node)null; // Initialize the root of the tree to NULL

		// Read the number of commands
		(VD)scanf("%d", &s4_t_numCommand);

		// Execute commands
		for (s4_t_iCommand = (S4)0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++)
		{
			// Read the command
			(VD)scanf("%s", s1_tp_command);

			// Execute the command based on its type
			s4_t_RtnStrcmp = (S4)strcmp(s1_tp_command, "insert");
			if (s4_t_RtnStrcmp == (S4)0)
			{
				// If the command is "insert", read the key value and insert it into the tree
				(VD)scanf("%d", &s4_t_insertKey);
				vd_d_insert(&st_tp_root, s4_t_insertKey);
			}
			else
			{
				// If the command is "print", print the tree
				vd_d_print(st_tp_root);
			}
		}

		return((S4)0);
	}

	// Insert a new node into the binary search tree
	public static void vd_d_insert(Node[] st_ap2_root, S4 s4_a_key)
	{
		Node st_tp_parentNode;
		Node st_tp_indexNode;
		Node st_tp_insertNode;

		st_tp_insertNode = st_dp_newST_NODE(s4_a_key); // Create a new node with the given key

		st_tp_parentNode = (Node)null;
		st_tp_indexNode = st_ap2_root[0];

		while (st_tp_indexNode != (Node)null)
		{
			st_tp_parentNode = st_tp_indexNode;
			if (st_tp_insertNode.s4_key < st_tp_indexNode.s4_key)
			{
				st_tp_indexNode = st_tp_indexNode.st_left;
			}
			else
			{
				st_tp_indexNode = st_tp_indexNode.st_right;
			}
		}
		st_tp_insertNode.st_parent = st_tp_parentNode; // Set the parent of the new node

		if (st_tp_parentNode == (Node)null)
		{
			st_ap2_root[0] = st_tp_insertNode; // If the tree was empty, set the root to the new node
		}
		else if (s4_a_key < st_tp_parentNode.s4_key)
		{
			st_tp_parentNode.st_left = st_tp_insertNode; // Insert the new node as the left child if the key is less than the parent's key
		}
		else
		{
			st_tp_parentNode.st_right = st_tp_insertNode; // Insert the new node as the right child if the key is greater than or equal to the parent's key
		}
	}

	// Print the tree in both pre-order and in-order traversal
	public static void vd_d_print(Node st_ap_root)
	{
		vd_s_printInOrder(st_ap_root); // Print the tree in in-order traversal
		System.out.println();
		vd_s_printPreOrder(st_ap_root); // Print the tree in pre-order traversal
		System.out.println();
	}

	// Pre-order traversal of the tree
	public static void vd_s_printPreOrder(Node st_ap_node)
	{
		if (st_ap_node == (Node)null)
		{
			return;
		}

		System.out.print(" " + st_ap_node.s4_key); // Print the current node's key
		vd_s_printPreOrder(st_ap_node.st_left); // Recursively print the left subtree
		vd_s_printPreOrder(st_ap_node.st_right); // Recursively print the right subtree
	}

	// In-order traversal of the tree
	public static void vd_s_printInOrder(Node st_ap_node)
	{
		static s4_s_printedNumNode = (S4)0; // Static variable to keep track of the number of nodes printed

		if (st_ap_node == (Node)null)
		{
			return;
		}

		vd_s_printInOrder(st_ap_node.st_left); // Recursively print the left subtree
		System.out.print(" " + st_ap_node.s4_key); // Print the current node's key
		vd_s_printInOrder(st_ap_node.st_right); // Recursively print the right subtree
	}

	// Constructor-like function to create a new ST_NODE
	public static Node st_dp_newST_NODE(S4 s4_a_key)
	{
		Node st_tp_node;
		st_tp_node = new Node(s4_a_key); // Allocate memory for the new node
		st_tp_node.st_parent = (Node)null; // Initialize the parent pointer to NULL
		st_tp_node.st_left = (Node)null; // Initialize the left child pointer to NULL
		st_tp_node.st_right = (Node)null; // Initialize the right child pointer to NULL
		st_tp_node.s4_key = s4_a_key; // Set the key of the new node

		return(st_tp_node);
	}
}

