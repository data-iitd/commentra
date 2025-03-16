# Declare variables to hold scores
t = 0
h = 0

# Read the number of rounds
a = int(input())

# Loop through each round
for _ in range(a):
    # Read the names of the players for the current round
    taro, hana = input().split()

    # Get the lengths of the names
    lt = len(taro)
    lh = len(hana)

    # Compare the names and update scores based on the comparison
    if taro > hana:
        t += 3  # Taro wins this round
    elif hana > taro:
        h += 3  # Hana wins this round
    else:  # Tie
        h += 1  # Both get 1 point
        t += 1  # Both get 1 point

# Output the final scores of Taro and Hana
print(t, h)

# <END-OF-CODE>
