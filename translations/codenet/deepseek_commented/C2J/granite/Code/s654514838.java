
import java.util.*;

class Node{
	int key;
	int priority;
	Node right, left;
}

class s654514838{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		Node root = null;
		for(int i = 0; i < num; i++)
		{
			String com = sc.next();
			switch(com.charAt(0))
			{
			  case 'i':int x = sc.nextInt();
				int y = sc.nextInt();
				root = insert(root,x,y);
				break;
			  case 'd':int x = sc.nextInt();
				root = Delete(root,x);
				break;
			  case 'f':int x = sc.nextInt();
				if(find(root,x))System.out.println("yes");
				else System.out.println("no");
				break;
			  case 'p':print(root);
				break;
			}
		}
	}
	// This function searches for a key in the tree. Returns 1 if found, otherwise 0.
	public static int find(Node p,int x)
	{
		while(p!=null)
		{
			if(p.key==x)return 1;
			else if(p.key > x)p = p.left;
			else p = p.right;
		}
		return 0;
	}

	// This function performs an inorder traversal of the tree and prints the keys.
	public static void inorder(Node a)
	{
		if(a.left!=null) inorder(a.left);
		System.out.print(" "+a.key);
		if(a.right!=null) inorder(a.right);
		return;
	}

	// This function performs a preorder traversal of the tree and prints the keys.
	public static void preorder(Node p)
	{
		System.out.print(" "+p.key);
		if(p.left!=null) preorder(p.left);
		if(p.right!=null) preorder(p.right);
		return;
	}

	// This function prints the tree in both inorder and preorder traversal formats.
	public static void print(Node p)
	{
		inorder(p);
		System.out.println();
		preorder(p);
		System.out.println();
		return;
	}

	// This function creates a new node with given key and priority.
	public static Node makenode(int x, int y)
	{
		Node newnode = new Node();
		newnode.key = x;
		newnode.priority = y;
		newnode.left = null;
		newnode.right = null;
		return newnode;
	}

	// This function performs a right rotation on the given node.
	public static Node rightRotate(Node p)
	{
		Node q = p.left;
		p.left = q.right;
		q.right = p;
		return q;
	}

	// This function performs a left rotation on the given node.
	public static Node leftRotate(Node p)
	{
		Node q = p.right;
		p.right = q.left;
		q.left = p;
		return q;
	}

	// This function inserts a new node into the tree while maintaining the heap property using rotations.
	public static Node insert(Node root, int key, int priority)  // Recursive search
	{
		Node newnode;
		if(root==null)
		return newnode = makenode(key,priority); // Create new node if leaf is reached
		if(root.key == key)
		return root;  // Ignore duplicate keys
		
		if(key < root.key) // Move to left child
		{
			root.left = insert(root.left,key,priority); // Update left child pointer
			if(root.priority < root.left.priority) // Right rotate if left child has higher priority
			root = rightRotate(root);
		}
		else{ // Move to right child
			root.right = insert(root.right,key,priority); // Update right child pointer
			if(root.priority < root.right.priority) // Left rotate if right child has higher priority
			root = leftRotate(root);
		}
		return root;
	}

	// This function initiates the deletion process and calls `delete` for actual deletion.
	public static Node Delete(Node root, int key)
	{
		if(root==null)
		return null;
		
		if(key < root.key) // Search for the node to delete
		root.left = Delete(root.left,key);
		
		else if(key > root.key)
		root.right = Delete(root.right,key);
		
		else return delete(root,key);
		return root;
	}

	// This function handles the actual deletion of nodes, including cases where the node has one or two children.
	public static Node delete(Node root, int key)
	{
		if(root.left == null && root.right == null)  // Case for leaf node
		{
			return null;
		}
		else if(root.left == null) // Case for node with only right child
		{
			root = leftRotate(root);
		}
		else if(root.right ==null) // Case for node with only left child
		{
			root = rightRotate(root);
		}
		else{ // Case for node with both left and right children
			if(root.left.priority > root.right.priority) // Rotate based on higher priority child
			root = rightRotate(root);
			else
			root = leftRotate(root);
		}
		return Delete(root,key);
	}
}

