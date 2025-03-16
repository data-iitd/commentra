# This section takes two inputs from the user
input1 = input()
input2 = input()

# This section compares each character of the two inputs
same_count = sum(map(lambda x, y: x == y, input1, input2))

# This section prints the count of positions where the characters are the same
print(same_count)
