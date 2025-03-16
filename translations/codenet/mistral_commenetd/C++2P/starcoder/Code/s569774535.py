
# Initialize an integer variable 'n' to store the number of elements in the vector 'a'
n = int(input())

# Allocate memory for the vector 'a' of size 'n'
a = [0]*n

# Read 'n' integers from the standard input and store them in the vector 'a'
for i in range(n):
    a[i] = int(input())

ans = 0 # Initialize an integer variable 'ans' to store the answer
ok = True # Initialize a boolean variable 'ok' to keep track of the loop condition

# Main logic of the program starts here
while ok:
    for i in range(n): # Iterate through all the elements in the vector 'a'
        if a[i]%2 == 1: # Check if the 'i'-th element of the vector 'a' is odd
            print(ans) # If yes, print the answer and exit the program
            exit(0)
        else: # If the 'i'-th element of the vector 'a' is even, divide it by 2
            a[i] /= 2
    ans += 1 # Increment the answer by 1 for each iteration of the outer loop
    ok = False # Set the loop condition to false to exit the loop if all elements in the vector 'a' become even

# Print the final answer if all elements in the vector 'a' become even
print(ans)

