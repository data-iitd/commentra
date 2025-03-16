# Declare variables
n, m = map(int, input().split())

# Initialize a list of size m to store the count of each food item
foods = [0] * m

# Read n food preferences from the standard input
for _ in range(n):
    k = int(input())
    
    # Read the indices of the food items in the current preference
    for _ in range(k):
        temp = int(input())
        
        # Increment the count of the corresponding food item in the foods list
        foods[temp] += 1

# Initialize a variable to store the number of food items that appear in all preferences
ans = 0

# Iterate through each element in the foods list and check if its count is equal to the total number of preferences
for elem in foods:
    if elem == n:
        ans += 1

# Print the value of ans to the standard output
print(ans)

# <END-OF-CODE>
