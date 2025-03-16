# Entry point of the program
def main():
    # Read the number of work items
    n = int(input())

    # Initialize a list to hold the work items
    ws = []

    # Read each work item's time and limit
    for _ in range(n):
        a, limit = map(int, input().split())
        ws.append((a, limit))  # Store the work item in the list

    # Sort the work items based on their limits
    ws.sort(key=lambda x: x[1])

    # Initialize a variable to keep track of the cumulative time
    cumulative_time = 0

    # Check if the cumulative time exceeds the limit for any work item
    for time, limit in ws:
        cumulative_time += time  # Add the current work item's time to the sum
        if cumulative_time > limit:
            print("No")  # If the sum exceeds the limit, print "No"
            return

    # If all work items are within their limits, print "Yes"
    print("Yes")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
