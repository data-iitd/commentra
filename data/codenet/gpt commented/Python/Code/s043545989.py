import collections  # Import the collections module to use Counter for counting hashable objects

# Read an integer input N which represents the number of elements in the list
N = int(input())

# Read a list of integers from input and store it in variable 'a'
a = list(map(int, input().split()))

# Create a Counter object to count the occurrences of each element in the list 'a'
B = collections.Counter(a)

# Extract the unique keys (elements) and their corresponding counts (values) from the Counter
k = list(B.keys())
v = list(B.values())

# Check if there are exactly 3 unique elements and they satisfy the conditions for a "Yes" output
if len(B) == 3 and k[0] ^ k[1] ^ k[2] == 0 and v[0] == v[1] == v[2]:
    print("Yes")  # Print "Yes" if the conditions are met
# Check if there are exactly 2 unique elements, one of which is 0, and their counts satisfy the conditions for a "Yes" output
elif len(B) == 2 and 0 in k and (v[0] == 2 * v[1] or v[1] == 2 * v[0]):
    print("Yes")  # Print "Yes" if the conditions are met
# Check if there is only 1 unique element and it is 0, which also qualifies for a "Yes" output
elif len(B) == 1 and 0 in k:
    print("Yes")  # Print "Yes" if the conditions are met
else:
    print("No")  # Print "No" if none of the above conditions are satisfied
