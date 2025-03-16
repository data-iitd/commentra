
n = int(input())  # Take an integer input representing the number of elements
q = []  # Initialize an empty list to store the elements
count = 0  # Initialize a counter to keep track of valid pairs

# Loop to take input and append to the list `q`
for i in range(n):
    a = input().split()  # Split the input into a list of strings
    q.append(a)  # Append the split input to the list `q`

# Nested loop to compare each element with every other element
for j in q:
    for k in q:
        if k == j:  # Skip if the same element is compared with itself
            continue
        elif j[0] == k[len(k) - 1]:  # Check if the first character of `j` matches the last character of `k`
            count += 1  # Increment the counter if the condition is met
        else:
            continue

print(count)  # Print the total count of valid pairs

