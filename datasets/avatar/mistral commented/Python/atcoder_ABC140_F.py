# Import the sys module to read input from standard input
import sys

# Function to read an integer from standard input
def I():
    return int(sys.stdin.readline())

# Function to read a list of integers from standard input
def LI():
    return [int(x) for x in sys.stdin.readline().split()]

# Main function to solve the problem
def main():
    # Read the number of test cases
    N = I()

    # Read the list of integers and sort it in descending order
    S = sorted(LI(), reverse=True)

    # Initialize a list of flags to keep track of whether each integer has been included in the current subsequence or not
    flag = [True] * len(S)

    # Initialize an empty list to store the current subsequence
    cur = []

    # Start from the first integer and include it in the subsequence
    cur.append(S[0])
    flag[0] = False

    # For each integer in the sorted list
    for i in range(N):
        # Initialize variables
        j = 0
        jM = len(cur)

        # Try to include the current integer in the subsequence
        for k in range(len(S)):
            # If the flag of the current integer is True and it is smaller than the last integer in the subsequence
            if flag[k] and S[k] < cur[j]:
                # Include the current integer in the subsequence and update the flag and the index of the last integer in the subsequence
                cur.append(S[k])
                j += 1
                flag[k] = False
                # If the length of the subsequence hasn't changed, break the loop
                if j == jM:
                    break

        # If we couldn't include any integer in the subsequence after the current one, return "No"
        else:
            return "No"

        # Sort the subsequence in descending order
        cur.sort(reverse=True)

    # If we could include all the integers in the subsequence, return "Yes"
    return "Yes"

# Run the main function if the script is executed directly
if __name__ == "__main__":
    # Read the output and print it
    print(main())
