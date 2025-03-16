# Step 1: Taking input from the user
h, a = map(int, input().split(" "))

# Step 2: Calculating the number of times 'a' fits into 'h' and the remainder
sho = int(h / a)
am = int(h % a)

# Step 3: Checking if there is a remainder and incrementing the count if necessary
if am != 0:
    sho += 1
else:
    pass

# Step 4: Printing the result
print(sho)
