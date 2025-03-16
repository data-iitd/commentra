# Declare three strings A, B, and C to store strings A, B, and C
A = input().split()
B = input().split()
C = input().split()

# Calculate the length of strings A and B using len function and store the lengths in la and lb respectively
la = len(A)
lb = len(B)
lc = len(C)

# Logical block to check if the last character of string A is same as the first character of string B
# and the last character of string B is same as the first character of string C
if A[-1] == B[0] and B[-1] == C[0]:
    # If the condition is true, print YES on the console
    print("YES")
# Logical block to check if the condition in if block is false
else:
    # If the condition is false, print NO on the console
    print("NO")

# Return 0 to indicate successful execution of the program
