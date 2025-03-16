import sys

MOD = 1000000007  # Constants definition

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Number of elements
    c = int(data[1])  # Capacity

    x = [0] * (n + 1)  # Initialize x array
    v = [0] * (n + 1)  # Initialize v array

    for i in range(1, n + 1):
        x[i] = int(data[2 + (i - 1) * 2])  # Read x[i]
        v[i] = int(data[2 + (i - 1) * 2 + 1])  # Read v[i]

    # Calculate left prefix sums
    lefttotal = [0] * (n + 1)
    maxlefttotal = [0] * (n + 1)
    for i in range(1, n + 1):
        lefttotal[i] = lefttotal[i - 1] + v[i]  # Prefix sums of v
        maxlefttotal[i] = max(maxlefttotal[i - 1], lefttotal[i] - x[i])  # Maximum prefix sums

    # Calculate right prefix sums
    righttotal = [0] * (n + 1)
    maxrighttotal = [0] * (n + 1)
    for i in range(1, n + 1):
        righttotal[i] = righttotal[i - 1] + v[n - i + 1]  # Prefix sums of reversed v
        maxrighttotal[i] = max(maxrighttotal[i - 1], righttotal[i] - (c - x[n + 1 - i]))  # Maximum prefix sums

    # Calculate answer
    ans = 0
    for i in range(1, n + 1):
        ans = max(ans, lefttotal[i] - x[i])  # Include current element in left sum
        ans = max(ans, lefttotal[i] - 2 * x[i] + maxrighttotal[n - i])  # Exclude current element in left sum and include in right sum
        ans = max(ans, righttotal[i] - (c - x[n + 1 - i]))  # Include current element in right sum
        ans = max(ans, righttotal[i] - 2 * (c - x[n + 1 - i]) + maxlefttotal[n - i])  # Exclude current element in right sum and include in left sum

    # Output answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
