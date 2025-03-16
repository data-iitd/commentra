// Importing required packages
import sys

// Declaring a variable 'a' of type string
a = sys.stdin.readline().strip()

// Reading a string input from the user using sys.stdin.readline()

// Declaring a temporary variable 'tmp' of type string
tmp = a.replace("1", "0")

// Replacing all occurrences of '1' with '0' in the string 'a'
// and storing the result in the variable 'tmp'

b = tmp.replace("9", "1")

// Replacing all occurrences of '9' with '1' in the string 'tmp'
// and storing the result in the variable 'b'

ans = b.replace("0", "9")

// Replacing all occurrences of '0' with '9' in the string 'b'
// and storing the result in the variable 'ans'

// Printing the final answer using print()
print(ans)

