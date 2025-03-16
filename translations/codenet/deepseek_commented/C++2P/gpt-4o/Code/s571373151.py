n, m = map(int, input().split())  # Read the number of people and the number of food types

foods = [0] * m  # Initialize a list to keep track of food counts

for _ in range(n):  # Loop through each person
    k = int(input())  # Read the number of food preferences for this person

    for _ in range(k):  # Loop through each food preference
        temp = int(input())  # Read the type of food
        temp -= 1  # Adjust the food type to be 0-indexed

        foods[temp] += 1  # Increment the count of this food type

ans = 0  # Initialize a counter for food types preferred by all people

for elem in foods:  # Loop through each food type count
    if elem == n:  # Check if the food type is preferred by all people
        ans += 1  # Increment the counter

print(ans)  # Output the number of food types preferred by all people
# <END-OF-CODE>
