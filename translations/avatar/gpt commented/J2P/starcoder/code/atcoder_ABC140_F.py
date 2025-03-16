import sys

def main():
    # Read the number of elements in the array
    N = int(sys.stdin.readline())
    
    # Initialize an array to hold the input values
    S = []
    
    # Read N elements into the array
    for i in range(N):
        S.append(int(sys.stdin.readline()))
    
    # Sort the array in ascending order
    S.sort()
    
    # Initialize a list to keep track of active slimes
    active = []
    
    # Add the largest element to the active list
    active.append(S[-1])
    
    # Mark the largest element as spawned
    spawned = [False] * len(S)
    spawned[-1] = True
    
    # Iterate N times to activate new slimes
    for i in range(N):
        # Sort the active list in descending order
        active.sort(reverse=True)
        
        # Initialize a list to keep track of newly activated slimes
        activated = []
        
        # Initialize the next index to the last element of S
        next = len(S) - 1
        
        # Iterate through each slime in the active list
        for slime in active:
            # Find the next unspawned element that is less than the current slime
            while next >= 0 and (S[next] >= slime or spawned[next]):
                next -= 1
            
            # If no valid unspawned element is found, print "No" and exit
            if next < 0:
                print("No")
                return
            
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

