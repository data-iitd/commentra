import sys
from collections import defaultdict

def main():
    # Read the first line of input and split it into an array
    input_line = sys.stdin.readline().strip().split()
    m = int(input_line[0])  # Read the number of methods
    s = int(input_line[2])  # Read the start position
    f = int(input_line[3])  # Read the finish position
    maxT = -1  # Initialize maximum thread ID

    # Create a dictionary to store thread IDs and their arrival and departure times
    map = defaultdict(list)

    # Read the remaining lines of input and store the thread IDs and their arrival and departure times in the dictionary
    for _ in range(m):
        mth = sys.stdin.readline().strip().split()
        k = int(mth[0])  # Read the thread ID
        map[k].append(int(mth[1]))  # Add the arrival time to the list
        map[k].append(int(mth[2]))  # Add the departure time to the list
        maxT = max(maxT, k)  # Update the maximum thread ID

    actions = []  # Initialize a list to store the output
    d = 1 if s < f else -1  # Determine the direction of the simulation
    cur = s  # Initialize the current position

    # Simulate the execution of threads and generate the output
    for t in range(1, maxT + 1):
        if t in map:
            a, b = map[t]
            if (cur >= a and cur <= b) or (cur + d >= a and cur + d <= b):
                actions.append('X')
            else:
                actions.append('R' if d == 1 else 'L')
                cur += d
            if cur == f:
                break
        else:
            actions.append('R' if d == 1 else 'L')
            cur += d

    # Print the output to the console
    while cur != f:
        actions.append('R' if d == 1 else 'L')
        cur += d
    print(''.join(actions))

if __name__ == "__main__":
    main()

