# Importing required packages
import sys

# Declaring a variable 'a' of type string
a = input()

# Replacing all occurrences of '1' with '0' in the string 'a'
tmp = a.replace("1", "0")

# Replacing all occurrences of '9' with '1' in the string 'tmp'
b = tmp.replace("9", "1")

# Replacing all occurrences of '0' with '9' in the string 'b'
ans = b.replace("0", "9")

# Printing the final answer
print(ans)

# <END-OF-CODE>
