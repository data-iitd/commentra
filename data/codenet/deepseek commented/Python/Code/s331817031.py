# Step 1: Read the input values for height (h) and width (w).
h, w = map(int, input().split())

# Step 2: Initialize an empty list (l) to store the grid.
l = []

# Step 3: Use a for loop to read each row of the grid and append it to the list (l).
for _ in range(h):
    a = list(map(str, input()))
    l.append(a)

# Step 4: Initialize a variable (tmp) to keep track of the position.
tmp = 0

# Step 5: Use nested for loops to iterate through each element of the grid.
for i in range(h):
    for j in range(w):
        # Step 6: Check if the current element is a "#".
        if l[i][j] == "#":
            # Step 7: If the current column position (j) is less than the stored position (tmp), print "Impossible" and exit.
            if j < tmp:
                print("Impossible")
                exit()
            else:
                # Step 8: Update the stored position (tmp) with the current column position (j).
                tmp = j

# Step 9: If the loop completes without any issues, print "Possible".
print("Possible")
