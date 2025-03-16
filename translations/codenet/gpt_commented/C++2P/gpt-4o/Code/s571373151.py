# Declare variables for the number of people (n) and the number of food items (m)
n, m = map(int, input().split())  # Input the values of n and m

# Create a list to count the number of people who like each food item
foods = [0] * m

# Loop through each person to gather their food preferences
for _ in range(n):
    k = int(input())  # Number of food items the current person likes

    # Loop through each food item liked by the current person
    for _ in range(k):
        temp = int(input())  # Input the food item index
        temp -= 1  # Convert to zero-based index

        # Increment the count for the corresponding food item
        foods[temp] += 1

# Initialize a counter for the number of food items liked by all people
ans = 0
# Loop through the food counts to find how many are liked by all n people
for elem in foods:
    if elem == n:  # Check if the food item is liked by all n people
        ans += 1  # Increment the answer if the condition is met

# Output the total number of food items liked by all people
print(ans)

# <END-OF-CODE>
