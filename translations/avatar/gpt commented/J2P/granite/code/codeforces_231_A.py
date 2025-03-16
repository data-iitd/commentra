
t = int(input()) # Reading the number of test cases
count = 0 # Initializing a counter to keep track of valid cases

# Looping through each test case
while t > 0:
    a, b, c = map(int, input().split()) # Reading the three integers and storing them in variables a, b, and c
    if (a == 1 and b == 1) or (a == 1 and c == 1) or (b == 1 and c == 1) or (a == 1 and b == 1 and c == 1):
        count += 1 # Incrementing the count if the condition is met
    t -= 1 # Decrementing the test case counter

# Outputting the total count of valid cases
print(count)
