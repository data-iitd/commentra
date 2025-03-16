import sys
from math import gcd

# Function to calculate the least common multiple (LCM) using GCD
def lcm(a, b):
    return a * b // gcd(a, b)  # LCM formula

# Main function
def main():
    n = int(input())  # Number of participants
    k = int(input())  # Points required to win
    q = int(input())  # Number of questions
    a = list(map(int, input().split()))  # Array to store the questions
    point = [0] * n  # Array to track points of each participant

    # Process each question and update points for the corresponding participant
    for i in range(q):
        participant = a[i]  # Read the participant number for the question
        point[participant - 1] += 1  # Increment the point for the participant who answered

    # Determine if each participant has enough points to win
    for i in range(n):
        if k - (q - point[i]) > 0:  # Check if the participant has enough points
            print("Yes")  # Participant can win
        else:
            print("No")  # Participant cannot win

if __name__ == "__main__":
    main()

# <END-OF-CODE>
