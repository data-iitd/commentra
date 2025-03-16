import sys

def main():
    # Read the first line of input and split it into an array
    input_line = input().split()
    
    # Parse the number of movements (m), start position (s), and final position (f)
    m = int(input_line[1])
    s = int(input_line[2])
    f = int(input_line[3])
    
    # Initialize maxT to keep track of the maximum time step
    maxT = -1
    
    # Create a dictionary to store the movements at each time step
    map = {}
    
    # Read the movements for each time step
    while m > 0:
        # Read the movement data for the current time step
        mth = input().split()
        k = int(mth[0])
        
        # Initialize the list for the current time step and add the movement range
        map[k] = [int(mth[1]), int(mth[2])]
        
        # Update maxT to the highest time step encountered
        maxT = max(maxT, k)
        m -= 1
    
    # Prepare a string to store the actions taken
    actions = []
    
    # Determine the direction of movement based on start and final positions
    M = 'R' if s < f else 'L'
    d = 1 if s < f else -1
    
    # Initialize current position to start position
    cur = s
    
    # Iterate through each time step from 1 to maxT
    for t in range(1, maxT + 1):
        # Check if there are movements defined for the current time step
        if t in map:
            a, b = map[t]
        else:
            a, b = None, None
        
        # Check if the current position or the next position is within the movement range
        if (map.get(t) is not None and (cur >= a and cur <= b) or (cur + d >= a and cur + d <= b)):
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
