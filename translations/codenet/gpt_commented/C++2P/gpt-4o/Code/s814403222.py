# Import necessary modules
from collections import defaultdict

# Define a list to hold pairs of scores and names
v = []

# Dictionary to hold lists of indices for each score
d = defaultdict(list)

while True:
    n = int(input())  # Read the number of participants
    if n == 0:
        break  # Exit if the number of participants is zero

    # Clear the previous data in the dictionary of lists
    d.clear()
    v = [(0, "") for _ in range(n)]  # Initialize scores and names

    # Loop through each participant
    for i in range(n):
        m = int(input())  # Read the number of scores for the participant
        name = input()  # Read the participant's name
        v[i] = (0, name)  # Initialize the participant's score

        # Loop through each score for the current participant
        for _ in range(m):
            a = int(input())  # Read the score

            # Update the score of the current participant
            v[i] = (v[i][0] + n - len(d[a]), v[i][1])

            # Decrease the score of participants who have already received this score
            for k in d[a]:
                v[k] = (v[k][0] - 1, v[k][1])

            # Add the current participant's index to the list for this score
            d[a].append(i)

    # Sort the participants based on their scores
    v.sort(reverse=True, key=lambda x: (x[0], x[1]))

    # Output the participant with the highest score
    print(v[0][0], v[0][1])

# <END-OF-CODE>
