# Constants declaration with initializing size of the memory list
size = 100001

# Function definition for main function
def main():
    # Variable declaration and initialization for number of queries and time interval
    n, t = map(int, input().split())

    # Initializing memory list with zero values
    mem = [0] * size

    # Iterating through each query in the input
    for _ in range(n):
        # Reading input values for start and end time intervals
        l, r = map(int, input().split())

        # Updating memory list values for start and end time intervals
        mem[l] += 1
        mem[r] -= 1

    # Initializing variable for answer
    ans = mem[0]

    # Iterating through each time interval in the memory list
    for i in range(1, t + 1):
        # Updating memory list values by adding previous value
        mem[i] += mem[i - 1]

        # Updating answer if current memory list value is greater than previous answer
        if ans < mem[i]:
            ans = mem[i]

    # Printing the final answer
    print(ans)

# Calling the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
