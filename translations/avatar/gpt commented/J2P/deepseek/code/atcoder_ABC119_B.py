def solve(x, u):
    total = 0.0
    for i in range(len(x)):
        if u[i] == 'JPY':
            total += x[i]
        else:
            total += x[i] * 380000
    return total

def main():
    # Read the number of currency entries
    N = int(input())
    
    # Initialize lists to hold the amounts and their corresponding currency units
    x = []
    u = []
    
    # Loop to read each amount and its currency unit
    for _ in range(N):
        line = input().split()
        x.append(float(line[0]))  # Read the amount
        u.append(line[1])  # Read the currency unit
    
    # Calculate the total value in a standard currency and print the result
    print(solve(x, u))

if __name__ == "__main__":
    main()
