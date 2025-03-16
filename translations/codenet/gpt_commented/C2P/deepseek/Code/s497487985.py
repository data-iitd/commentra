# Define the maximum and minimum macros
def max(x, y):
    return x if x > y else y

def min(x, y):
    return x if x < y else y

# Function to calculate the greatest common divisor (GCD) using recursion
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

# Function to calculate the least common multiple (LCM) using GCD
def lcm(a, b):
    return a * b // gcd(a, b)

# Main function
def main():
    n = int(input())  # Number of participants
    k = int(input())  # Points required to win
    q = int(input())  # Number of questions
    a = [int(input()) for _ in range(q)]  # Array to store the questions
    point = [0] * (n + 1)  # Array to track points of each participant

    # Process each question and update points for the corresponding participant
    for i in range(q):
        participant = a[i]
        point[participant] += 1

    # Determine if each participant has enough points to win
    for i in range(1, n + 1):
        if k - (q - point[i]) > 0:  # Check if the participant has enough points
            print("Yes")  # Participant can win
        else:
            print("No")  # Participant cannot win

# Call the main function
main()
