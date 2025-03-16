# Importing required packages
import re

# Declaring a variable 'a' of type string
a = input()

# Replacing all occurrences of '1' with '0' in the string 'a'
# and storing the result in the variable 'tmp'
tmp = re.sub('1', '0', a)

# Replacing all occurrences of '9' with '1' in the string 'tmp'
# and storing the result in the variable 'b'
b = re.sub('9', '1', tmp)

# Replacing all occurrences of '0' with '9' in the string 'b'
# and storing the result in the variable 'ans'
ans = re.sub('0', '9', b)

# Printing the final answer using print()
print(ans)
