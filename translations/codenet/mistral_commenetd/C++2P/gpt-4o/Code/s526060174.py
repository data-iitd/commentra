# Define a function to read input and process the data
def main():
    n, m = map(int, input().split())  # Read input values for n and m
    x = [0] * 31  # Initialize a list x of size 31 with zeros

    # Process each input value for n times
    for _ in range(n):
        k = int(input())  # Read the number of elements in the current input

        # Process each element in the current input
        for _ in range(k):
            a = int(input())  # Read the value of the current element
            x[a] += 1  # Increment the count of the current value in the list x

    # Initialize answer variable to zero
    ans = 0

    # Check each value from 1 to m and increment the answer if the count is equal to n
    for i in range(1, m + 1):
        if x[i] == n:  # Check if the count of the current value is equal to n
            ans += 1  # Increment the answer if true

    # Output the final answer
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
