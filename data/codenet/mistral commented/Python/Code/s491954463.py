# Define variables n and m as integers
n, m = list(map(int, input().split()))

# Initialize empty lists a and b
a = []
b = []

# Read m pairs of integers from user input and append them to lists a and b
for _ in range(m):
    a1, b1 = list(map(int, input().split()))
    a.append(a1)
    b.append(b1)

# Iterate through each integer i from 1 to n and print the number of occurrences of i in both lists a and b
for i in range(1, n+1):
    # Count the number of occurrences of i in list a
    count_a = a.count(i)
    # Count the number of occurrences of i in list b
    count_b = b.count(i)
    # Print the total number of occurrences of i in both lists a and b
    print(count_a + count_b)