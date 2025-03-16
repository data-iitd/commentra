import sys

def solve(x, u):
    # Convert each amount to a standard currency and sum them up
    return sum(x[i] * (1 if u[i] == "JPY" else 380000) for i in range(len(x)))

if __name__ == "__main__":
    # Read the number of currency entries
    N = int(input())

    # Initialize arrays to hold the amounts and their corresponding currency units
    x = [0] * N
    u = [0] * N

    # Loop to read each amount and its currency unit
    for i in range(N):
        x[i], u[i] = map(float, input().split())

    # Calculate the total value in a standard currency and print the result
    print(solve(x, u))

