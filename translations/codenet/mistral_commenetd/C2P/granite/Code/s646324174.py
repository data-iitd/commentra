
# Initialize stack top to 0
top = 0
S = []

# Function to push an element onto the stack
def push(x):
 # Append the element to the stack
 S.append(x)

# Function to pop an element from the stack
def pop():
 # Return the top element and remove it from the stack
 return S.pop()

# Main function
def main():
 # Initialize variables
 a, b = 0, 0
 s = ""

 # Initialize stack top to 0
 top = 0
 S = []

 # Read input until end of file
 while True:
 try:
 # Read the input
 s = input()

 # Check if the input is an operator or a number
 if s[0]=='+':
 # Pop the top two elements from the stack
 b = pop()
 a = pop()

 # Perform the operation and push the result back onto the stack
 push(a+b)
 elif s[0]=='-':
 b = pop()
 a = pop()
 push(a-b)
 elif s[0]=='*':
 b = pop()
 a = pop()
 push(a*b)
 else: # Input is a number
 # Push the number directly onto the stack
 push(int(s))
 except EOFError:
 # Print the final result
 print(pop())

 # Return 0 to indicate successful execution
 return 0

