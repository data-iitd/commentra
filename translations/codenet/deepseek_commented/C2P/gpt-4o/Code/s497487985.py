# Define a function to calculate the greatest common divisor (GCD)
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

# Define a function to calculate the least common multiple (LCM)
def lcm(a, b):
    return a * b // gcd(a, b)

# Main function
def main():
    n = int(input())  # Number of players
    k = int(input())  # Initial points
    q = int(input())  # Number of queries
    a = [0] * q  # Array to store query results
    point = [0] * n  # Array to store points for each player

    # Process each query to update points
    for i in range(q):
        a[i] = int(input())
        point[a[i] - 1] += 1  # Update points for the player who answered the query

    # Determine if each player can reach the required points
    for i in range(n):
        if k - (q - point[i]) > 0:
            print("Yes")  # Player can reach the required points
        else:
            print("No")  # Player cannot reach the required points

if __name__ == "__main__":
    main()

# <END-OF-CODE>
