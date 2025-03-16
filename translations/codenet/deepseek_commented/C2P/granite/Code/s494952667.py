
str = input("Enter a string: ")
len = len(str)

# Reverse the string and print it
for i in range(len - 1, -1, -1):
    print(str[i], end="")

print() # Print a newline character at the end

