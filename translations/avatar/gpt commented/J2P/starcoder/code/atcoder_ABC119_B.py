import sys

def solve(x, u):
    return sum(x[i] * (1 if u[i] == "JPY" else 380000) for i in range(len(x)))

if __name__ == "__main__":
    # Read the number of currency entries
    N = int(input())
    
    # Initialize arrays to hold the amounts and their corresponding currency units
    x = [0] * N
    u = [""] * N
    
    # Loop to read each amount and its currency unit
    for i in range(N):
        x[i] = float(input()) # Read the amount
        u[i] = input() # Read the currency unit
    
    # Calculate the total value in a standard currency and print the result
    print(solve(x, u))

# 