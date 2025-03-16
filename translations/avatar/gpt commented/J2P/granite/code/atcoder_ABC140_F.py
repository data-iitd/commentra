
import sys

def main():
    # Read the integer N which determines the size of the input array
    N = int(input())
    
    # Calculate the size of the array as 2^N
    size = 1 << N
    
    # Initialize an array S to hold the input values
    S = [int(x) for x in input().split()]
    
    # Initialize a boolean array to track which elements have been spawned
    spawned = [False] * size
    
    # Mark the last element as spawned (the largest element)
    spawned[-1] = True
    
    # Sort the array S in ascending order
    S.sort()
    
    # Create a list to keep track of active slimes
    active = [S[-1]]
    
    # Mark the largest element as spawned
    spawned[-1] = True
    
    # Iterate N times to activate new slimes
    for i in range(N):
        # Sort the active list in descending order
        active.sort(reverse=True)
        
        # Create a list to keep track of newly activated slimes
        activated = []
        
        # Initialize the next index to the last element of S
        next = size - 1
        
        # Iterate through each slime in the active list
        for slime in active:
            # Find the next unspawned element that is less than the current slime
            while next >= 0 and (S[next] >= slime or spawned[next]):
                next -= 1
            
            # If no valid unspawned element is found, print "No" and exit
            if next < 0:
                print("No")
                sys.exit(0)
            
            # Mark the found element as spawned
            spawned[next] = True
            
            # Add the newly activated slime to the activated list
            activated.append(S[next])
        
        # Add all newly activated slimes to the active list
        active.extend(activated)
    
    # If all iterations complete successfully, print "Yes"
    print("Yes")

if __name__ == "__main__":
    main()

