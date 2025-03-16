

num = int(input()) # Read the size of the grid
counter = 0 # Counter for the number of 'C's
fine = 0 # Fine amount to be calculated
arr = [] # ArrayList to store the grid rows

# Read num strings representing the grid rows
for i in range(num):
    s = input()
    arr.append(s)

# Calculate the fine for each column
for i in range(num):
    for k in range(num):
        if arr[k][i] == 'C':
            counter += 1
    fine += (counter * (counter - 1)) // 2 # Calculate the fine for the column
    counter = 0 # Reset the counter for the next column

# Calculate the fine for each row
for i in range(num):
    for k in range(num):
        if arr[i][k] == 'C':
            counter += 1
    fine += (counter * (counter - 1)) // 2 # Calculate the fine for the row
    counter = 0 # Reset the counter for the next row

# Print the total fine
print(fine) # 