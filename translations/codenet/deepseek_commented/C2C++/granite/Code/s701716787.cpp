
#include <iostream>
#include <string.h>

using namespace std;

#define COMMAND_LENGTH     (10)   /* 命令の文字数 */

struct ST_NODE
{
	ST_NODE* st_parent;
	ST_NODE* st_left;
	ST_NODE* st_right;
	int s4_key;
};

void d_d_insert(ST_NODE**, int);
void d_d_print(ST_NODE*);
static void s_printPreOrder(ST_NODE*);
static void s_printInOrder(ST_NODE*);
ST_NODE* dp_newST_NODE(int);

int main()
{
	ST_NODE* tp_root;
	int t_numCommand;
	int t_iCommand;
	char t_command[COMMAND_LENGTH];
	int t_insertKey;
	int t_RtnStrcmp;

	tp_root = NULL; // Initialize the root of the tree to NULL

	// Read the number of commands
	cin >> t_numCommand;

	// Execute commands
	for (t_iCommand = 0; t_iCommand < t_numCommand; t_iCommand++)
	{
		// Read the command
		cin >> t_command;

		// Execute the command based on its type
		t_RtnStrcmp = strcmp(t_command, "insert");
		if (t_RtnStrcmp == 0)
		{
			// If the command is "insert", read the key value and insert it into the tree
			cin >> t_insertKey;
			d_d_insert(&tp_root, t_insertKey);
		}
		else
		{
			// If the command is "print", print the tree
			d_d_print(tp_root);
		}
	}

	return 0;
}

// Insert a new node into the binary search tree
void d_d_insert(ST_NODE** ap2_root, int a_key)
{
	ST_NODE* tp_parentNode;
	ST_NODE* tp_indexNode;
	ST_NODE* tp_insertNode;

	tp_insertNode = dp_newST_NODE(a_key); // Create a new node with the given key

	tp_parentNode = NULL;
	tp_indexNode = *ap2_root;

	while (tp_indexNode!= NULL)
	{
		tp_parentNode = tp_indexNode;
		if (tp_insertNode->s4_key < tp_indexNode->s4_key)
		{
			tp_indexNode = tp_indexNode->st_left;
		}
		else
		{
			tp_indexNode = tp_indexNode->st_right;
		}
	}
	tp_insertNode->st_parent = tp_parentNode; // Set the parent of the new node

	if (tp_parentNode == NULL)
	{
		*ap2_root = tp_insertNode; // If the tree was empty, set the root to the new node
	}
	else if (a_key < tp_parentNode->s4_key)
	{
		tp_parentNode->st_left = tp_insertNode; // Insert the new node as the left child if the key is less than the parent's key
	}
	else
	{
		tp_parentNode->st_right = tp_insertNode; // Insert the new node as the right child if the key is greater than or equal to the parent's key
	}
}

// Print the tree in both pre-order and in-order traversal
void d_d_print(ST_NODE* ap_root)
{
	s_printInOrder(ap_root); // Print the tree in in-order traversal
	cout << endl;
	s_printPreOrder(ap_root); // Print the tree in pre-order traversal
	cout << endl;
}

// Pre-order traversal of the tree
static void s_printPreOrder(ST_NODE* ap_node)
{
	if (ap_node == NULL)
	{
		return;
	}

	cout << " " << ap_node->s4_key; // Print the current node's key
	s_printPreOrder(ap_node->st_left); // Recursively print the left subtree
	s_printPreOrder(ap_node->st_right); // Recursively print the right subtree
}

// In-order traversal of the tree
static void s_printInOrder(ST_NODE* ap_node)
{
	static int s_printedNumNode = 0; // Static variable to keep track of the number of nodes printed

	if (ap_node == NULL)
	{
		return;
	}

	s_printInOrder(ap_node->st_left); // Recursively print the left subtree
	cout << " " << ap_node->s4_key; // Print the current node's key
	s_printInOrder(ap_node->st_right); // Recursively print the right subtree
}

// Constructor-like function to create a new ST_NODE
ST_NODE* dp_newST_NODE(int a_key)
{
	ST_NODE* tp_node;
	tp_node = (ST_NODE*)malloc(sizeof(ST_NODE)); // Allocate memory for the new node
	tp_node->st_parent = NULL; // Initialize the parent pointer to NULL
	tp_node->st_left = NULL; // Initialize the left child pointer to NULL
	tp_node->st_right = NULL; // Initialize the right child pointer to NULL
	tp_node->s4_key = a_key; // Set the key of the new node

	return(tp_node);
}

