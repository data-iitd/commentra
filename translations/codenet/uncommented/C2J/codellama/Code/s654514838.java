#include <stdio.h>
#include <stdlib.h>

class Node{
	int key;
	int priority;
	Node left;
	Node right;
	
	public Node(int x , int y)
	{
		key = x;
		priority = y;
		left = null;
		right = null;
	}
}

class Tree{
	Node root;
	
	public Tree()
	{
		root = null;
	}
	
	public void insert(int x , int y)
	{
		root = insert(root,x,y);
	}
	
	public void delete(int x)
	{
		root = Delete(root,x);
	}
	
	public void find(int x)
	{
		if(find(root,x))System.out.println("yes");
		else System.out.println("no");
	}
	
	public void print()
	{
		inorder(root);
		System.out.println();
		preorder(root);
		System.out.println();
	}
	
	public Node insert(Node t , int key, int priority)
	{
		Node new;
		if(t==null)
		return new Node(key,priority);
		if(t.key == key)
		return t;
		
		if(key < t.key)
		{
			t.left = insert(t.left,key,priority);
			if(t.priority < t.left.priority)
			t = rightRotate(t);
		}
		else{
			t.right = insert(t.right,key,priority);
			if(t.priority < t.right.priority)
			t = leftRotate(t);
		}
		return t;
	}
	
	public Node Delete(Node t , int key)
	{
		if(t==null)
		return null;
		
		if(key < t.key)
		t.left = Delete(t.left,key);
		
		else if(key > t.key)
		t.right = Delete(t.right,key);
		
		else return delete(t,key);
		return t;
	}
	
	public Node delete(Node t , int key)
	{
		if(t.left == null && t.right == null)
		return null;
		
		if(t.left == null)
		t = leftRotate(t);
		
		else if(t.right == null)
		t = rightRotate(t);
		
		else{
			if(t.left.priority > t.right.priority)
			t = rightRotate(t);
			else
			t = leftRotate(t);
		}
		return Delete(t,key);
	}
	
	public boolean find(Node p,int x)
	{
		while(p!=null)
		{
			if(p.key==x)return true;
			else if(p.key > x)p = p.left;
			else p = p.right;
		}
		return false;
	}
	
	public void inorder(Node a)
	{
		if(a.left!=null) inorder(a.left);
		System.out.print(" "+a.key);
		if(a.right!=null) inorder(a.right);
		return;
	}
	
	public void preorder(Node p)
	{
		System.out.print(" "+p.key);
		if(p.left!=null) preorder(p.left);
		if(p.right!=null) preorder(p.right);
		return;
	}
	
	public Node rightRotate(Node p)
	{
		Node q = p.left;
		p.left = q.right;
		q.right = p;
		return q;
	}
	
	public Node leftRotate(Node p)
	{
		Node q = p.right;
		p.right = q.left;
		q.left = p;
		return q;
	}
}

public class Main{
	public static void main(String[] args)
	{
		int num ,  x, y;
		String com;
		Tree root = new Tree();
		
		Scanner sc = new Scanner(System.in);
		num = sc.nextInt();
		
		for(int i = 0; i < num; i++)
		{
			com = sc.next();
			switch(com.charAt(0))
			{
			  case 'i':x = sc.nextInt();
				y = sc.nextInt();
				root.insert(x,y);
				break;
			  case 'd':x = sc.nextInt();
				root.delete(x);
				break;
			  case 'f':x = sc.nextInt();
				root.find(x);
				break;
			  case 'p':root.print();
				break;
			}
		}
	}
}

