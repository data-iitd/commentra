
import sys # Import sys for input operations

def main():
    N = int(input()) # Read the number of elements N from the user
    x = [float(input()) for _ in range(N)] # Read the values into the list x
    u = [input() for _ in range(N)] # Read the currencies into the list u

    # Call the solve method and print the result
    print(solve(x, u))

# Define the solve method to calculate the total value based on the currency
def solve(x, u):
    return sum(x[i] * (1 if u[i] == "JPY" else 380000) for i in range(len(x)))

if __name__ == "__main__":
    main()

