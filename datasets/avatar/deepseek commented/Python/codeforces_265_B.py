n = int(input())  # Read the number of elements in the list
l = []  # Initialize an empty list to store the elements

# Read n elements and append them to the list l
for i in range(n):
    l.append(int(input()))

ans = n - 1  # Initialize ans to n - 1, which will store the final answer
last = 0  # Initialize last to 0, used to track the last element in the list

# Iterate over each element in the list l
for i in l:
    ans += abs(last - i) + 1  # Update ans based on the current element and last element
    last = i  # Update last to the current element

print(ans)  # Print the final answer
