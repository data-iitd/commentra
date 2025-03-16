# Read the values of 'a' and 'b' from standard input
a = int(input())  # Read the value of 'a' and convert it to an integer
b = int(input())  # Read the value of 'b' and convert it to an integer

# Determine the value of 'result' based on the values of 'a' and 'b'
if a > b:
    result = 2 * a - 1  # If 'a' is greater than 'b', calculate 'result' as 2 * 'a' - 1
elif a == b:
    result = 2 * a      # If 'a' is equal to 'b', calculate 'result' as 2 * 'a'
else:
    result = 2 * b - 1  # If 'a' is less than 'b', calculate 'result' as 2 * 'b' - 1

print(result)  # Output the value of 'result' to standard output

# <END-OF-CODE>
