import sys; # Importing the sys module for input

n = int(sys.stdin.readline()); # Reading the number of ingredients
m = int(sys.stdin.readline()); # Reading the number of nutrient types
x = int(sys.stdin.readline()); # Reading the minimum requirement for each nutrient
min = 1000000000; # Initializing the minimum cost to a large value
a = []; # Initializing the 2D array to store nutrient amounts

# Filling the array with nutrient amounts for each ingredient
for i in range(n):
    a.append(list(map(int, sys.stdin.readline().split())));

# Generating all possible combinations of ingredients
for i in range(2 ** n):
    status = [0] * n; # Array to store the status of each ingredient in the combination
    for j in range(n):
        if ((1 & i >> j) == 1): # Checking if the j-th ingredient is included
            status[j] = 1;
    res = [0] * (m + 1); # Array to store the total nutrient amounts for the current combination
    for j in range(n):
        if (status[j] == 1): # Adding the nutrient amounts of included ingredients
            for k in range(m + 1):
                res[k] += a[j][k];
    flag = True; # Flag to check if the current combination meets the requirement
    for j in range(1, m + 1):
        if (res[j] < x): # Checking if the nutrient requirement is met
            flag = False;
            break;
    if (flag):
        min = min(min, res[0]); # Updating the minimum cost if the requirement is met

# Outputting the result
if (min == 1000000000):
    print(-1); # Outputting -1 if no combination meets the requirement
else:
    print(min); # Outputting the minimum cost if a valid combination is found

