def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read the integer N which determines the size of the input array
    N = int(data[0])
    
    # Calculate the size of the array as 2^N
    size = 1 << N
    
    # Initialize an array S to hold the input values
    S = list(map(int, data[1:size + 1]))
    
    # Initialize a boolean array to track which elements have been spawned
    spawned = [False] * size
    
    # Mark the last element as spawned (the largest element)
    spawned[size - 1] = True
    
    # Sort the array S in ascending order
    S.sort()
    
    # Create a list to keep track of active slimes
    active = []
    
    # Add the largest element to the active list
    active.append(S[size - 1])
    
    # Iterate N times to activate new slimes
    for _ in range(N):
        # Sort the active list in descending order
        active.sort(reverse=True)
        
        # Create a list to keep track of newly activated slimes
        activated = []
        
        # Initialize the next index to the last element of S
        next_index = size - 1
        
        # Iterate through each slime in the active list
        for slime in active:
            # Find the next unspawned element that is less than the current slime
            while next_index >= 0 and (S[next_index] >= slime or spawned[next_index]):
                next_index -= 1
            
            # If no valid unspawned element is found, print "No" and exit
            if next_index < 0:
                print("No")
                return
            
            # Mark the found element as spawned
            spawned[next_index] = True
            
            # Add the newly activated slime to the activated list
            activated.append(S[next_index])
        
        # Add all newly activated slimes to the active list
        active.extend(activated)
    
    # If all iterations complete successfully, print "Yes"
    print("Yes")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
