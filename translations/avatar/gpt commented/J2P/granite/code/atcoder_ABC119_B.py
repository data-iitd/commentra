
import sys

def solve(x, u):
    # Convert each amount to a standard currency and sum them up
    return sum(x[i] * (1 if u[i] == "JPY" else 380000) for i in range(len(x)))

def main():
    # Read the number of currency entries
    N = int(input())

    # Initialize arrays to hold the amounts and their corresponding currency units
    x = []
    u = []

    # Loop to read each amount and its currency unit
    for _ in range(N):
        line = input().split()
        x.append(float(line[0]))
        u.append(line[1])

    # Calculate the total value in a standard currency and print the result
    print(solve(x, u))

if __name__ == "__main__":
    main()