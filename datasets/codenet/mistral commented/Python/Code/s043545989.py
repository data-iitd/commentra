
import collections # Import the collections module

N = int(input()) # Read the value of N from the standard input
a = list(map(int,input().split())) # Read a line of text from the standard input and convert it to a list of integers
B = collections.Counter(a) # Create a Counter object from the list of integers

# Extract the keys and values from the Counter object
k = list(B.keys())
v = list(B.values())

# Check if the length of the Counter is 3, and if all the keys have a bitwise XOR equal to 0, and if all the values are equal
if len(B) == 3 and k[0]^k[1]^k[2] == 0 and v[0] == v[1] == v[2]:
    print("Yes") # If all conditions are met, print "Yes"
# Check if the length of the Counter is 2, and if 0 is one of the keys, and if either of the values is twice the other
elif len(B) == 2 and 0 in k and (v[0] == 2*v[1] or v[1] == 2*v[0]):
    print("Yes") # If all conditions are met, print "Yes"
# Check if the length of the Counter is 1, and if 0 is one of the keys
elif len(B) == 1 and 0 in k:
    print("Yes") # If all conditions are met, print "Yes"
# If none of the above conditions are met, print "No"
else: print("No")