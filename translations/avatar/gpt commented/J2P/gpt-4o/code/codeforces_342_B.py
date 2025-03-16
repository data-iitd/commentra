import sys
from collections import defaultdict

def main():
    # Read the first line of input and split it into an array
    input_data = sys.stdin.readline().strip().split()
    
    # Parse the number of movements (m), start position (s), and final position (f)
    m = int(input_data[1])
    s = int(input_data[2])
    f = int(input_data[3])
    
    # Initialize maxT to keep track of the maximum time step
    maxT = -1
    
    # Create a dictionary to store the movements at each time step
    movements = defaultdict(list)
    
    # Read the movements for each time step
    for _ in range(m):
        mth = list(map(int, sys.stdin.readline().strip().split()))
        k = mth[0]
        
        # Add the movement range to the dictionary
        movements[k].append((mth[1], mth[2]))
        
        # Update maxT to the highest time step encountered
        maxT = max(maxT, k)
    
    # Prepare a list to store the actions taken
    actions = []
    
    # Determine the direction of movement based on start and final positions
    M = 'R' if s < f else 'L'
    d = 1 if s < f else -1
    
    # Initialize current position to start position
    cur = s
    a, b = -1, -1
    
    # Iterate through each time step from 1 to maxT
    for t in range(1, maxT + 1):
        if t in movements:
            a, b = movements[t][0]  # Get the first movement range
        
        # Check if the current position or the next position is within the movement range
        if t in movements and ((a <= cur <= b) or (a <= cur + d <= b)):
            actions.append('X')  # Append 'X' if within the range
        else:
            actions.append(M)  # Append the movement direction
            cur += d  # Update the current position
        
        # Break the loop if the current position reaches the final position
        if cur == f:
            break
    
    # Continue moving until the current position reaches the final position
    while cur != f:
        actions.append(M)  # Append the movement direction
        cur += d  # Update the current position
    
    # Output the sequence of actions taken
    print(''.join(actions))

if __name__ == "__main__":
    main()
# <END-OF-CODE>
