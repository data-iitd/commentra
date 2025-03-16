
a = int(input()) # Read the value of 'a' from standard input
b = int(input()) # Read the value of 'b' from standard input

if a > b:
    result = 2 * a - 1 # If 'a' is greater than 'b', calculate'result' as 2 * 'a' - 1
elif a == b:
    result = 2 * a # If 'a' is equal to 'b', calculate'result' as 2 * 'a'
else:
    result = 2 * b - 1 # If 'a' is less than 'b', calculate'result' as 2 * 'b' - 1

print(result) # Output the value of'result' to standard output

