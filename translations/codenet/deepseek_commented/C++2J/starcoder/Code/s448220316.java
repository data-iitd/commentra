import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws Exception{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		int[] fa=new int[n+1],v=new int[n+1];
		// Initialize the union-find structure with each node as its own parent.
		for(int i=1;i<=n;i++)fa[i]=i;
		// Initialize the value array with 0.
		for(int i=1;i<=m;i++){
			int l=sc.nextInt(),r=sc.nextInt(),vi=sc.nextInt();
			// Read the left node, right node, and value increment for each operation.
			int li=get(l,fa,v),ri=get(r,fa,v);
			// Find the roots of l and r.
			if(li!=ri){
				v[ri]=vi-v[r]+v[l];
				// Update the value of ri based on the values of l and r.
				fa[ri]=li;
				// Set the parent of ri to li.
			}else{
				if(v[r]-v[l]!=vi){
					System.out.println("No");
					return;
					// If the values are inconsistent, print "No" and exit.
				}
			}
		}
		System.out.println("Yes");
		// If all operations are consistent, print "Yes".
	}
	// Main function to execute the union-find structure and value updates.
	public static int get(int x,int[] fa,int[] v){
		if(x==fa[x])return x;
		// Base case: if x is the root of itself, return x.
		int f=get(fa[x],fa,v);
		// Recursively find the root of x's parent.
		v[x]+=v[fa[x]];
		// Update the value of x based on its parent's value.
		return fa[x]=f;
		// Set the parent of x to the root and return the root.
	}
	// Get function to find the root of a node and update the value array.
}

// Main function to execute the union-find structure and value updates.

