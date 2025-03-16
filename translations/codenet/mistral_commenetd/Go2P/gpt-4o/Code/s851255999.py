# Import necessary modules
import sys

# Define a class named "Work" with two attributes: "time" and "limit"
class Work:
    def __init__(self, time, limit):
        self.time = time
        self.limit = limit

# Main function is the entry point of our program
def main():
    # Read the number of work structures
    n = int(sys.stdin.readline().strip())

    # Create a list of Work objects
    works = []

    # Read input data for each work structure and store it in the list
    for _ in range(n):
        a, limit = map(int, sys.stdin.readline().strip().split())
        works.append(Work(a, limit))

    # Sort the works list based on the "limit" attribute of each Work object
    works.sort(key=lambda w: w.limit)

    # Initialize a variable named "sum" and set its value to 0
    total_time = 0

    # Iterate through the sorted works list and check if the total time exceeds any work's limit
    for work in works:
        # Add the time of the current work structure to the total_time variable
        total_time += work.time

        # Check if the total_time is greater than the limit of the current work structure
        if total_time > work.limit:
            # If it is, print "No" and return from the function
            print("No")
            return

    # If the loop completes without finding a work structure whose time exceeds its limit, print "Yes"
    print("Yes")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
