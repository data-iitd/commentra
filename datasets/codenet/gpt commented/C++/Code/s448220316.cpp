#include<iostream>
#include<cstdio>
using namespace std;

// Function to read an integer from input
inline int read(){
    int k=0, f=1; // Initialize value and sign
    char ch=getchar(); // Read a character from input
    // Skip non-digit characters and check for negative sign
    while(ch<'0'||ch>'9'){ 
        if(ch=='-') f=-1; // Set sign if negative
        ch=getchar(); // Read next character
    }
    // Construct the integer from the digits read
    while(ch>='0'&&ch<='9'){ 
        k=k*10+ch-'0'; // Build the number
        ch=getchar(); // Read next character
    }
    return k*f; // Return the final integer with sign
}

// Function to write an integer to output
inline void write(int x){
    if(x<0) x=-x, putchar('-'); // Print negative sign if needed
    if(x>9) write(x/10); // Recursively write the digits
    putchar(x%10+'0'); // Print the last digit
}

// Function to write an integer followed by a newline
inline void writeln(int x){
    write(x); // Write the integer
    puts(""); // Print a newline
}

// Global variables for number of nodes, edges, and other parameters
int n, m, l, r, vi, fa[100005], v[200005];

// Function to find the representative of a set and update the value
inline int get(int x){
    if(x==fa[x]) return x; // If x is its own parent, return it
    int f=get(fa[x]); // Recursively find the root
    v[x]+=v[fa[x]]; // Update the value based on the parent
    return fa[x]=f; // Path compression
}

int main(){
    n=read(); // Read number of nodes
    m=read(); // Read number of edges
    // Initialize the parent array for union-find
    for(int i=1; i<=n; i++) fa[i]=i; 
    // Process each edge
    for(int i=1; i<=m; i++){
        l=read(); // Read left node
        r=read(); // Read right node
        vi=read(); // Read value to be assigned
        int li=get(l), ri=get(r); // Find representatives of both nodes
        // If they belong to different sets, union them
        if(li!=ri){
            v[ri]=vi-v[r]+v[l]; // Update the value for the new root
            fa[ri]=li; // Union the sets
        } else {
            // If they are in the same set, check for consistency
            if(v[r]-v[l]!=vi){
                cout<<"No\n"; // Inconsistent values
                return 0; // Exit the program
            }
        }
    }
    cout<<"Yes\n"; // All edges processed successfully
    return 0; // Exit the program
}
