
# Function to read a long long integer from input
def read():   
    x=0; f=1; 
    ch=getchar();   
    # Read characters until a digit or '-' is found
    while(ch<'0' or ch>'9'): 
        if(ch=='-'): f=-1; # Check for negative sign
        ch=getchar();
    # Convert the digits to a long long integer
    while(ch>='0' and ch<='9'): 
        x=x*10+ch-'0'; 
        ch=getchar();
    return x*f; # Return the final value with sign

# Function to write a long long integer to output
def write(x):    
    if (x<0): putchar('-'), x=-x; # Print negative sign if needed
    if (x>=10): write(x/10);   # Recursively write the digits
    putchar(x%10+'0');  # Print the last digit

# Function to write a long long integer followed by a newline
def writeln(x): 
    write(x);   
    print("");   # Print a newline

n=read(); # Read the number of elements
a=[0]*(n+1); # Declare an array of size n+1
for i in range(1,n+1): a[i]=read(); # Read the elements into the array a
a.sort(); # Sort the array in non-decreasing order

# Identify duplicates and store them in array q
q=[0]*(n+1);
tot=0;
for i in range(1,n+1): 
    if (a[i]==a[i+1]): 
        q[tot]=a[i]; # Store the duplicate
        i+=1; # Skip the next element
    tot+=1;

# Output the product of the last two duplicates found
writeln(q[tot]*q[tot-1]);

