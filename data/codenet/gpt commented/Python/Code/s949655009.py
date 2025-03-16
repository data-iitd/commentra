# Get input from the user and convert it to an integer
strn = input()
n = int(strn)

# Define a list of valid digits for the "shichigo" numbers
shichigolist = ["3", "5", "7"]

# Initialize a list to hold combinations of "shichigo" numbers for each digit position
shichigo = [[] for _ in range(len(strn))]

# Generate all possible combinations of "shichigo" numbers
for i in range(len(strn)):
    if i == 0:
        # For the first digit position, directly add the valid digits
        for j in shichigolist:
            shichigo[i].append(j)
    else:
        # For subsequent digit positions, append valid digits to previous combinations
        for j in shichigo[i-1]:
            for k in shichigolist:
                shichigo[i].append(j + k)

# Set the target index to the last digit position
target = len(strn) - 1

# Filter out invalid combinations based on the target number
for i in range(len(strn)):
    for j in shichigo[i][:]:  # Iterate over a copy of the list to avoid modification issues
        if i == target:
            # For the last digit position, check if the number exceeds 'n' or lacks required digits
            if int(j) > n:
                shichigo[target].remove(j)  # Remove if it exceeds 'n'
            elif j.count("3") == 0 or j.count("5") == 0 or j.count("7") == 0:
                shichigo[target].remove(j)  # Remove if it lacks any of the required digits
        else:
            # For other digit positions, remove combinations that lack required digits
            if j.count("3") == 0 or j.count("5") == 0 or j.count("7") == 0:
                shichigo[i].remove(j)

# Calculate and print the total number of valid "shichigo" combinations
print(sum([len(shichigo[i]) for i in range(len(strn))]))
