# Define macros for maximum and minimum values
def max(x, y):
    return x if x > y else y

def min(x, y):
    return x if x < y else y

# Function to compare integers in descending order
def compare_int(a, b):
    return b - a  # Descending order

# Function to calculate the greatest common divisor (GCD)
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

# Function to calculate the least common multiple (LCM)
def lcm(a, b):
    return a * b // gcd(a, b)

# Main function
def main():
    n = int(input())  # Number of players
    k = int(input())  # Initial points
    q = int(input())  # Number of queries
    a = [int(input()) for _ in range(q)]  # Array to store query results
    point = [0] * (n + 1)  # Array to store points for each player

    # Process each query to update points
    for query in a:
        point[query - 1] += 1  # Update points for the player who answered the query

    # Determine if each player can reach the required points
    for i in range(n):
        if k - (q - point[i]) > 0:
            print("Yes")  # Player can reach the required points
        else:
            print("No")  # Player cannot reach the required points

main()
