# Define the main function
def main_function():
    # Read the number of test cases
    n = int(input())

    # Read the array of integers
    a = [int(i) for i in input().split()]

    # Initialize variables
    current_level = 0
    counter = 0
    counter_turns = -1

    # Main loop
    while counter < len(a):
        # Increment turns counter
        counter_turns += 1

        # Iterate through the array
        for i in range(len(a)):
            # If current index is valid and its value is less than or equal to current level
            if a[i] != -1 and a[i] <= counter:
                # Increment counter and mark the index as visited
                counter += 1
                a[i] = -1

        # Reverse the array
        a.reverse()

    # Print the result
    print(counter_turns)

# Call the main function
main_function()
