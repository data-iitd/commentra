# Define a constant for the value of PI
PI = 3.14159265358979

# Define a type alias for long long (not needed in Python, but for clarity)
ll = int

# Function to simplify loop creation (not needed in Python, using range instead)

# ---------------------------------------------

def main():
    # Declare variables to hold the number of groups
    n, m = map(int, input().split())

    # Initialize the answer variable to store the total pairs
    ans = 0

    # Calculate the number of pairs within group n
    # The formula n*(n-1)/2 gives the number of ways to choose 2 from n
    ans += n * (n - 1) // 2

    # Calculate the number of pairs within group m
    # Similarly, m*(m-1)/2 gives the number of ways to choose 2 from m
    ans += m * (m - 1) // 2

    # Output the total number of pairs
    print(ans)

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
