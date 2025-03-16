

#include<stdio.h>

// Inline function to read an integer from standard input
inline int read(){
	int k=0,f=1;char ch=getchar();
	// Initialize variables for reading an integer
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1; // Handle negative sign
		ch=getchar(); // Read next character
	}
	// Read digits and store them in 'k'
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	// Multiply the number by the sign and return it
	return k*f;
}

// Inline function to write an integer to standard output
inline void write(int x){
	if(x<0)x=-x; // Handle negative numbers
	// Write the digit in reverse order
	if(x>9)write(x/10);
	putchar(x%10+'0'); // Write the current digit
}

// Inline function to write an integer and a newline to standard output
inline void writeln(int x){
	write(x); // Write the integer
	puts(""); // Write a newline
}

// Initialize variables
int n,m,l,r,vi,fa[100005],v[200005];

// Inline function to get the root of a tree
inline int get(int x){
	if(fa[x]==x)return x; // Base case: the root of the tree is itself
	// Recursively find the root of the tree
	int f=get(fa[x]);
	// Update the depth of the nodes on the path from 'x' to the root
	v[x]+=v[fa[x]];
	// Update the father of 'x'
	fa[x]=f;
	return f;
}

// Main function
int main(){
	// Read the number of vertices 'n' and edges'm'
	n=read();m=read();
	// Initialize the trees for each vertex
	for(int i=1;i<=n;i++)fa[i]=i;
	// Process each edge
	for(int i=1;i<=m;i++){
		// Read the left and right endpoints and the value 'vi' of the edge
		l=read();r=read();vi=read();
		// Find the roots of the trees of the left and right endpoints
		int li=get(l),ri=get(r);
		// If the roots are different, update the depth of the right tree and its father
		if(li!=ri){
			v[ri]+=vi-v[r]+v[l]; // Update the depth of the right tree
			fa[ri]=li; // Set the father of the right tree to the father of the left tree
		}else{
			// If the roots are the same, check if the value of the edge is correct
			if(v[r]-v[l]!=vi){
				printf("No\n"); // Output 'No' if the value is incorrect
				return 0; // Terminate the program
			}
		}
	}
	// Output 'Yes' if all edges have the correct value
	printf("Yes\n");
	return 0;
}
