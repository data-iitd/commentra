# Function to read an integer from input
def read():
    k=0; f=1; # Initialize value and sign
    ch=input(); # Read a character from input
    # Skip non-digit characters and check for negative sign
    while(ch<'0' or ch>'9'): 
        if(ch=='-'): f=-1; # Set sign if negative
        ch=input(); # Read next character
    # Construct the integer from the digits read
    while(ch>='0' and ch<='9'): 
        k=k*10+ch-'0'; # Build the number
        ch=input(); # Read next character
    return k*f; # Return the final integer with sign

# Function to write an integer to output
def write(x):
    if(x<0): x=-x; putchar('-'); # Print negative sign if needed
    if(x>9): write(x/10); # Recursively write the digits
    putchar(x%10+'0'); # Print the last digit

# Function to write an integer followed by a newline
def writeln(x):
    write(x); # Write the integer
    print(""); # Print a newline

# Global variables for number of nodes, edges, and other parameters
n=0; m=0; l=0; r=0; vi=0; fa=[0]*100005; v=[0]*200005;

# Function to find the representative of a set and update the value
def get(x):
    if(x==fa[x]): return x; # If x is its own parent, return it
    f=get(fa[x]); # Recursively find the root
    v[x]+=v[fa[x]]; # Update the value based on the parent
    return fa[x]=f; # Path compression

# Main program
n=read(); # Read number of nodes
m=read(); # Read number of edges
# Initialize the parent array for union-find
for i in range(1,n+1): fa[i]=i; 
# Process each edge
for i in range(1,m+1):
    l=read(); # Read left node
    r=read(); # Read right node
    vi=read(); # Read value to be assigned
    li=get(l); ri=get(r); # Find representatives of both nodes
    # If they belong to different sets, union them
    if(li!=ri):
        v[ri]=vi-v[r]+v[l]; # Update the value for the new root
        fa[ri]=li; # Union the sets
    else:
        # If they are in the same set, check for consistency
        if(v[r]-v[l]!=vi):
            print("No"); # Inconsistent values
            return 0; # Exit the program
print("Yes"); # All edges processed successfully
return 0; # Exit the program

