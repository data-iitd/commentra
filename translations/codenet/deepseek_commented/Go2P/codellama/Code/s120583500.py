
# Step 1: The program starts by taking a string input from the user.
s = input()

# Step 2: It initializes a counter to keep track of the lengths of consecutive valid characters.
count = 0

# Step 3: It checks if the input string is empty and returns immediately if it is.
if s == "":
    return

# Step 4: It splits the input string into individual characters.
li = list(s)

# Step 5: It iterates through each character in the split string, incrementing the count for valid characters and resetting the count for invalid characters.
for s in li:
    if s == "A" or s == "C" or s == "G" or s == "T":
        count += 1
    else:
        counter.append(count)
        count = 0

# Step 6: It appends the final count to the counter array and sorts the array.
counter.append(count)
counter.sort()

# Step 7: Finally, it prints the maximum value in the sorted counter array.
print(counter[len(counter)-1])

