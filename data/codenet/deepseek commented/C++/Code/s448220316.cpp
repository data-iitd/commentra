#include<iostream>
#include<cstdio>
using namespace std;

// Include headers for input/output operations.

inline int read(){
	int k=0,f=1;char ch=getchar();
	// Initialize variables to read integers efficiently.
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	// Skip non-digit characters and handle negative numbers.
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	// Convert characters to digits and accumulate the result.
	return k*f;
	// Return the integer value, considering its sign.
}

// Read function to efficiently read integers.

inline void write(int x){
	if(x<0)x=-x,putchar('-');
	// Handle negative numbers by converting them to positive.
	if(x>9)write(x/10);
	// Recursively write the digits of the number.
	putchar(x%10+'0');
	// Write the last digit.
}

// Write function to efficiently write integers.

inline void writeln(int x){
	write(x);puts("");
	// Write the integer and then print a newline.
}

// Writeln function to write integers and print a newline.

int n,m,l,r,vi,fa[100005],v[200005];

// Declare global variables for the number of nodes, number of operations, and arrays for union-find structure and values.

inline int get(int x){
	if(x==fa[x])return x;
	// Base case: if x is the root of itself, return x.
	int f=get(fa[x]);
	// Recursively find the root of x's parent.
	v[x]+=v[fa[x]];
	// Update the value of x based on its parent's value.
	return fa[x]=f;
	// Set the parent of x to the root and return the root.
}

// Get function to find the root of a node and update the value array.

int main(){
	n=read();m=read();
	// Read the number of nodes and operations.
	for(int i=1;i<=n;i++)fa[i]=i;
	// Initialize the union-find structure with each node as its own parent.
	for(int i=1;i<=m;i++){
		l=read();r=read();vi=read();
		// Read the left node, right node, and value increment for each operation.
		int li=get(l),ri=get(r);
		// Find the roots of l and r.
		if(li!=ri){
			v[ri]=vi-v[r]+v[l];
			// Update the value of ri based on the values of l and r.
			fa[ri]=li;
			// Set the parent of ri to li.
		}else{
			if(v[r]-v[l]!=vi){
				cout<<"No\n";
				return 0;
				// If the values are inconsistent, print "No" and exit.
			}
		}
	}
	cout<<"Yes\n";
	// If all operations are consistent, print "Yes".
	return 0;
}

// Main function to execute the union-find structure and value updates.
