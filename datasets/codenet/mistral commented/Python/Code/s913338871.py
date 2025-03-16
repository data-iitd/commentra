# Take an integer N as input from the user
N = int(input())

# Take N number of integers as input and store them in a list a
a = list(map(int, input().split()))

# Sort the list a in ascending order
a.sort()

# Create a new list s which contains the last N/2 elements of the sorted list a
s = a[N::2]

# Print the sum of the elements in the list s
print("The sum of the last", N//2, "elements is:")
print(sum(s))
