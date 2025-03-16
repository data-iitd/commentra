# Declare variables for storing team names and initialize scores
t = []
h = []
n = int(input())
taro = 0
hanako = 0

# Loop through each round to read team names and calculate scores
for i in range(n):
    # Read team names for both players
    team_taro = input().strip()
    team_hanako = input().strip()
    
    # Compare team names and update scores based on the comparison
    if team_taro < team_hanako:
        # If Hanako's team name is lexicographically smaller, she gets 3 points
        hanako += 3
    elif team_taro > team_hanako:
        # If Taro's team name is lexicographically larger, he gets 3 points
        taro += 3
    else:
        # If both team names are the same, both players get 1 point
        taro += 1
        hanako += 1

# Output the final scores of Taro and Hanako
print(taro, hanako)

# <END-OF-CODE>
