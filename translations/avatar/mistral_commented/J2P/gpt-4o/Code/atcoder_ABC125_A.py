# Import the sys module to read input from standard input
import sys

def main():
    # Read three integers from the standard input: the number of seconds, the number of periods, and the total number of seconds
    sec = int(input())  # Read the number of seconds
    per_num = int(input())  # Read the number of periods
    max_sec = int(input()) + 0.5  # Read the total number of seconds and add 0.5

    # Initialize a counter variable ans_num to zero
    ans_num = 0

    # Start a for loop that runs from the initial value sec to the final value max_sec with a step size of sec
    for i in range(sec, int(max_sec), sec):
        ans_num += per_num

    # Print the result ans_num to the standard output stream
    print(ans_num)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
