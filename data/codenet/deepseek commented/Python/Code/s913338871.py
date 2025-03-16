
N = int(input())  # Read an integer N from the user input
a = list(map(int, input().split()))  # Read a list of integers and store it in a
a.sort()  # Sort the list a

# Create a new list s containing elements from a at even indices starting from N
s = [ai for ai in a[N::2]]

# Print the sum of the elements in s
print(sum(s))

