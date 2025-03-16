
# Import the required libraries
import sys

# Main function is the entry point of our program
def main():
    # Declare variables and initialize them
    n = int(input())

    # Create a list of work structures with length "n"
    ws = [None] * n

    # Read input data for each work structure and store it in the corresponding index of the "ws" list
    for i in range(n):
        a, n = map(int, input().split())
        ws[i] = (a, n)

    # Sort the "ws" list based on the "n" field of each work structure
    ws.sort(key=lambda x: x[1])

    # Initialize a variable named "sum" of type int64 and set its value to 0
    sum = 0

    # Iterate through the sorted "ws" list and check if the total time spent on all works exceeds any work's limit
    for w in ws:
        # Add the time of the current work structure to the "sum" variable
        sum += w[0]

        # Check if the sum is greater than the limit of the current work structure
        if sum > w[1]:
            # If it is, print "No" and return from the function
            print("No")
            return

    # If the loop completes without finding a work structure whose time exceeds its limit, print "Yes"
    print("Yes")


# Main function is the entry point of our program
if __name__ == "__main__":
    main()

