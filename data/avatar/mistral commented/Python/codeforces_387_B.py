# Function to perform the main logic of the program
def main():

    # Initialize variables n and m with the given input
    n, m = [int(i) for i in input().split()]

    # Initialize lists round_complexity and george_complexity
    # with the given input
    round_complexity = [int(i) for i in input().split()]
    george_complexity = [int(i) for i in input().split()]

    # Initialize variables i and j to 0
    i = j = 0

    # Start the while loop that compares the complexity of each
    # round with George's complexity and moves the pointers accordingly
    while i < n and j < m:

        # Increment i if the complexity of the current round is
        # less than or equal to George's complexity at the current j
        i += 1 if round_complexity[i] <= george_complexity[j] else 0

        # Increment j
        j += 1

    # Print the final answer
    print(n - i)

# Run the main function if the script is executed directly
if __name__ == '__main__':
    main()
