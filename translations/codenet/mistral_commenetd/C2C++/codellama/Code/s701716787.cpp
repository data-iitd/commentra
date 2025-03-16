#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#define COMMAND_LENGTH     (10)   /* 命令の文字数 */

using namespace std;

typedef struct st_node ST_NODE;
typedef struct st_node
{
	ST_NODE* st_parent;
	ST_NODE* st_left;
	ST_NODE* st_right;
	S4 s4_key;
};

void vd_d_insert(ST_NODE**, S4); // Function prototype for inserting a new node
void vd_d_print(ST_NODE*);      // Function prototype for printing the tree
static void vd_s_printPreOrder(ST_NODE*); // Function prototype for pre-order traversal
static void vd_s_printInOrder(ST_NODE*); // Function prototype for in-order traversal
ST_NODE* st_dp_newST_NODE(S4); // Function prototype for creating a new node

S4 main() // Main function
{
	ST_NODE* st_tp_root; // Pointer to the root node of the AVL tree
	S4 s4_t_numCommand; // Number of commands to be executed
	S4 s4_t_iCommand; // Index of the current command
	S1 s1_tp_command[COMMAND_LENGTH]; // Command string
	S4 s4_t_insertKey; // Key to be inserted
	S4 s4_t_RtnStrcmp; // Return value of strcmp() function

	st_tp_root = (ST_NODE*)NULL; // Initialize the root node to NULL

	// Read the number of commands from the standard input
	cout << "Enter the number of commands: ";
	cin >> s4_t_numCommand;

	// Process each command
	for (s4_t_iCommand = (S4)0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++)
	{
		// Read the command string
		cout << "Enter the command (insert or print): ";
		cin >> s1_tp_command;

		// Determine the type of command based on the command string
		s4_t_RtnStrcmp = (S4)strcmp(s1_tp_command, "insert");
		if (s4_t_RtnStrcmp == (S4)0) // If the command is "insert"
		{
			// Read the key to be inserted
			cout << "Enter the key to be inserted: ";
			cin >> s4_t_insertKey;

			// Call the insert function to insert the new node
			vd_d_insert(&st_tp_root, s4_t_insertKey);
		}
		else // If the command is "print"
		{
			// Call the print function to print the tree
			vd_d_print(st_tp_root);
		}
	}

	return((S4)0); // Return success
}

void vd_d_insert(ST_NODE** st_ap2_root, S4 s4_a_key) // Function for inserting a new node into the AVL tree
{
	ST_NODE* st_tp_parentNode; // Pointer to the parent node of the new node
	ST_NODE* st_tp_indexNode; // Pointer to the node where the new node should be inserted
	ST_NODE* st_tp_insertNode; // Pointer to the new node

	st_tp_insertNode = st_dp_newST_NODE(s4_a_key); // Create a new node with the given key

	st_tp_parentNode = (ST_NODE*)NULL; // Initialize the parent node pointer to NULL
	st_tp_indexNode = *st_ap2_root; // Initialize the index node pointer to the root node

	// Search for the position to insert the new node
	while (st_tp_indexNode != (ST_NODE*)NULL)
	{
		st_tp_parentNode = st_tp_indexNode; // Move the parent node pointer one step back

		if (st_tp_insertNode->s4_key < st_tp_indexNode->s4_key) // If the new node's key is smaller than the current node's key
		{
			st_tp_indexNode = st_tp_indexNode->st_left; // Move to the left subtree
		}
		else // If the new node's key is larger than or equal to the current node's key
		{
			st_tp_indexNode = st_tp_indexNode->st_right; // Move to the right subtree
		}
	}

	// Insert the new node at the appropriate position
	st_tp_insertNode->st_parent = st_tp_parentNode;

	if (st_tp_parentNode == (ST_NODE*)NULL) // If the new node is the root node
	{
		*st_ap2_root = st_tp_insertNode; // Set the root node to the new node
	}
	else if (s4_a_key < st_tp_parentNode->s4_key) // If the new node's key is smaller than the parent node's key
	{
		st_tp_parentNode->st_left = st_tp_insertNode; // Set the left child of the parent node to the new node
	}
	else // If the new node's key is larger than or equal to the parent node's key
	{
		st_tp_parentNode->st_right = st_tp_insertNode; // Set the right child of the parent node to the new node
	}
}

void vd_d_print(ST_NODE* st_ap_root) // Function for printing the AVL tree
{
	vd_s_printInOrder(st_ap_root); // Call the in-order traversal function to print the tree in sorted order
	cout << endl;
	vd_s_printPreOrder(st_ap_root); // Call the pre-order traversal function to print the tree in the recursive order
	cout << endl;
}

// st_ap_node…exploration start node
static void vd_s_printPreOrder(ST_NODE* st_ap_node) // Function for pre-order traversal of the AVL tree
{
	if (st_ap_node == (ST_NODE*)NULL) // If the node is NULL, return
	{
		return;
	}

	cout << " " << st_ap_node->s4_key; // Print the key of the current node
	vd_s_printPreOrder(st_ap_node->st_left); // Recursively print the left subtree
	vd_s_printPreOrder(st_ap_node->st_right); // Recursively print the right subtree
}

// st_ap_node…exploration start node
static void vd_s_printInOrder(ST_NODE* st_ap_node) // Function for in-order traversal of the AVL tree
{
	static S4 s4_s_printedNumNode = (S4)0; // A static variable to keep track of the number of nodes printed

	if (st_ap_node == (ST_NODE*)NULL) // If the node is NULL, return
	{
		return;
	}

	vd_s_printInOrder(st_ap_node->st_left); // Recursively print the left subtree
	cout << " " << st_ap_node->s4_key; // Print the key of the current node
	vd_s_printInOrder(st_ap_node->st_right); // Recursively print the right subtree
}

// ST_NODE constructor
ST_NODE* st_dp_newST_NODE(S4 s4_a_key) // Function for creating a new node
{
	ST_NODE* st_tp_node; // Pointer to the new node
	st_tp_node = (ST_NODE*)malloc(sizeof(ST_NODE)); // Allocate memory for the new node
	st_tp_node->st_parent = (ST_NODE*)NULL; // Initialize the parent pointer to NULL
	st_tp_node->st_left = (ST_NODE*)NULL; // Initialize the left child pointer to NULL
	st_tp_node->st_right = (ST_NODE*)NULL; // Initialize the right child pointer to NULL
	st_tp_node->s4_key = s4_a_key; // Set the key of the new node

	return(st_tp_node); // Return the new node
}

