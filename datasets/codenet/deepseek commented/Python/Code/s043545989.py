
import collections

# Read the number of elements in the list
N = int(input())

# Read the list of integers
a = list(map(int, input().split()))

# Create a Counter object to count the frequency of each element in the list
B = collections.Counter(a)

# Extract the keys (unique elements) and values (counts of each element) from the Counter object
k = list(B.keys())
v = list(B.values())

# Check the conditions based on the properties of the Counter object
if len(B) == 3 and k[0] ^ k[1] ^ k[2] == 0 and v[0] == v[1] == v[2]:
    # If the length of the Counter is 3, and the XOR of all keys is 0, and all values are equal
    print("Yes")
elif len(B) == 2 and 0 in k and (v[0] == 2 * v[1] or v[1] == 2 * v[0]):
    # If the length of the Counter is 2, and 0 is one of the keys, and the values satisfy a specific relationship
    print("Yes")
elif len(B) == 1 and 0 in k:
    # If the length of the Counter is 1, and 0 is one of the keys
    print("Yes")
else:
    # If none of the above conditions are met
    print("No")