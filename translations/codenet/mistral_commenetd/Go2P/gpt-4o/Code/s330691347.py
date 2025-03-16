import sys

# Function to read an integer from the input
def next_int():
    return int(sys.stdin.readline().strip())

# Function to read a string from the input
def next_string():
    return sys.stdin.readline().strip()

# Define a class Data to represent a single data point
class Data:
    def __init__(self, x):
        self.x = x

# Main function starts here
def main():
    # Read number of data points N from the input
    N = next_int()

    # Read number of queries L from the input
    L = next_int()

    # Initialize a list of Data objects
    s = []

    # Read data points X from the input and store them in the list s
    for _ in range(N):
        s.append(Data(next_string()))

    # Print the number of data points N, number of queries L, and the list s
    print(N, L, [data.x for data in s])  # This line mimics the out function

    # Sort the list s in ascending order based on x field
    s.sort(key=lambda data: data.x)

    # Initialize an empty string ans to store the concatenated x values
    ans = ""

    # Iterate through the list s and concatenate x values to the string ans
    for data in s:
        ans += data.x

    # Print the concatenated string ans to the console
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
