import sys
from collections import defaultdict

def main():
    # Read the input and split it into an array of strings
    input_data = sys.stdin.read().splitlines()
    input_values = input_data[0].split()
    
    # Parse the required integers from the input
    m = int(input_values[1])
    s = int(input_values[2])
    f = int(input_values[3])
    
    # Initialize the maximum time and a dictionary to store the intervals
    max_t = -1
    intervals = defaultdict(list)
    
    # Read the intervals from the input and store them in the dictionary
    for i in range(1, m + 1):
        k, a, b = map(int, input_data[i].split())
        intervals[k].append(a)
        intervals[k].append(b)
        max_t = max(max_t, k)
    
    # Initialize a list to build the sequence of actions
    actions = []
    
    # Determine the direction of movement and initialize the current position
    M = 'R' if s < f else 'L'
    d = 1 if s < f else -1
    cur = s
    
    # Variables to store the current interval's start and end
    a = -1
    b = -1
    
    # Build the sequence of actions based on the intervals and the current position
    for t in range(1, max_t + 1):
        if t in intervals:
            a = intervals[t][0]
            b = intervals[t][1]
        
        if t in intervals and ((cur >= a and cur <= b) or (cur + d >= a and cur + d <= b)):
            actions.append('X')
        else:
            actions.append(M)
            cur += d
        
        if cur == f:
            break
    
    # Continue moving in the determined direction until reaching the final position
    while cur != f:
        actions.append(M)
        cur += d
    
    # Print the sequence of actions
    print(''.join(actions))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
