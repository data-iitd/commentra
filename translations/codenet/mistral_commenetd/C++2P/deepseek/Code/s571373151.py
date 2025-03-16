# Declare variables
n, m = map(int, input().split())

# Initialize a list to store the count of each food item
foods = [0] * m

# Read n food preferences from the standard input
for _ in range(n):
    k = list(map(int, input().split()))
    k.pop(0)  # Remove the first element which is the count of food items

    # Increment the count of the corresponding food item in the foods list
    for food_index in k:
        foods[food_index - 1] += 1

# Initialize a variable to store the number of food items that appear in all preferences
ans = 0

# Iterate through each element in the foods list and check if its count is equal to the total number of preferences
for count in foods:
    if count == n:
        ans += 1

# Print the value of ans to the standard output
print(ans)
