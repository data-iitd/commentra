import java.util.*;

public class Main{
	public static void main(String[] args){
		int num,  x, y;
		String com;
		Node root = null;
		Scanner sc = new Scanner(System.in);
		num = sc.nextInt();
		
		for(int i = 0; i < num; i++)
		{
			com = sc.next();
			switch(com.charAt(0))
			{
			  case 'i':x = sc.nextInt();
				y = sc.nextInt();
				root = insert(root,x,y);
				break;
			  case 'd':x = sc.nextInt();
				root = Delete(root,x);
				break;
			  case 'f':x = sc.nextInt();
				if(find(root,x))System.out.println("yes");
				else System.out.println("no");
				break;
			  case 'p':print(root);
				break;
			}
		}
	}
	
	public static Node insert(Node root, int x, int y)
	{
		Node new = new Node();
		new.key = x;
		new.priority = y;
		new.left = null;
		new.right = null;
		if(root == null)
		return new;
		if(root.key == x)
		return root;
		if(x < root.key)
		{
			root.left = insert(root.left,x,y);
			if(root.priority < root.left.priority)
			root = rightRotate(root);
		}
		else{
			root.right = insert(root.right,x,y);
			if(root.priority < root.right.priority)
			root = leftRotate(root);
		}
		return root;
	}
	
	public static Node Delete(Node root, int x)
	{
		if(root == null)
		return null;
		if(x < root.key)
		root.left = Delete(root.left,x);
		else if(x > root.key)
		root.right = Delete(root.right,x);
		else return delete(root,x);
		return root;
	}
	
	public static Node delete(Node root, int x)
	{
		if(root.left == null && root.right == null)
		return null;
		else if(root.left == null)
		root = leftRotate(root);
		else if(root.right == null)
		root = rightRotate(root);
		else{
			if(root.left.priority > root.right.priority)
			root = rightRotate(root);
			else
			root = leftRotate(root);
		}
		return Delete(root,x);
	}
	
	public static boolean find(Node root, int x)
	{
		while(root!= null)
		{
			if(root.key == x)
			return true;
			else if(root.key > x)
			root = root.left;
			else
			root = root.right;
		}
		return false;
	}
	
	public static void print(Node root)
	{
		inorder(root);
		System.out.println();
		preorder(root);
		System.out.println();
	}
	
	public static void inorder(Node root)
	{
		if(root.left!= null) inorder(root.left);
		System.out.print(" " + root.key);
		if(root.right!= null) inorder(root.right);
	}
	
	public static void preorder(Node root)
	{
		System.out.print(" " + root.key);
		if(root.left!= null) preorder(root.left);
		if(root.right!= null) preorder(root.right);
	}
	
	public static Node rightRotate(Node root)
	{
		Node q = root.left;
		root.left = q.right;
		q.right = root;
		return q;
	}
	
	public static Node leftRotate(Node root)
	{
		Node q = root.right;
		root.right = q.left;
		q.left = root;
		return q;
	}
}

