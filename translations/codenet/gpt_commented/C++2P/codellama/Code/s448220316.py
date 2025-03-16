#include<iostream>
#include<cstdio>
using namespace std;

# Function to read an integer from input
def read():
    k=0; f=1; # Initialize value and sign
    ch=getchar(); # Read a character from input
    # Skip non-digit characters and check for negative sign
    while ch<'0' or ch>'9':
        if ch=='-': f=-1; # Set sign if negative
        ch=getchar(); # Read next character
    # Construct the integer from the digits read
    while ch>='0' and ch<='9':
        k=k*10+ch-'0'; # Build the number
        ch=getchar(); # Read next character
    return k*f; # Return the final integer with sign

# Function to write an integer to output
def write(x):
    if x<0: x=-x, putchar('-'); # Print negative sign if needed
    if x>9: write(x/10); # Recursively write the digits
    putchar(x%10+'0'); # Print the last digit

# Function to write an integer followed by a newline
def writeln(x):
    write(x); # Write the integer
    puts(""); # Print a newline

# Global variables for number of nodes, edges, and other parameters
n=read(); # Read number of nodes
m=read(); # Read number of edges
# Initialize the parent array for union-find
for i in range(1, n+1): fa[i]=i; 
# Process each edge
for i in range(1, m+1):
    l=read(); # Read left node
    r=read(); # Read right node
    vi=read(); # Read value to be assigned
    li=get(l); # Find representatives of both nodes
    ri=get(r);
    # If they belong to different sets, union them
    if li!=ri:
        v[ri]=vi-v[r]+v[l]; # Update the value based on the parent
        fa[ri]=li; # Union the sets
    else:
        # If they are in the same set, check for consistency
        if v[r]-v[l]!=vi:
            cout<<"No\n"; # Inconsistent values
            return 0; # Exit the program

cout<<"Yes\n"; # All edges processed successfully
return 0; # Exit the program

