import sys

# Function to read the next integer from the input
def get_next_int():
    return int(sys.stdin.readline().strip())

# Main function
def main():
    # Read the first integer from the input
    n = get_next_int()

    # Initialize a list 'aa' of size 'n+2'
    aa = [0] * (n + 2)
    # Initialize a variable 'sum' to store the sum of absolute differences between consecutive elements
    total_sum = 0

    # Iterate through the array 'aa' and calculate the sum of absolute differences between consecutive elements
    for i in range(n):
        aa[i + 1] = get_next_int()  # Read the next integer from the input
        total_sum += abs(aa[i + 1] - aa[i])  # Calculate the absolute difference and add to the sum

    # Calculate the absolute difference between the last two elements and add it to the sum
    total_sum += abs(aa[n + 1] - aa[n])

    # Iterate through the array 'aa' and print the answer for each subarray
    for i in range(1, n + 1):
        # Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
        ans = total_sum - abs(aa[i + 1] - aa[i]) - abs(aa[i] - aa[i - 1]) + abs(aa[i + 1] - aa[i - 1])
        print(ans)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
