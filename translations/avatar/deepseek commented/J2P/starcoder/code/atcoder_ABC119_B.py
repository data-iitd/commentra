import sys; # Import the sys module to read input from the user

def solve(x, u):
    return sum(x[i] * (1 if u[i] == "JPY" else 380000) for i in range(len(x)))

if __name__ == "__main__":
    N = int(sys.stdin.readline()) # Read the number of elements N from the user
    x = [0] * N # Initialize the array to store the values
    u = [""] * N # Initialize the array to store the currencies

    # Read the values into the arrays x and u
    for i in range(N):
        x[i], u[i] = map(float, sys.stdin.readline().split())

    # Call the solve method and print the result
    print(solve(x, u))

