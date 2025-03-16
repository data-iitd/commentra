from typing import List, Tuple

# Define a pair type to hold an integer and a string
Pair = Tuple[int, str]

# Array to hold pairs of scores and names
v = [None] * 22

# List to hold lists of indices for each number
d = [[] for _ in range(33)]

def main():
    while True:
        n = int(input())  # Variable to hold the number of participants
        if n == 0:
            break

        m = int(input())  # Variable to hold the number of scores for each participant

        # Clear the previous data in the vector of lists
        for i in range(33):
            d[i].clear()

        # Loop through each participant
        for i in range(n):
            v[i] = (0, input().split()[0])  # Initialize the score of the participant to zero

            # Read the participant's name and the number of scores
            scores = list(map(int, input().split()))
            scores.pop(0)  # Remove the number of scores from the list

            # Loop through each score for the current participant
            for j in scores:
                # Update the score of the current participant
                v[i] = (v[i][0] + n - len(d[j]), v[i][1])

                # Decrease the score of participants who have already received this score
                for k in d[j]:
                    v[k] = (v[k][0] - 1, v[k][1])

                # Add the current participant's index to the list for this score
                d[j].append(i)

        # Sort the participants based on their scores
        v.sort(key=lambda x: x[0])

        # Output the participant with the highest score
        print(v[0][0], v[0][1])

if __name__ == "__main__":
    main()
