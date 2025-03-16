import sys

def main():
    input_data = sys.stdin.read().strip().splitlines()  # Read all input at once
    first_line = input_data[0].split()  # Split the first line of input
    m = int(first_line[0])  # Read the number of methods
    s = int(first_line[2])  # Read the start position
    f = int(first_line[3])  # Read the finish position
    max_t = -1  # Initialize maximum thread ID

    thread_map = {}  # Create a dictionary to store thread IDs and their arrival and departure times

    # Read the remaining lines of input and store the thread IDs and their arrival and departure times in the dictionary
    for i in range(1, m + 1):
        mth = input_data[i].split()  # Read a line of input and split it into an array
        k = int(mth[0])  # Read the thread ID
        thread_map[k] = [int(mth[1]), int(mth[2])]  # Store arrival and departure times
        max_t = max(max_t, k)  # Update the maximum thread ID

    actions = []  # Initialize a list to store the output
    M = 'R' if s < f else 'L'  # Determine the direction of the simulation based on the start and finish positions
    d = 1 if s < f else -1  # Determine the direction of the simulation as 1 for right and -1 for left
    cur = s  # Initialize the current position
    a = -1  # Initialize variables for storing the arrival and departure times of the current thread
    b = -1

    # Simulate the execution of threads and generate the output
    for t in range(1, max_t + 1):
        if t in thread_map:  # Check if there is a thread with the given ID
            a, b = thread_map[t]  # Get the arrival and departure time of the thread

            if (cur >= a and cur <= b) or (cur + d >= a and cur + d <= b):  # Check if the current position is within the execution time of the thread
                actions.append('X')  # Append an 'X' to the output if the current position is within the execution time of the thread
            else:
                actions.append(M)  # Append the direction character to the output if the current position is not within the execution time of the thread
                cur += d  # Move the current position in the direction of the simulation

            if cur == f:  # Break the loop if the finish position is reached
                break
        else:
            actions.append(M)  # Append the direction character to the output if there is no thread at the current position
            cur += d  # Move the current position in the direction of the simulation

    # Print the output to the console
    while cur != f:
        actions.append(M)
        cur += d

    print(''.join(actions))  # Print the output as a single string

if __name__ == "__main__":
    main()

# <END-OF-CODE>
