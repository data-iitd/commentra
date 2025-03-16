
// Binary search tree implementation

// Node class
class Node
{
    int key;
    Node left, right;

    public Node(int key)
    {
        this.key = key;
    }
}

// Binary search tree class
class BST
{
    Node root;

    public BST()
    {
        root = null;
    }

    // Insert a key into the binary search tree
    public void insert(int key)
    {
        Node parent = null, index = root;

        // Create a new node with the given key
        Node newNode = new Node(key);

        // Traverse the tree to find the correct insertion point
        while (index!= null)
        {
            parent = index;
            if (newNode.key < index.key)
            {
                index = index.left;
            }
            else
            {
                index = index.right;
            }
        }
        newNode.parent = parent;

        // Insert the new node in the tree
        if (parent == null)
        {
            root = newNode; // Tree was empty, new node becomes root
        }
        else if (newNode.key < parent.key)
        {
            parent.left = newNode; // Insert as left child
        }
        else
        {
            parent.right = newNode; // Insert as right child
        }
    }

    // Print the binary search tree
    public void print()
    {
        printInOrder(root); // Print in-order
        System.out.println();
        printPreOrder(root); // Print pre-order
        System.out.println();
    }

    // Print the tree in pre-order
    public void printPreOrder(Node node)
    {
        if (node == null)
        {
            return; // Base case: if the node is NULL, return
        }

        System.out.print(" " + node.key); // Print the key of the current node
        printPreOrder(node.left); // Recursively print left subtree
        printPreOrder(node.right); // Recursively print right subtree
    }

    // Print the tree in in-order
    public void printInOrder(Node node)
    {
        if (node == null)
        {
            return; // Base case: if the node is NULL, return
        }

        printInOrder(node.left); // Recursively print left subtree
        System.out.print(" " + node.key); // Print the key of the current node
        printInOrder(node.right); // Recursively print right subtree
    }
}

// Main program
public class Main
{
    public static void main(String[] args)
    {
        BST tree = new BST(); // Create a new binary search tree

        // Read the number of commands from user input
        Scanner sc = new Scanner(System.in);
        int numCommand = sc.nextInt();

        // Execute commands based on user input
        for (int iCommand = 0; iCommand < numCommand; iCommand++)
        {
            // Read the command (insert or print)
            String command = sc.next();

            // Execute the command based on its type
            // Assumes only "insert" and "print" commands are valid
            if (command.equals("insert"))
            {
                // If the command is "insert", read the key value to insert
                int key = sc.nextInt();
                tree.insert(key); // Insert the key into the tree
            }
            else
            {
                tree.print(); // Print the current state of the tree
            }
        }
    }
}

