
# Python3 program to count the number of 
# rotations needed to reach 360 degrees 
# using a given number of steps 
import math 
  
# Function to count the number of rotations 
# needed to reach 360 degrees 
def countRotations(steps): 
  
    # Find the number of rotations 
    # needed to reach 360 degrees 
    rotations = steps // 360; 
  
    # Find the number of steps left 
    # after rotations 
    steps = steps % 360; 
  
    # If steps is less than 180, then 
    # no further rotations are needed 
    if (steps < 180): 
        return rotations; 
  
    # If steps is greater than 180, then 
    # further rotations are needed 
    rotations = rotations + 1; 
  
    # If steps is greater than 360, then 
    # further rotations are needed 
    if (steps > 360): 
        rotations = rotations + 1; 
  
    return rotations; 
  
# Driver Code 
if __name__ == '__main__': 
    steps = 1000; 
    print("Number of rotations needed to reach 360 degrees is", 
          countRotations(steps)); 
  
# This code is contributed by <NAME> 

