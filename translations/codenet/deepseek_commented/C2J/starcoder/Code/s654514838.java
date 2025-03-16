
import java.util.*;

public class Heap {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		Node root = null;
		for(int i = 0; i < num; i++)
		{
			String com = sc.next();
			switch(com.charAt(0))
			{
				case 'i':
					int x = sc.nextInt();
					int y = sc.nextInt();
					root = insert(root,x,y);
					break;
				case 'd':
					int x = sc.nextInt();
					root = delete(root,x);
					break;
				case 'f':
					int x = sc.nextInt();
					if(find(root,x))System.out.println("yes");
					else System.out.println("no");
					break;
				case 'p':
					print(root);
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
	}
	
	// This function performs a preorder traversal of the tree and prints the keys.
	public static void preorder(Node p)
	{
		System.out.print(" "+p.key);
		if(p.left!=null) preorder(p.left);
		if(p.right!=null) preorder(p.right);
	}
	
	// This function prints the tree in both inorder and preorder traversal formats.
	public static void print(Node p)
	{
		inorder(p);
		System.out.println();
		preorder(p);
		System.out.println();
	}
	
	// This function creates a new node with given key and priority.
	public static Node makenode(int x, int y)
	{
		Node new = new Node();
		new.key = x;
		new.priority = y;
		new.left = null;
		new.right = null;
		return new;
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
	public static Node insert(Node t, int key, int priority)  // Recursive search
	{
		Node new;
		if(t==null)
		return new = makenode(key,priority); // Create new node if leaf is reached
		if(t.key == key)
		return t;  // Ignore duplicate keys
		
		if(key < t.key) // Move to left child
		{
			t.left = insert(t.left,key,priority); // Update left child pointer
			if(t.priority < t.left.priority) // Right rotate if left child has higher priority
			t = rightRotate(t);
		}
		else{ // Move to right child
			t.right = insert(t.right,key,priority); // Update right child pointer
			if(t.priority < t.right.priority) // Left rotate if right child has higher priority
			t = leftRotate(t);
		}
		return t;
	}
	
	// This function initiates the deletion process and calls `delete` for actual deletion.
	public static Node Delete(Node t, int key)
	{
		if(t==null)
		return null;
		
		if(key < t.key) // Search for the node to delete
		t.left = Delete(t.left,key);
		
		else if(key > t.key)
		t.right = Delete(t.right,key);
		
		else return delete(t,key);
		return t;
	}
	
	// This function handles the actual deletion of nodes, including cases where the node has one or two children.
	public static Node delete(Node t, int key)
	{
		if(t.left == null && t.right == null)  // Case for leaf node
		{
			return null;
		}
		else if(t.left == null) // Case for node with only right child
		{
			t = leftRotate(t);
		}
		else if(t.right ==null) // Case for node with only left child
		{
			t = rightRotate(t);
		}
		else{ // Case for node with both left and right children
			if(t.left.priority > t.right.priority) // Rotate based on higher priority child
			t = rightRotate(t);
			else
			t = leftRotate(t);
		}
		return Delete(t,key);
	}
}

class Node{
	int key;
	int priority;
	Node left, right;
}

