
# <START-OF-CODE>

# Read the number of lines to process, ignoring the newline character
n = int(input())

# Loop to process each line of input
while n > 0:
    # Read a line of input from stdin
    s = input()

    # Search for the substring "Hoshino" in the input line
    # Replace the character following "Hoshino" with 'a'
    while "Hoshino" in s:
        s = s.replace("Hoshino", "Hoshinoa", 1)

    # Print the modified line
    print(s)

    n -= 1

# 