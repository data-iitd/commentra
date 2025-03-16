
import sys

# Preprocessor directives for standard libraries and namespaces

intmax = sys.maxsize # Macro for maximum integer value
lmax = sys.maxsize # Macro for maximum long integer value
uintmax = sys.maxsize # Macro for maximum unsigned integer value
ulmax = sys.maxsize # Macro for maximum unsigned long integer value
llmax = sys.maxsize # Macro for maximum long long integer value
ll = int # Define long long integer type
rep = range # Macro for repetition of a loop
llfor = i,j # Macro for loop variables declaration
sc = lambda: sys.stdin.readline().rstrip() # Macro for reading an integer value from standard input
pr = lambda x: sys.stdout.write(str(x)+"\n") # Macro for printing a value to standard output
pY = lambda: sys.stdout.write("YES\n") # Macro for printing "YES" to standard output
pN = lambda: sys.stdout.write("NO\n") # Macro for printing "NO" to standard output
py = lambda: sys.stdout.write("Yes\n") # Macro for printing "Yes" to standard output
pn = lambda: sys.stdout.write("No\n") # Macro for printing "No" to standard output
pnn = lambda: sys.stdout.write("\n") # Macro for printing a newline character
all = lambda x: x.begin(),x.end() # Macro for getting the iterator range of a container
push = lambda x,y: x.append(y) # Macro for adding an element to a container
llvec = lambda: [] # Define a 2D vector of long long integers
charvec = lambda: [] # Define a 2D vector of characters
size = lambda a,b: [[a]*b for _ in range(b)] # Macro for creating a vector of size 'b' with default value 'a'
llpvec = lambda: [] # Define a vector of pairs of long long integers
pi = 3.14159265358979323846 # Assign value of pi constant
cei = lambda x,y: (x+y-1)//y # Function for ceiling division
gcd = lambda x,y: y if y else x # Function for finding greatest common divisor
lcm = lambda x,y: x*y//gcd(x,y) # Function for finding least common multiple
llpow = lambda x,n: x**n # Function for exponentiation
fact = lambda x: 1 if x<=1 else x*fact(x-1) # Function for factorial calculation
ncr = lambda n,r: fact(n)//fact(r)//fact(n-r) # Function for calculating nCr
npr = lambda n,r: fact(n)//fact(n-r) # Function for calculating nPr
prime = lambda a: a<=1 or all(a%i for i in range(2,int(a**0.5)+1)) # Function for prime number check
fib = lambda x: 1 if x<=1 else fib(x-1)+fib(x-2) # Function for generating Fibonacci sequence
dig = lambda n: len(str(n)) # Function for finding number of digits

h,w = map(int,sc().split()) # Read height and width from standard input
ans = 0 # Variable declaration

for i in range(h): # Iterate through each row of the grid
    for j in range(w): # Iterate through each column of the grid
        t = sc() # Read a character from standard input
        if t=="snuke": # Check if current character matches the pattern'snuke'
            c = chr(ord('A')+j) # Calculate the column index 'j' of the matching character and convert it to ASCII character
            pr(c+str(i+1)) # Print the character and its row number to standard output
            exit() # Exit the program if a match is found

Translate the above Python code to C++ and end with comment "