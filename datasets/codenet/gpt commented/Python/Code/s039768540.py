# Prompt the user for input and convert it to an integer
x = int(input())

# Generate a string that consists of "ai1333" followed by the character "3" repeated (x // 100) times
# This means if x is 300, it will append "3" three times, resulting in "ai1333333"
print("ai1333{}".format("3" * (x // 100)))
